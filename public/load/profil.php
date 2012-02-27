<?php include '../inc/init.inc';
if(!isset($user))
    $res->load('signin.php');
$res->useTemplate('Mon Profil')
?>