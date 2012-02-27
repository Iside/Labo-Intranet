<?php include '../inc/init.inc';
$res->membres = User::all();
$res->useTemplate('Liste des membres', true, "");