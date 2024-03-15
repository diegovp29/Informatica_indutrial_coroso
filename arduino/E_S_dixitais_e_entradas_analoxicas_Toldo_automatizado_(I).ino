/* En esta práctica se van a controlar un motor con un pulsador imitando el funcionamiento de un toldo, de forma que al iniciar el programa el motor gira en una dirección recogiendo el toldo, al pulsar el pulsador
de marcha/paro el motor para si lo velvemos a pulsar gira en dirección inversa abriendo el toldo, tambien hay dos pulsadores simulando finales de carrera, si está recogiendo y pulsamo su respectivo final de carrera,
este se detendrá y al pulsar el pulsador de marcha/paro iniciará en sentido contrario, lo mismo ocurre cuando se está abriendo el toldo.*/

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
int velocidad = 0;
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
//Lectura del ldr
  lecturaldr = analogRead(entradaldr);
//Mapear la entrada que recibe tensión a través del ldr en valores enteros de 0 a 5
  velocidad = map(lecturaldr, 54, 974, 0, 5);
  Serial.println(velocidad);
//Modificar la velocidad del motor
  switch (velocidad){
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
//Accionamiento del motor
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
//Lectura del final de carrera al Abrir 
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
//Lectura del final de carrera al cerrar  
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
