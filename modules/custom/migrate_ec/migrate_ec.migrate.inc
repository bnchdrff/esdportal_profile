<?php

/**
 * @file migrate_ec.migrate.inc
 * Imports early childhood taxonomy terms from Great Start export.
 */

/**
 * Implements hook_migrate_api().
 */
function migrate_ec_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'terms' => array(
        'title' => t('Terms'),
        'disable_hooks' => array(
          'field_attach_presave' => array(
            'geocoder',
          ),
        ),
      ),
      'nodes' => array(
        'title' => t('Nodes'),
      ),
    ),
    'migrations' => array(
      'ESD_ec_profiles_2015' => array(
        'class_name' => 'ESD_ec_profiles_2015',
        'group_name' => 'nodes',
      ),
      'GS_ec_terms' => array(
        'class_name' => 'GS_ec_terms',
        'group_name' => 'terms',
      ),
      'GS_ec_profiles' => array(
        'class_name' => 'GS_ec_profiles',
        'group_name' => 'nodes',
      ),
      'ESD_oldearlychild_ec_profiles' => array(
        'class_name' => 'ESD_oldearlychild_ec_profiles',
        'group_name' => 'nodes',
      ),
    ),
  );
  return $api;
}

class Migrate_EC_Helpers {
  /**
   * given string 'a, b, , c, d'
   * return array('a', 'b', 'c', 'd')
   */
  public static function csvToArray($csv) {
    $ret = array();
    $potential_values = preg_split("/[\s]*[,][\s]*/", $csv);
    foreach ($potential_values as $val) {
      if (strlen($val) > 1) {
        $ret[] = $val;
      }
    }
    return $ret;
  }
}

/**
 * Based on ESD's 2015 early chlidhood center scorecard data,
 * creates ec_profile nodes.
 *
 * Only sets two fields: the title & the ec term reference field.
 *
 * The same dataset will later be used to populate 2015 test results in a data table.
 */
class ESD_ec_profiles_2015 extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Creates early childhood center profiles (nodes) from ESD 2015 scores.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'program_id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'State of Michigan license number, minus letters',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceCSV('/tmp/migrate_ec/esd-ec-2015.csv', array(), array('header_rows'=>1, 'embedded_newlines'=>FALSE));

    $this->destination = new MigrateDestinationNode('ec_profile');

    $this->addFieldMapping('title', 'program_name');
    $this->addFieldMapping(NULL, 'program_id');
    $this->addFieldMapping('field_ec', 'prepared_schoolid');
    $this->addFieldMapping('field_ec:source_type')->defaultValue('tid');
  }

  public function prepareRow($row) {
    $row->prepared_schoolid = db_query("SELECT entity_id FROM {field_data_field_esd_ec_id} WHERE field_esd_ec_id_value = :esd_ec_id", array(":esd_ec_id" => (int) $row->program_id))->fetchField();
  }
}

/**
 * Based on Great Start exported data,
 * creates taxonomy terms for all Michigan early childhood centers.
 */
class GS_ec_terms extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import early childhood center base records (taxonomy terms) from Great Start export.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'State of Michigan license number, minus letters',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    //$query = db_select('earlychild', 'ec')
    //           ->fields('ec');
    //$this->source = new MigrateSourceSQL($query);
    $this->source = new MigrateSourceCSV('/tmp/migrate_ec/esd-ec-gsexport.csv', array(), array('header_rows'=>1, 'embedded_newlines'=>FALSE));

    $this->destination = new MigrateDestinationTerm('ec');

    $this->addFieldMapping('name', 'Business Name');
    $this->addFieldMapping('field_address')->defaultValue('US');
    $this->addFieldMapping('field_address:name_line', 'Business Name');
    $this->addFieldMapping('field_address:locality', 'City');
    $this->addFieldMapping('field_address:administrative_area', 'State');
    $this->addFieldMapping('field_address:phone_number', 'Phone');
    $this->addFieldMapping('field_address:postal_code', 'Zip Code');
    $this->addFieldMapping('field_address:thoroughfare', 'Address');
    $this->addFieldMapping(NULL, 'Accepts Ages From');
    $this->addFieldMapping('field_age_from', 'AgeFromMonthified');
    $this->addFieldMapping(NULL, 'Accepts Ages To');
    $this->addFieldMapping('field_age_to', 'AgeToMonthified');
    $this->addFieldMapping('field_ec_license_type', 'License Type');
    $this->addFieldMapping('field_ec_license_type:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_license_type:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_esd_ec_id', 'id');
    $this->addFieldMapping('field_licensed_date', 'Licensed/registered date');
    //$this->addFieldMapping('field_months_of_operation MonthsOfOperation
    $this->addFieldMapping('field_state_license_id', 'License Number');
  }

  public function prepareRow($row) {
    $age_from_matches = array();
    $age_to_matches = array();
    preg_match('/(\d*) years (\d*) months/', $row->{'Accepts Ages From'}, $age_from_matches);
    $row->AgeFromMonthified = (int) $age_from_matches[1] * 12 + (int) $age_from_matches[2];
    preg_match('/(\d*) years (\d*) months/', $row->{'Accepts Ages To'}, $age_to_matches);
    $row->AgeToMonthified = (int) $age_to_matches[1] * 12 + (int) $age_to_matches[2];
  }
}

