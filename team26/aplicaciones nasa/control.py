import serial
import urllib2 
ser = serial.Serial('/dev/ttyACM0', 9600)
opcion = "0"
while 1:
  f = urllib2.urlopen("http://192.168.1.111/config-planta/opcion.php")
  opcion1=f.read()
  print opcion1
  if opcion1 == opcion:
    ser.write('x')
    srt=ser.readline() #leo una linea, lee temperatura,luz,humedad
    srt=srt.strip()
    lista=srt.split(",")#tokenizo el string
    print lista
    f = urllib2.urlopen("http://192.168.1.111/config-planta/guardar.php?t="+lista[0]+"&l="+lista[1]+"&h="+lista[2])
    f.read()  
    f.close()
  
  else:
    ser.write(opcion1)
    opcion=opcion1
