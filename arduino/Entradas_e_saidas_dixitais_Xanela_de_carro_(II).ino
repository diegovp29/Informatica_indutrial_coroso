/* En esta práctica se van a controlar dos motores con un pulsador imitando el funcionamiento de la ventanilla de un coche, de forma que al pulsar el pulsador se activa el primer motor y al volver a pulsarlo se activa
el segundo motor, los motores se mantienen activos duracte 7 segundos tras pulsar el pulsador, si se pulsa el pulsador mientras uno de los motores está activo, este se detendrá y se activará el otro sin pasar
por paro, nunca pueden estar los dos motores activos al mismo tiempo. */

#define pulsador 12
#define motorSubir 11
#define motorBajar 10
#define finalMotorSubir 9
#define finalMotorBajar 8

//Variable utilizada para utilizar el pulsador con alternancia de estado
bool estadoPulsador = 0;
bool ultimoMotor = 0;
bool estadoMotorSubir = 0;
bool estadoMotorBajar = 0;

void setup() {
  pinMode(motorSubir, OUTPUT);
  pinMode(motorBajar, OUTPUT);
  pinMode(pulsador, INPUT);
  pinMode(finalMotorSubir, INPUT);
  pinMode(finalMotorBajar, INPUT);
}

void loop() {
//Lectura del pulsador con alternancia de estado
  if(digitalRead(pulsador)) {
    estadoPulsador = !estadoPulsador;
    estadoMotorSubir = 0;
    estadoMotorBajar = 0;
    while(digitalRead(pulsador)) {
      delay(20);
    }
    if(estadoPulsador == !0){
      ultimoMotor = !ultimoMotor;
    }
  }  
//Accionamiento de los motores
  if(estadoPulsador == 0 && ultimoMotor == !0) {
    digitalWrite(motorSubir, 1);
    digitalWrite(motorBajar, 0);
    estadoMotorSubir = 1;
  }
  else if(estadoPulsador == 0 && ultimoMotor == 0){
    digitalWrite(motorSubir, 0);
    digitalWrite(motorBajar, 1);
    estadoMotorBajar = 1;
  }else{
    digitalWrite(motorSubir, 0);
    digitalWrite(motorBajar, 0);
    estadoMotorSubir = 0;
    estadoMotorBajar = 0;
  }
//Lectura del final de carrera al subir  
  if(digitalRead(finalMotorSubir)) {
//Si al accionar el final de carrera está el motor activo, lo detiene
    if(estadoMotorSubir == 1){
      digitalWrite(motorSubir, 0);
      estadoPulsador = !estadoPulsador;
      estadoMotorSubir = 0;
      ultimoMotor = !ultimoMotor;
    }
    while(digitalRead(finalMotorSubir)) {
      delay(20);
    }
  }
//Lectura del final de carrera al bajar  
  if(digitalRead(finalMotorBajar)) {
//Si al accionar el final de carrera está el motor activo, lo detiene
    if(estadoMotorBajar == 1){
      digitalWrite(motorBajar, 0);
      estadoPulsador = !estadoPulsador;
      estadoMotorBajar = 0;
      ultimoMotor = !ultimoMotor;
    }
    while(digitalRead(finalMotorBajar)) {
      delay(20);
    }
  }
}