/**
 * Updates ec_profile nodes with information found in the GS export.
 */
class GS_ec_profiles extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->systemOfRecord = Migration::DESTINATION;

    $this->description = t('Updates early childhood center profiles (nodes) from Great Start export.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'State of Michigan license number, minus letters',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceCSV('/tmp/migrate_ec/esd-ec-gsexport.csv', array(), array('header_rows'=>1, 'embedded_newlines'=>FALSE));

    $this->destination = new MigrateDestinationNode('ec_profile');

    $this->addFieldMapping(NULL, 'id');
    $this->addFieldMapping('nid', 'nid');
    //$this->addFieldMapping('field_gsc_provider_id GSCProviderID
    //$this->addFieldMapping('field_months_of_operation MonthsOfOperation
    $this->addFieldMapping(NULL, 'Preschool');
    $this->addFieldMapping(NULL, 'Head Start');
    $this->addFieldMapping(NULL, 'Early Head Start');
    $this->addFieldMapping(NULL, 'Great Start Readiness Program');
    $this->addFieldMapping(NULL, 'School Age ONLY');
    $this->addFieldMapping(NULL, 'Montessori');
    $this->addFieldMapping(NULL, 'Reggio Inspired');
    $this->addFieldMapping(NULL, 'Faith-based');
    $this->addFieldMapping('field_ec_specialty', 'collated_specialties');
    $this->addFieldMapping('field_ec_specialty:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_specialty:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_website', 'Website');
    $this->addFieldMapping('field_capacity', 'Capacity');

  }

  public function prepareRow($row) {
    // only try to update centers that are part of the ESD universe

    $ec_tid = db_query("SELECT entity_id FROM {field_data_field_esd_ec_id} WHERE field_esd_ec_id_value = :esd_ec_id", array(":esd_ec_id" => (int) $row->id))->fetchField();

    if ($ec_tid < 1) {
      return false;
    }

    $ec_profile_id = db_query("SELECT entity_id FROM {field_data_field_ec} WHERE field_ec_tid = :ec_tid AND entity_type='node' AND bundle='ec_profile'", array(':ec_tid' => (int) $ec_tid))->fetchField();

    if ($ec_profile_id < 1) {
      return false;
    }

    $row->nid = $ec_profile_id;

    $specialties = array();

    $potential_specialties = array(
      'Preschool' => $row->{'Preschool'},
      'Head Start' => $row->{'Head Start'},
      'Early Head Start' => $row->{'Early Head Start'},
      'Great Start Readiness Program' => $row->{'Great Start Readiness Program'},
      'School Age ONLY' => $row->{'School Age ONLY'},
      'Montessori' => $row->{'Montessori'},
      'Reggio Inspired' => $row->{'Reggio Inspired'},
      'Faith-based' => $row->{'Faith-based'},
    );

    foreach ($potential_specialties as $key => $value) {
      if ($value === 'Yes') {
        $specialties[] = $key;
      }
    }

    $row->collated_specialties = $specialties;
  }
}

/**
 * @todo
 * Updates ec_profiles with info from old earlychild table.
 */
