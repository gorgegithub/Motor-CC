int IN3 = 5; 
int IN4 = 4;
int ENB = 3;    // ENB conectada al pin 3 de Arduino
void setup()
{
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (ENB, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // Motor gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  // Aplicamos PWM al pin ENB, haciendo girar el motor, cada 2 seg aumenta la velocidad
  Serial.println("40");
  analogWrite(ENB,40);
  delay(2000);
  Serial.println("50");
  analogWrite(ENB,50);
  delay(2000);
  Serial.println("100");
  analogWrite(ENB,100);
  delay(2000);
  Serial.println("150");
  analogWrite(ENB,150);
  delay(2000);
  Serial.println("200");
  analogWrite(ENB,200);
  delay(2000);
  Serial.println("255");
  analogWrite(ENB,255);
  delay(2000);

  
  // Apagamos el motor y esperamos 5 seg
  Serial.println("5s Parada");
  analogWrite(ENB,0);
  delay(5000);
}
