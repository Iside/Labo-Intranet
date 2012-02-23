<?php include '../common/inc/init.inc';
$res->membres = User::all();
$res->useTemplate(array('Liste des membres', true, true, ""), array(true));