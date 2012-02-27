<?php
include '../inc/init.inc';
isset ($_GET['signin']) ? $result = "Veuillez vous inscrire pour accèder à toutes les fonctionnalités de l'Intranet" : $result="";
if (isset($_POST['login']) && isset($_POST['password'])) {
  $users = User::find('all', array('conditions' => array('id' => strtolower($_POST['login']), 'password' => sha1($_POST['password']."h@Ck"))));
if (count($users)>0){
    session_name('LBI');
    session_start();
    $_SESSION['user'] = $users[0];
//    if (count(!$users[0]->getPrivileges()) == 0) {
//      header("location:/M1/index.php?error=true;");
//    }
    $res->load('membres');
  }
  else
    $result="Vérifier les informations que vous avez entrées";
}
  $res->useTemplate('Bienvenue', true, $result);
?>