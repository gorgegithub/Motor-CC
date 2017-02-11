#include <SoftwareSerial.h>
SoftwareSerial BT1(11,10); // RX, TX

int IN3 = 5;
int IN4 = 4;
int ENB = 3;    // ENB conectada al pin 3 de Arduino
int option;
int value;
int value_fin;


void setup()
{
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (ENB, OUTPUT);
  Serial.begin(9600);
  BT1.begin(115200);//esta a 115200
}
void loop()
{
  //si existe datos disponibles los leemos
  if (BT1.available() > 0) {
    //leemos la opcion enviada
    option = BT1.read();    //Leemos lo que llega por Bluetooth
    Serial.write(option);   //Lo escribimos por consola

    if (option == 'S') { //Si nos mandan S Parar
      Serial.println("Orden de parada");
      analogWrite(ENB, 0);
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, LOW);
    }
    if (option == 'R') { //Girar a Derecha
      Serial.println("Girar a Derecha");
      analogWrite(ENB, 0); //Parar
      delay(300);         //Espera
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
    }
    if (option == 'L') { //Girar a Izquierda
      Serial.println("Girar a Izquierda");
      analogWrite(ENB, 0); //Parar
      delay(300);         //Espera
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, HIGH);
    }
    if (option >= '0' && option <= '9') {
      value = (value * 10) + (option - '0');
    }
    if (option == '<') {
      value_fin = value;
      Serial.println(value_fin);
      analogWrite(ENB, value_fin); //Girar a Velocidad Introducida
      value = 0;
    }
  }



}
