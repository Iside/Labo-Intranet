<?php
include 'common/inc/init.inc';
if (isset($user) && $user->keep_connection != 0) {
  session_start();
  session_unset();
  session_destroy();
}
  header("location:".SITE_PATH);