class ESD_oldearlychild_ec_profiles extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->systemOfRecord = Migration::DESTINATION;

    $this->description = t('Updates early childhood center profiles (nodes) from old earlychild data.');

    $q = db_select('field_data_field_esd_ec_id', 'f_d_f_esd_ec_id');
    $q->innerJoin('field_data_field_ec', 'f_d_f_ec', 'f_d_f_ec.field_ec_tid=f_d_f_esd_ec_id.entity_id');
    $q->innerJoin('earlychild', 'ec', 'ec.id=f_d_f_esd_ec_id.field_esd_ec_id_value');
    /// @todo join term to related node!
    $q->fields('f_d_f_ec', array('entity_id'))
      ->fields('ec', array(
        'SundayDayOpen',
        'SundayDayClose',
        'MondayDayOpen',
        'MondayDayClose',
        'TuesdayDayOpen',
        'TuesdayDayClose',
        'WednesdayDayOpen',
        'WednesdayDayClose',
        'ThursdayDayOpen',
        'ThursdayDayClose',
        'FridayDayOpen',
        'FridayDayClose',
        'SaturdayDayOpen',
        'SaturdayDayClose',
        'Transportation',
        'Environment',
        'Meals',
        'GSCeligibility',
        'GSCspecial',
        'GSCsubsidy',
        'GSCcapacity',
        'GSCcontract',
        'GSCfee',
        'GSCemail',
        'GSCcontact',
        'GSCmessage',
        'GSCspecialty',
        'GSCschedule',
      ));

    $this->source = new MigrateSourceSQL($q);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'entity_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ec_profile entity_id',
          'alias' => 'f_d_f_ec',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->destination = new MigrateDestinationNode('ec_profile');

    $this->addFieldMapping('nid', 'entity_id');
    $this->addFieldMapping('field_sunday_open', 'SundayDayOpen');
    $this->addFieldMapping('field_sunday_close', 'SundayDayClose');
    $this->addFieldMapping('field_monday_open', 'MondayDayOpen');
    $this->addFieldMapping('field_monday_close', 'MondayDayClose');
    $this->addFieldMapping('field_tuesday_open', 'TuesdayDayOpen');
    $this->addFieldMapping('field_tuesday_close', 'TuesdayDayClose');
    $this->addFieldMapping('field_wednesday_open', 'WednesdayDayOpen');
    $this->addFieldMapping('field_wednesday_close', 'WednesdayDayClose');
    $this->addFieldMapping('field_thursday_open', 'ThursdayDayOpen');
    $this->addFieldMapping('field_thursday_close', 'ThursdayDayClose');
    $this->addFieldMapping('field_friday_open', 'FridayDayOpen');
    $this->addFieldMapping('field_friday_close', 'FridayDayClose');
    $this->addFieldMapping('field_saturday_open', 'SaturdayDayOpen');
    $this->addFieldMapping('field_saturday_close', 'SaturdayDayClose');
    $this->addFieldMapping(NULL, 'Transportation');
    $this->addFieldMapping('field_ec_transportation', 'TransportationBoolified');
    $this->addFieldMapping(NULL, 'Environment');
    $this->addFieldMapping('field_ec_environment', 'EnvironmentTaxonomyManyified');
    $this->addFieldMapping('field_ec_environment:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_environment:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping(NULL, 'Meals');
    $this->addFieldMapping('field_ec_meals', 'MealsTaxonomyManyified');
    $this->addFieldMapping('field_ec_meals:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_meals:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping(NULL, 'GSCeligibility');
    $this->addFieldMapping('field_ec_eligibility', 'GSCeligibilityBoolified');
    $this->addFieldMapping(NULL, 'GSCspecial');
    $this->addFieldMapping('field_ec_special', 'GSCspecialTaxonomyManyified');
    $this->addFieldMapping('field_ec_special:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_special:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_subsidy', 'GSCsubsidy');
    $this->addFieldMapping('field_ec_subsidy:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_subsidy:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping(NULL, 'GSCcontract');
    $this->addFieldMapping('field_ec_contract', 'GSCcontractBoolified');
    $this->addFieldMapping(NULL, 'GSCfee');
    $this->addFieldMapping('field_ec_fee', 'GSCfeeFloatified');
    $this->addFieldMapping('field_email', 'GSCemail');
    $this->addFieldMapping('field_ec_contact', 'GSCcontact');
    $this->addFieldMapping('field_ec_message', 'GSCmessage');
    $this->addFieldMapping(NULL, 'GSCspecialty');
    $this->addFieldMapping('field_ec_specialty', 'GSCspecialtyTaxonomyManyfied');
    $this->addFieldMapping('field_ec_specialty:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_specialty:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_ec_schedule', 'GSCschedule');

  }

  public function prepareRow($row) {
    // bool the bools
    $row->TransportationBoolified = ($row->Transportation === "Yes") ? TRUE : FALSE;
    $row->GSCeligibility = ($row->GSCeligibility === "Yes") ? TRUE : FALSE;
    $row->GSCcontact = ($row->GSCcontractBoolified === "Yes") ? TRUE : FALSE;

    // taxonomize the taxonomies
    $row->GSCspecialTaxonomyManyified = Migrate_EC_Helpers::csvToArray($row->GSCspecial);
    $row->GSCspecialtyTaxonomyManyified = Migrate_EC_Helpers::csvToArray($row->GSCspecialty);
    $row->EnvironmentTaxonomyManyified = Migrate_EC_Helpers::csvToArray($row->Environment);
    $row->MealsTaxonomyManyified = Migrate_EC_Helpers::csvToArray($row->Meals);

    // floatify the floats
    $row->GSCfeeFloatified = str_replace('$', '', $row->GSCfee);
  }
}
