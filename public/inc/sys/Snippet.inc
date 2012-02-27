<?php

class Snippet {
  
  private static $instances = array();

  /**
   * Static method for instantiating a singleton object.
   *
   * @return object
   */
  final public static function instance() {
    if (!isset(self::$instances['Snippet']))
      self::$instances['Snippet'] = new Snippet();

    return self::$instances['Snippet'];
  }

  final private function __clone() {
    
  }

  final protected function get_called_class() {
    $backtrace = debug_backtrace();
    return get_class($backtrace[2]['object']);
  }

  public function __construct() {
    
  }
  
  public function load($name){
    $res = Template::instance('template');
    $widget = $this;
    include SNIPPET_PATH.$name."/"."index.php";
  }
}
?>
