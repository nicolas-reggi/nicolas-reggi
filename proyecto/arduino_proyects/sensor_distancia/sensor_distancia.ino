#include <Servo.h>//biblioteca Servo para controlar servo motor
Servo servo1;

int trigPin = 12;//Pin 12 de Arduino conectado al pin Trigger del sensor.
int ecoPin = 11;//Pin 11 de Arduino conectado al pin Echo del sensor. 
long tiempo;//se utiliza como variable para numeros grandes. 
int distancia;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(ecoPin, INPUT);
Serial.begin(9600);//Inicializa la comunicación serial a 9600 bps.
servo1.attach(10);//Conecta el servo motor al pin 10. 
}
void loop() {
 
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
tiempo = pulseIn(ecoPin, HIGH);
distancia = (tiempo * 0.034) / 2;
//multiplica tiempo de de ida y vuelta del pulso en microsegundos.
//por la velocidad del sonido 340 metros-x-seg o 0,034cm x seg dividido 2 ya que es ida i vuelta.
Serial.println(distancia);
delay(500);
if (distancia<=50)
{
servo1.write(180);
}
else
{
servo1.write(0);//Si la distancia es menor o igual a 50 cm, gira el servo motor a 180 grados; de lo contrario, lo gira a 0 grados.
  }
}