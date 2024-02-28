/* En esta práctica se van a controlar dos motores con un pulsador imitando el funcionamiento de la ventanilla de un coche, de forma que al pulsar el pulsador se activa el primer motor y al volver a pulsarlo se activa
el segundo motor, los motores se mantienen activos duracte 7 segundos tras pulsar el pulsador, si se pulsa el pulsador mientras uno de los motores está activo, este se detendrá y se activará el otro sin pasar
por paro, nunca pueden estar los dos motores activos al mismo tiempo. */

#define pulsador 12
#define motorSubir 11
#define motorBajar 10

//Variable utilizada para utilizar el pulsador con alternancia de estado
bool estado = 0;
//Contador para el tiempo que los motores deben permanecer funcionando
int contador = 100; 

void setup() {
  pinMode(motorSubir, OUTPUT);
  pinMode(motorBajar, OUTPUT);
  pinMode(pulsador, INPUT);
}

void loop() {
//Lectura del pulsador con alternancia de estado
  if(digitalRead(pulsador)) {
    estado = !estado; 
    contador = 100;
    while(digitalRead(pulsador)) {
      delay(20);
    }
  }
  
//Accionamiento de los motores
  if(contador > 0) {
    if(estado == 0) {
      digitalWrite(motorSubir, 1);
      digitalWrite(motorBajar, 0);
      delay(70);
      contador--;
    }
    else {
      digitalWrite(motorSubir, 0);
      digitalWrite(motorBajar, 1);
      delay(70);
      contador--;
    }
  }
//Si ningún motor está funcionando, lee el estado del pulsador cada 50 ms
  else {
    delay(50);
  }
//Tras termiar el tiempo activo, se paran los motores
  if (contador ==0) {
    digitalWrite(motorSubir, 0);
    digitalWrite(motorBajar, 0);
  }
}
