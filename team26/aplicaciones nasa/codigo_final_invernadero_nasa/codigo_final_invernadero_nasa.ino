/*
    GRUPO ROBOTICA UBB CHILLAN 

*/

//definición de pines usados

int pin_sensor_temperatura=A0;
int pin_sensor_humedad=A1;
int pin_sensor_luz=A2;
int pin_ventilador_entrada=9;
int pin_ventilador_salida=10;
int pin_ventilador_aire_caliente=11;
int pin_motobomba=2;
int pin_luces=3;
int pin_calefactor = 7;

//variables
int op=0;


void setup(){
  pinMode(pin_sensor_temperatura, INPUT);   
  pinMode(pin_sensor_humedad, INPUT);   
  pinMode(pin_ventilador_entrada, OUTPUT);     
  pinMode(pin_ventilador_salida, OUTPUT);     
  pinMode(pin_ventilador_aire_caliente, OUTPUT);     
  pinMode(pin_motobomba, OUTPUT);     
  pinMode(pin_luces, OUTPUT);  
  pinMode(pin_sensor_luz, INPUT);  
  
  Serial.begin(9600);
}

void loop(){

  
  if(Serial.available()){
  
    op= Serial.read();
    
    switch(op){
      case '1':
	Serial.print("La temperatura es: ");
	Serial.println(get_temperatura(pin_sensor_temperatura));
      
      break;
      case '2':
	Serial.print("humedad: ");
	Serial.println(get_humedad(pin_sensor_humedad));
      break;
      case '3':
	Serial.print("luz: ");
	Serial.println(get_luz(pin_sensor_luz));
      break;
      case '4':
	//Serial.println("Enciende luz");
        prende_luz(pin_luces, 255);
      break;
      case '5':
	//Serial.println("Apaga luz");
        apaga_luz(pin_luces);
      break;
      case '6':
	//Serial.println("Enciende motobomba");
        prende_motobomba(pin_motobomba);
      break;
      case '7':
	//Serial.println("Apaga motobomba");
        apaga_motobomba(pin_motobomba);
      break;
      case '8':
	//Serial.println("Enciende ventilador ");
        prende_ventilador(pin_ventilador_aire_caliente, 255);
      break;
      case '9':
	//Serial.println("Apaga ventilador ");
         apaga_ventilador(pin_ventilador_aire_caliente);
      break;
      case 'a':
	//Serial.println("enciende_calefactor");
         enciende_calefactor(pin_ventilador_aire_caliente,  pin_calefactor);
      break;
      case 'b':
	//Serial.println("apaga_calefactor  ");
         apaga_calefactor( pin_ventilador_aire_caliente, pin_calefactor);
      break;
      default:
        //Serial.println("digita bien a...");
      break;
      
    }
    
    if(op=='x'){
      //Serial.print("La temperatura es: ");
	Serial.print(get_temperatura(pin_sensor_temperatura));
        Serial.print(",");
	//Serial.print("luz: ");
        Serial.print(get_luz(pin_sensor_luz)); 
        Serial.print(",");
	//Serial.print("humedad: ");
        Serial.println(get_humedad(pin_sensor_humedad));
	
        delay(1000);
    }
  }
  
  
}

int get_humedad(int pin){
  return analogRead(pin);
}

int get_temperatura(int pin){
  /*
   * valor sacado de 
   * http://termochalo.blogspot.com/2012/03/senso-de-temperatura-con-lm35-en.html
   * http://www.matbra.com/en/2012/09/23/sensor-de-temperatura-com-arduino-e-lm35-arduino-lm35/
   */
  return (analogRead(pin) * 0.49);
}

int get_luz(int pin){
  return analogRead(pin);
}

void prende_luz(int pin, int intensidad){
  analogWrite(pin, intensidad);
}

void apaga_luz(int pin){
  digitalWrite(pin, LOW);
}

void prende_motobomba(int pin){
  digitalWrite(pin, HIGH);
}

void apaga_motobomba(int pin){
  digitalWrite(pin, LOW);
}

void prende_ventilador(int pin, int intensidad){
  analogWrite(pin, intensidad);
}

void apaga_ventilador(int pin){
  analogWrite(pin, 0);
}

void enciende_calefactor(int pin_ventilador, int pin_calefactor){
  prende_ventilador(pin_ventilador, 128);
  
  digitalWrite(pin_calefactor, HIGH);
  
}

void apaga_calefactor(int pin_ventilador, int pin_calefactor){
  apaga_ventilador(pin_ventilador);
  
  digitalWrite(pin_calefactor, LOW);
  
}
