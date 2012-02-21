<?php
include '../common/inc/init.inc';
if (isset($_POST['login']) && isset($_POST['password'])) {
  $users = User::find('all', array('conditions' => array('campus_id' => strtolower($_POST['login']), 'password' => sha1($_POST['password']."h@Ck"))));
if (count($users)>0){
    $_SESSION['user'] = $users[0];
//    if (count(!$users[0]->getPrivileges()) == 0) {
//      header("location:/M1/index.php?error=true;");
//    }
    $res->load('profil', array('failed' => 'true'));
  }
  else
    $res->reload(array('failed' => 'true'));
}
  $res->useTemplate(array("Connexion"));
?>