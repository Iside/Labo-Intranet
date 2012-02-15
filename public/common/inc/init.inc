<?php
// <editor-fold defaultstate="collapsed" desc="set global variable">
define('Environment', 'production');
//define('Environment', 'development');
Environment == 'development' ? define("SITE_PATH", '/public/') : define("SITE_PATH", '/');
define("SYS_PATH", '../common/inc/');
define("VIEW_PATH", '../views');
define("LOAD_PATH", '../load');
define("WP_INC_PATH", '../blog/wp_includes/');
define("IMG_PATH", '../common/img/');
define("MODEL_PATH", '../common/inc/models');
define("SiteName", 'Labo-Robotique');
define("JS_PATH", '../common/js');
define("CSS_PATH", '../common/css');
setlocale(LC_ALL, 'fr_FR');
if (strtolower($_SERVER['REQUEST_URI']) == strtolower(SITE_PATH))
    header("location:" . SITE_PATH . 'load');
// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="inclusion des classes de models">
require_once '../common/inc/ActiveRecord.inc';
require_once '../common/inc/sys/Dir.inc';
require_once '../common/inc/sys/Template.inc';

$connections = array(
    'development' => 'mysql://root:test@localhost/dev_intranet?charset="utf8',
    'production' => 'mysql://user_f657b901:IdZ&)t%az^mqEF@a.db.shared.orchestra.io/db_f657b901?charset="utf8'
);

ActiveRecord\Config::initialize(function($cfg) use ($connections) {
            $cfg->set_model_directory('../common/inc/models');
            $cfg->set_connections($connections);
            $cfg->set_date_format("Y-m-d H:i:s");

# A fixer sur production lorsque le projet sera termine
            $cfg->set_default_connection(Environment);
        });
session_name('LBIntranet');
session_start();
if (isset($_SESSION['user']))
    $user = $_SESSION['user'];

$res = Template::instance('template');
// </editor-fold>
?>