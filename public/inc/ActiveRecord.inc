<?php

require 'lib/Singleton.inc';
require 'lib/Config.inc';
require 'lib/Utils.inc';
require 'lib/DateTime.inc';
require 'lib/Model.inc';
require 'lib/Table.inc';
require 'lib/ConnectionManager.inc';
require 'lib/Connection.inc';
require 'lib/SQLBuilder.inc';
require 'lib/Reflections.inc';
require 'lib/Inflector.inc';
require 'lib/CallBack.inc';
require 'lib/Exceptions.inc';

spl_autoload_register('activerecord_autoload');

function activerecord_autoload($class_name)
{
	$path = ActiveRecord\Config::instance()->get_model_directory();
	$root = realpath(isset($path) ? $path : '.');

	if (($namespaces = ActiveRecord\get_namespaces($class_name)))
	{
		$class_name = array_pop($namespaces);
		$directories = array();

		foreach ($namespaces as $directory)
			$directories[] = $directory;

		$root .= DIRECTORY_SEPARATOR . implode($directories, DIRECTORY_SEPARATOR);
	}

	$file = "$root/$class_name.inc";

	if (file_exists($file))
		require $file;
}
?>
