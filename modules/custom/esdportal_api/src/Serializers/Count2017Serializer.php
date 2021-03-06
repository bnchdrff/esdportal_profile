<?php

/**
 * @file
 * Contains Drupal\esdportal_api\Serializers\Count2017Serializer.
 *
 * Serializes count_2017 records.
 */

namespace Drupal\esdportal_api\Serializers;

use Tobscure\JsonApi\SerializerAbstract;

/**
 * Serializes count_2017 data records.
 */
class Count2017Serializer extends SerializerAbstract {
  protected $type = 'count_2017s';

  /**
   * Nothing special here, yet.
   */
  protected function attributes($row) {
    return $row;
  }

  /**
   * Provides primary key as id.
   */
  protected function id($row) {
    return $row->BuildingCode;
  }

  /**
   * Backwards-compatible with bnchdrff/json-api version.
   */
  protected function getId($row) {
    return $row->BuildingCode;
  }

}
