<?php

        $host="localhost";
        $user="WordPress";
        $pass="planta";
        $db="planta2";

        $temp=$_GET['t'];
        $luz=$_GET['l'];
        $humedad=$_GET['h'];
        $fecha=date("Y-m-d H:i:s");
        
        $conexion = mysql_connect($host, $user, $pass) or die(mysql_error() );
        mysql_select_db($db, $conexion);
        $consultaSQL="insert into datos (temperatura, luz, humedad, fecha)";
	$consultaSQL .= " VALUES (".$temp.",".$luz.",".$humedad.",'".$fecha."')";
	
	echo $consultaSQL;
	
        $r3 = mysql_query($consultaSQL, $conexion) or die(mysql_error());

        echo "actualizado";
        mysql_close($conexion);


?>
