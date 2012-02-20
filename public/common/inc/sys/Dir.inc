<?php

class Dir {

    public static function listFiles($Directory, $Entries=Array()) {
        $MyDirectory = opendir($Directory) or die('Erreur');
        while ($Entry = @readdir($MyDirectory)) {
            if (is_dir($Directory . '/' . $Entry) && $Entry != '.' && $Entry != '..' && $Entry != 'lib')
                array_merge($Entries, listFiles($Directory . '/' . $Entry));
            else {
                if ($Entry != '.' && $Entry != '..')
                    $Entries[] = $Directory . '/' . $Entry;
            }
            return $Entries;
        }
    }

    public static function IncludeDirectory($Directory, $type='inc') {
        $MyDirectory = opendir($Directory) or die('Erreur');
        while ($Entry = @readdir($MyDirectory)) {
            if (is_dir($Directory . '/' . $Entry) && $Entry != '.' && $Entry != '..' && $Entry != 'lib')
                IncludeDirectory($Directory . '/' . $Entry, $type);
            else {
                if ($Entry != '.' && $Entry != '..') {
                    switch ($type) {
                        case 'inc':
                            require_once $Directory . '/' . $Entry;
                            break;
                        case 'js':
                            print "<script type='text/javascript' src='" . $Directory . '/' . $Entry . "'></script>\n";
                            break;
                        case 'css':
                            print "<link rel='stylesheet' type='text/css' media='screen' href='" . $Directory . '/' . $Entry . "' />\n";
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        closedir($MyDirectory);
    }

}

?>
