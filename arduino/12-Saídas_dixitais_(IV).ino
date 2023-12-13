// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
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
