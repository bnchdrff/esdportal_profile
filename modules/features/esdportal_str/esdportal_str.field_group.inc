<?php
/**
 * @file
 * esdportal_str.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function esdportal_str_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_2013|taxonomy_term|schools|form';
  $field_group->group_name = 'group_2013';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'schools';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2013 Fields',
    'weight' => '22',
    'children' => array(
      0 => 'field_loc_email',
      1 => 'field_2011_pct_det_res',
      2 => 'field_opted_in',
      3 => 'field_5e_roster',
      4 => 'field_2013_site_visit_date',
      5 => 'field_grdataletter',
      6 => 'field_grdatatype',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '2013 Fields',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-2013 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_2013|taxonomy_term|schools|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_2014|taxonomy_term|schools|form';
  $field_group->group_name = 'group_2014';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'schools';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2014 Fields',
    'weight' => '21',
    'children' => array(
      0 => 'field_2014_graded',
      1 => 'field_2014_profile',
      2 => 'field_2014_site_visit',
      3 => 'field_2014_site_visit_date',
      4 => 'field_2014_5essentials_roster',
      5 => 'field_2014_5essentials_teacher',
      6 => 'field_2014_5essentials_student',
      7 => 'field_2014_5essentials_parent',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '2014 Fields',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-2014 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_2014|taxonomy_term|schools|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_2015|taxonomy_term|schools|form';
  $field_group->group_name = 'group_2015';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'schools';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2015 Fields',
    'weight' => '20',
    'children' => array(
      0 => 'field_2015_universe',
      1 => 'field_2015_graded',
      2 => 'field_2015_5essentials_parent',
      3 => 'field_2015_5essentials_roster',
      4 => 'field_2015_5essentials_student',
      5 => 'field_2015_5essentials_teacher',
      6 => 'field_2015_zone',
      7 => 'field_2015_site_visit',
      8 => 'field_2015_sv_eligible',
      9 => 'field_2015_site_visit_date',
      10 => 'field_2015_site_visit_category',
      11 => 'field_2015_profile',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '2015 Fields',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-2015 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_2015|taxonomy_term|schools|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_2016|taxonomy_term|schools|form';
  $field_group->group_name = 'group_2016';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'schools';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2016 Fields',
    'weight' => '19',
    'children' => array(
      0 => 'field_2016_universe',
      1 => 'field_2016_verified',
      2 => 'field_2016_recommended',
      3 => 'field_ed_participant',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-2016 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_2016|taxonomy_term|schools|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_2017|taxonomy_term|schools|form';
  $field_group->group_name = 'group_2017';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'schools';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2017 Fields',
    'weight' => '54',
    'children' => array(
      0 => 'field_2017_universe',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-2017 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_2017|taxonomy_term|schools|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_academics_resources|node|school_profile|form';
  $field_group->group_name = 'group_academics_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'Academics & Resources',
    'weight' => '11',
    'children' => array(
      0 => 'field_academic_focus',
      1 => 'field_instructional_model',
      2 => 'field_staff_resources',
      3 => 'field_facilities',
      4 => 'field_schedule',
      5 => 'field_immersion',
      6 => 'field_extra_learning_resources',
      7 => 'field_parent_involvement',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-academics-resources field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_academics_resources|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accessibility|node|school_profile|form';
  $field_group->group_name = 'group_accessibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'Special Ed, Access, ELL',
    'weight' => '10',
    'children' => array(
      0 => 'field_transportation_options',
      1 => 'field_special_ed_level',
      2 => 'field_special_ed_programs',
      3 => 'field_ell_level',
      4 => 'field_ell_languages',
      5 => 'field_wheelchair_accessible',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Special Ed, Access, ELL',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-accessibility field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_accessibility|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_college_career|node|school_profile|form';
  $field_group->group_name = 'group_college_career';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'College & Career',
    'weight' => '15',
    'children' => array(
      0 => 'field_ap_classes',
      1 => 'field_dual_enrollment',
      2 => 'field_dual_enrollment_institutio',
      3 => 'field_college_prep',
      4 => 'field_skills_training',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-college-career field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_college_career|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_edit|node|school_profile|form';
  $field_group->group_name = 'group_current_edit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'Old Fields (Ignore)',
    'weight' => '54',
    'children' => array(
      0 => 'field_after_school_transportatio',
      1 => 'field_character_development',
      2 => 'field_college_counseling',
      3 => 'field_counselor_student_ratio',
      4 => 'field_discipline_programs',
      5 => 'field_early_child_center_relatio',
      6 => 'field_early_childhood_transition',
      7 => 'field_english_language_learners',
      8 => 'field_family_supports',
      9 => 'field_in_school_programs',
      10 => 'field_organized_sports',
      11 => 'field_parent_supports',
      12 => 'field_person_responsible',
      13 => 'field_special_needs',
      14 => 'field_special_tracks',
      15 => 'field_student_development_progra',
      16 => 'field_student_leadership_opportu',
      17 => 'field_transportation',
      18 => 'field_site_visit_status',
      19 => 'field_site_visit_available_dates',
      20 => 'field_site_visit_reuse_reason',
      21 => 'field_site_visit_unavailability',
      22 => 'field_growth_data_doc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Old Fields (Ignore)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_current_edit|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eem|taxonomy_term|schools|form';
  $field_group->group_name = 'group_eem';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'schools';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'EEM Fields',
    'weight' => '18',
    'children' => array(
      0 => 'field_state_status',
      1 => 'field_strict_discipline_academy',
      2 => 'field_special_ed_emphasis',
      3 => 'field_alternative_school',
      4 => 'field_career_technical_emphasis',
      5 => 'field_specialty_school',
      6 => 'field_governance',
      7 => 'field_authorized_grades',
      8 => 'field_district',
      9 => 'field_operator',
      10 => 'field_authorizer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'EEM Fields',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-eem field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_eem|taxonomy_term|schools|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrollment|node|school_profile|form';
  $field_group->group_name = 'group_enrollment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'Enrollment',
    'weight' => '13',
    'children' => array(
      0 => 'field_application_process',
      1 => 'field_admissions_url',
      2 => 'field_application_fee',
      3 => 'field_application_fee_amount',
      4 => 'field_applications_received',
      5 => 'field_students_accepted',
      6 => 'field_feeder_school',
      7 => 'field_destination_school',
      8 => 'field_application_open',
      9 => 'field_application_deadline',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrollment field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_enrollment|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_esd_internal|node|school_profile|form';
  $field_group->group_name = 'group_esd_internal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'ESD Internal',
    'weight' => '16',
    'children' => array(
      0 => 'field_school',
      1 => 'field_site_visit_status',
      2 => 'field_site_visit_available_dates',
      3 => 'field_site_visit_reuse_reason',
      4 => 'field_site_visit_unavailability',
      5 => 'field_growth_data_doc',
      6 => 'locations',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-esd-internal field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_esd_internal|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_extracurriculars|node|school_profile|form';
  $field_group->group_name = 'group_extracurriculars';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'Extracurriculars',
    'weight' => '14',
    'children' => array(
      0 => 'field_boys_sports',
      1 => 'field_girls_sports',
      2 => 'field_foreign_language',
      3 => 'field_student_clubs',
      4 => 'field_student_clubs_dance',
      5 => 'field_student_clubs_language',
      6 => 'field_student_clubs_other',
      7 => 'field_arts_media',
      8 => 'field_arts_music',
      9 => 'field_arts_performing_written',
      10 => 'field_arts_visual',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-extracurriculars field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_extracurriculars|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|school_profile|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => 'General Info',
    'weight' => '9',
    'children' => array(
      0 => 'field_early_childhood_programs',
      1 => 'field_email',
      2 => 'field_grades_served',
      3 => 'field_school_contact_first_name',
      4 => 'field_school_contact_last_name',
      5 => 'field_photos',
      6 => 'field_dress_code',
      7 => 'field_before_after_care',
      8 => 'field_bullying_policy',
      9 => 'field_facebook_url',
      10 => 'field_school_url',
      11 => 'field_general_contact_phone',
      12 => 'field_message',
      13 => 'field_shared_documents',
      14 => 'field_time_open',
      15 => 'field_time_closed',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'General Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_general|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_new_edit|node|school_profile|form';
  $field_group->group_name = 'group_new_edit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_new';
  $field_group->data = array(
    'label' => '*New - Edit 2014 School Profile',
    'weight' => '5',
    'children' => array(
      0 => 'field_ap_classes',
      1 => 'field_dual_enrollment',
      2 => 'field_dual_enrollment_institutio',
      3 => 'field_early_childhood_programs',
      4 => 'field_academic_focus',
      5 => 'field_instructional_model',
      6 => 'field_staff_resources',
      7 => 'field_boys_sports',
      8 => 'field_girls_sports',
      9 => 'field_ell_level',
      10 => 'field_ell_languages',
      11 => 'field_facilities',
      12 => 'field_dress_code',
      13 => 'field_schedule',
      14 => 'field_college_prep',
      15 => 'field_skills_training',
      16 => 'field_bullying_policy',
      17 => 'field_immersion',
      18 => 'field_extra_learning_resources',
      19 => 'field_foreign_language',
      20 => 'field_parent_involvement',
      21 => 'field_admissions_url',
      22 => 'field_application_fee',
      23 => 'field_application_fee_amount',
      24 => 'field_applications_received',
      25 => 'field_students_accepted',
      26 => 'field_student_clubs',
      27 => 'field_student_clubs_dance',
      28 => 'field_student_clubs_language',
      29 => 'field_student_clubs_other',
      30 => 'field_feeder_school',
      31 => 'field_destination_school',
      32 => 'field_arts_media',
      33 => 'field_arts_music',
      34 => 'field_arts_performing_written',
      35 => 'field_arts_visual',
      36 => 'field_message',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '*New - Edit 2014 School Profile',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_new_edit|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_new|node|school_profile|form';
  $field_group->group_name = 'group_new';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'school_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'School Profiles',
    'weight' => '8',
    'children' => array(
      0 => 'group_enrollment',
      1 => 'group_accessibility',
      2 => 'group_general',
      3 => 'group_college_career',
      4 => 'group_extracurriculars',
      5 => 'group_esd_internal',
      6 => 'group_academics_resources',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'School Profiles',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_new|node|school_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partnerships|node|ec_profile|form';
  $field_group->group_name = 'group_partnerships';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ec_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Partnerships',
    'weight' => '49',
    'children' => array(
      0 => 'field_ec_partner1',
      1 => 'field_ec_partner1_detail',
      2 => 'field_ec_partner2',
      3 => 'field_ec_partner2_detail',
      4 => 'field_ec_partner3',
      5 => 'field_ec_partner3_detail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Partnerships',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-partnerships field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_partnerships|node|ec_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scorecard|taxonomy_term|ec|form';
  $field_group->group_name = 'group_scorecard';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'ec';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scorecard Tracker',
    'weight' => '22',
    'children' => array(
      0 => 'field_scorecard_display',
      1 => 'field_ed_participant',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-scorecard field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_scorecard|taxonomy_term|ec|form'] = $field_group;

  return $export;
}
