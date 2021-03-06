<?php
// <editor-fold defaultstate="collapsed" desc="set global variable">

/*
 * Basculer sur production avant passage en prod de ce fichier
 */
define('Environment', 'production');
//define('Environment', 'development');
Environment == 'development' ? define("SITE_PATH", '/public/') : define("SITE_PATH", '/');
define("SYS_PATH", '../inc/');
define("VIEW_PATH", '../views/');
define("LOAD_PATH", '../load/');
define("IMG_PATH", '../common/img/');
define("MODEL_PATH", '../inc/models');
define("SNIPPET_PATH", '../inc/snippets/');
define("SiteName", 'Intranet');
define("JS_PATH", '../common/js/');
define("CSS_PATH", '../common/css/');
setlocale(LC_ALL, 'fr_FR');
if (strtolower($_SERVER['REQUEST_URI']) == strtolower(SITE_PATH))
    header("location:" . SITE_PATH . 'load');
// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="inclusion des classes de models">
require_once '../inc/ActiveRecord.inc';
require_once '../inc/sys/Dir.inc';
require_once '../inc/sys/Template.inc';
require_once '../inc/sys/Snippet.inc';

$connections = array(
    'development' => 'mysql://root:test@localhost/dev_intranet?charset="utf8',
    'production' => 'mysql://user_9a66987e:oAYpoB3)tgrrBa@a.db.shared.orchestra.io/db_9a66987e?charset="utf8'
);

ActiveRecord\Config::initialize(function($cfg) use ($connections) {
            $cfg->set_model_directory('../inc/models');
            $cfg->set_connections($connections);
            $cfg->set_date_format("Y-m-d H:i:s");
            $cfg->set_default_connection(Environment);
        });

$res = Template::instance('template');
$res->widget = $widget = Snippet::instance('snippet');;
session_name('LBI');
session_start();
if (isset($_SESSION['user'])){
    $user = $_SESSION['user'];
    $res->user = $user;
}
else{
  if (!stripos($_SERVER['SCRIPT_NAME'], "index.php") && !stripos($_SERVER['SCRIPT_NAME'], "suscribe.php")) {
    $res->user = null;
    $res->load('index', array("signin" => 1));
  }
}
// </editor-fold>
?>