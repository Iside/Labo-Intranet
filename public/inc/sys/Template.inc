<?
class Template {

  private static $instances = array();

  /**
   * Static method for instantiating a singleton object.
   *
   * @return object
   */
  final public static function instance() {
    if (!isset(self::$instances['Template']))
      self::$instances['Template'] = new Template();

    return self::$instances['Template'];
  }

  final private function __clone() {
    
  }

  final protected function get_called_class() {
    $backtrace = debug_backtrace();
    return get_class($backtrace[2]['object']);
  }

  public function __construct() {
    
  }

  /*
   * Vous pouvez mettre nul ici pour ne pas décorer le template comma valeur à begin. La vue sera chargé si elle existe.
   */

  function useTemplate($title='Home', $layout=true, $alert="") {
    if ($layout) {
      $this->Begin($title, $alert);
    }
    $paths = explode('/', $_SERVER['SCRIPT_NAME']);
    foreach (get_object_vars($this) as $key => $var) {
      global $$key;
      $$key = $var;
    }
    $script = $paths[count($paths) - 1];
    if (is_file(VIEW_PATH . '/' . $script)) {
      include VIEW_PATH . '/' . $script;
    }
    if ($layout) {
      $this->Close();
    }
  }

  function load($action, $args=array()) {
    $arguments = "";
    if (count($args))
      $arguments = "?";
    $count = 1;
    foreach ($args as $key => $arg) {
      $arguments .= $key . '=' . $arg;
      $count++;
      $count == count($args) ? $arguments .= "&amp;" : $arguments .="";
    }
    if (!preg_match('/', $action))
    header("location:" . SITE_PATH . 'load/' . $action . '.php' . $arguments);
  }

  function reload($action, $args=array()) {
    $this->load($_SERVER['SCRIPT_NAME'], $args);
  }

  public static function asLink($page="") {
    if ($page == "")
      return;
    if (is_file(LOAD_PATH . $page .'.php'))
      return LOAD_PATH . $page .'.php';
    elseif ((is_file(VIEW_PATH . $page .'.php')))
      return VIEW_PATH . $page .'.php';
    return;
  }

  function Begin($title='Home', $infos="") {
    /*ajouter ici les templates qui font changer la class main...*/
    $full = stripos($_SERVER['SCRIPT_NAME'], "index");
    $full = $full > 0 ? $full : stripos($_SERVER['SCRIPT_NAME'], "suscribe");
    ?>
<!DOCTYPE html>
<html>
  <head>
    <title>SUPINFO - <?=$title?></title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
     <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
    
    <!-- Le styles -->
        <link rel="stylesheet" type="text/css" href="<?=CSS_PATH?>style.css" media="screen" />
        <link rel="stylesheet" type="text/css" href="<?=CSS_PATH?>bootstrap.css" media="screen" />
        <?
//          Dir::IncludeDirectory(CSS_PATH, 'css');
//          Dir::IncludeDirectory(JS_PATH, 'js');
        ?>
  </head>
  <body>
    <div id="background" class="lazyHeight">
     <div id="bg-user" class="lazyHeight">
      
     </div>
     <div id="bg-liner" class="lazyHeight">
      
     </div>      
    </div>
      
<div id="doc" class="text-shadow">
      <div id="content">
        <div id="header">
            <div class="header-colors"></div>
            <div class="<?=$full>0 ? "full" : "container-fluid"?> text-right">
              <?if (isset($this->user)):?>
              <a class="uiProfile nodeco" href="https://www.facebook.com/mangoberry?ref=tn_tnmn" title="Profil">
                <img class="uiProfilePhoto" width="32" src="https://fbcdn-profile-a.akamaihd.net/hprofile-ak-snc4/48769_770534613_1336862317_q.jpg" alt="">
                <span class="lien uiName nodeco"><?=$this->user->id?></span>
              </a>
              <?else: ?>
              <a class="btn btn-success" href="suscribe.php">Inscription</a>
              <?endif;?>
            </div>
        </div>
        <div id="main" class="<?=$full>0 ? "full" : "container-fluid"?>">
          <?                    if ($infos!=""):?>
                      <div class="alert alert-info"><strong>Attention!</strong> <?=$infos?></div>
          <?endif;?>
          <div id="main-wrapper" class="row<?=$full>0 ? "" : "-fluid"?> show-grid">
        <?
        }

        function Close() {?>
        </div>
      </div>
    </div>
      </div>
    <script type="text/javascript">
    $(document).ready(function() {

      setTimeout('heighty()',1000);
            
      $("#chat-title").click(function(){ 
        $("#chat-content").slideToggle("50","easeOutExpo");
      });
 
      $("#chat-user .icon-remove").click(function(){ 
        $("#chat-message").hide();
        $("#chat-contacts").css("height","379px");
      });
      
      $("#chat-contacts .contact").each(function(n){
        $(this).bind("click",function(){
          var name = $(this).data("name");
          $("#chat-contacts").css("height","200px"); 
          $("#chat-message").show();  
          $("#chat-user .name").text(name);  
        });
      });
      
      $(window).scroll(function(){
        if ($(window).scrollTop() >= "94" && $(window).width() > 968){
          $("#chat").css({
            "position" : "fixed",
            "top" : "15px",
            "width" : "238px"
          });
        }
        if ($(window).scrollTop() < "94" && $(window).width() > 968){
          $("#chat").css({
            "position" : "relative",
            "top" : "0px",
            "width" : "238px"
          });
        }
      });
    
    });
    
    function scrollTo(top){
      $('html, body').animate({scrollTop: top + "px" }, 200);
    }
    
    function heighty () {
      $('.lazyHeight').each(function(n) { 
        var documentHeight = $(document).height();
        $(this).css("height", documentHeight + "px");
      });
    }
    </script>
    </body>
</html>
    <?
  }
}
?>
