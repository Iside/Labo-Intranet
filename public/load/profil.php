<?php include '../common/inc/init.inc';
if(!isset($user) OR $user->name != "invite")
    $res->load('signin.php');
?>