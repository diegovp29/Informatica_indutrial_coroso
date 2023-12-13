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
  /*comprobamos que o pulsador conectado ao pin 10
  non esté pulsado*/
  if (digitalRead(10) == LOW) {
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
