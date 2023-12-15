// C++ code
//
void setup()
{
  pinMode(10, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  /*Si el pulsador envía señal pone en low las
  salidas 11, 12 y 13*/
  if (digitalRead(10) == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  } /* Si no se cumple la condición anterior hace 
  lo siguiente */
  else {
    //damos tensión en el pin 13
    digitalWrite(LED_BUILTIN, HIGH);
    //esperamos 10 segundos
    delay(10000);
    //quitamos tensión en el pin 13
    digitalWrite(LED_BUILTIN, LOW);
    //esperamos 4 segundos
    delay(4000);
    //damos tensión en el pin 12
    digitalWrite(12, HIGH);
    //damos tensión en el pin 11
    digitalWrite(11, HIGH);
    //esperamos 10 segundos
    delay(10000);
    //quitamos tensión en el pin 12
    digitalWrite(12, LOW);
    //quitamos tensión en el pin 11
    digitalWrite(11, LOW);
    //esperamos 4 segundos
    delay(4000);
  }
}
