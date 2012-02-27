<?php
class Company extends ActiveRecord\Model {

  static $validates_presence_of = array(
      array('user_id'), array('name'));
}
?>