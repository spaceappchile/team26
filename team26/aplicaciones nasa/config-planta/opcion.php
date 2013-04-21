<?php

	$host="localhost";
	$user="WordPress";
	$pass="planta";
	$db="planta2";

	$conexion = mysql_connect($host, $user, $pass) or die(mysql_error() );
	mysql_select_db($db, $conexion);
	$consultaSQL="SELECT * FROM opcion";
	$r3 = mysql_query($consultaSQL, $conexion) or die(mysql_error());
	echo mysql_result($r3, 0, "opcion");
	mysql_close($conexion);


?>
