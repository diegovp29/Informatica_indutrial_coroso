// C++ code
//
/*Puertas lógicas con arduino

Tenemos 3 pulsadores, A, B y C, el pulsador A está conectado al pin 10, el pulsador B está conectado al pin 9 y el pulsador C está conectado al pin 8

Si el pulsador B está pulsado y  los pulsadores B y C no, se enciende el led, si los pulsadores A y B están pulsados y el pulsador C no, se enciende el led, y si todos los pulsadores están pulsados, se enciende el led.
Cuando el led se enciende, queda encendido durante 4 segundos. En caso de no cumplirse ninguno de los casos anteriores, el led permanecerá apagado.
*/
void setup()
{
  //Pulsador A en el pin 10
  pinMode(10, INPUT);
  //Pulsador B en el pin 9
  pinMode(9, INPUT);
  //Pulsador C en el pin 8
  pinMode(8, INPUT);
  //Led conectado en el pin 12
  pinMode(12, OUTPUT);
}

void loop()
{
  //Si el pulsador B está pulsado y  los pulsadores B y C no, se enciende el led, si los pulsadores A y B están pulsados y el pulsador C no, se enciende el led, y si todos los pulsadores están pulsados, se enciende el led
  if (digitalRead(10) == LOW && (digitalRead(9) == HIGH && digitalRead(8) == LOW) || (digitalRead(10) == HIGH && (digitalRead(9) == HIGH && digitalRead(8) == LOW) || digitalRead(10) == HIGH && (digitalRead(9) == HIGH && digitalRead(8) == HIGH))) {
    //Damos tensión al pin 12
    digitalWrite(12, HIGH);
    //Esperamos 4 segundos
    delay(4000);
    //Si no se cumplen ninguna de las condiciones anteriores ejecutamos los siguiente
  } else {
    //Quitamos tensión del pin 12
    digitalWrite(12, LOW);
  }
}
