/* En esta práctica se van a controlar dos motores con un pulsador imitando el funcionamiento de la ventanilla de un coche, de forma que al pulsar el pulsador se activa el primer motor y al volver a pulsarlo se detiene,
si pulsamos nuevamente se activa el otro motor y así sucesivamente. Si accionamos un final de carrera mientras en motor respectivo a ese final de carrera está activo, este se detendrá y si pulsamos el pulsador de 
marcha/paro se activa el motor contrario.*/

#define pulsador 12
#define motorAbrir 11
#define motorCerrar 10
#define finalMotorAbrir 9
#define finalMotorCerrar 8
#define salidaldr 6
#define entradaldr A0

//Variable utilizada para utilizar el pulsador con alternancia de estado
bool estadoPulsador = 0;
bool ultimoMotor = 0;
bool estadoMotorAbrir = 0;
bool estadoMotorCerrar = 0;
int velocidade = 0;
int lecturaldr = 0;

void setup() {
  pinMode(motorAbrir, OUTPUT);
  pinMode(motorCerrar, OUTPUT);
  pinMode(pulsador, INPUT);
  pinMode(finalMotorAbrir, INPUT);
  pinMode(finalMotorCerrar, INPUT);
  Serial.begin(9600);
}

void loop() {
//Lectura del ldr 0.26V - 4.76V
  lecturaldr = analogRead(entradaldr);
  velocidade = map(lecturaldr, 54, 974, 0, 5);
  Serial.println(velocidade);
  switch (velocidade){
    case 0: analogWrite(salidaldr, 255*0.05);break;
    case 1: analogWrite(salidaldr, 255*0.2);break;
    case 2: analogWrite(salidaldr, 255*0.4);break;
    case 3: analogWrite(salidaldr, 255*0.6);break;
    case 4: analogWrite(salidaldr, 255*0.8);break;
    case 5: analogWrite(salidaldr, 255);break;
  }
//Lectura del pulsador con alternancia de estado
  if(digitalRead(pulsador)) {
    estadoPulsador = !estadoPulsador;
    estadoMotorAbrir = 0;
    estadoMotorCerrar = 0;
    while(digitalRead(pulsador)) {
      delay(20);
    }
    if(estadoPulsador == !0){
      ultimoMotor = !ultimoMotor;
    }
  }  
//Accionamiento de los motores
  if(estadoPulsador == 0 && ultimoMotor == !0) {
    digitalWrite(motorAbrir, 1);
    digitalWrite(motorCerrar, 0);
    estadoMotorAbrir = 1;
  }
  else if(estadoPulsador == 0 && ultimoMotor == 0){
    digitalWrite(motorAbrir, 0);
    digitalWrite(motorCerrar, 1);
    estadoMotorCerrar = 1;
  }else{
    digitalWrite(motorAbrir, 0);
    digitalWrite(motorCerrar, 0);
    estadoMotorAbrir = 0;
    estadoMotorCerrar = 0;
  }
//Lectura del final de carrera al subir  
  if(digitalRead(finalMotorAbrir)) {
    if(estadoMotorAbrir == 1){
      digitalWrite(motorAbrir, 0);
      estadoPulsador = !estadoPulsador;
      estadoMotorAbrir = 0;
      ultimoMotor = !ultimoMotor;
    }
    while(digitalRead(finalMotorAbrir)) {
      delay(20);
    }
  }
//Lectura del final de carrera al bajar  
  if(digitalRead(finalMotorCerrar)) {
    if(estadoMotorCerrar == 1){
      digitalWrite(motorCerrar, 0);
      estadoPulsador = !estadoPulsador;
      estadoMotorCerrar = 0;
      ultimoMotor = !ultimoMotor;
    }
    while(digitalRead(finalMotorCerrar)) {
      delay(20);
    }
  }
}
