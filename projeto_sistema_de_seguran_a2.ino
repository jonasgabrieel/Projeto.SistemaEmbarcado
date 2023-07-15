#define pinSensorAberto 12
#define pinSensorFechado 2
#define pinMotorAbre 6 
#define pinMotorFecha 5
#define pinLEDAberto 11
#define pinLEDFechado 10
#define pinSensorLuz A4
#define pinPotenc A5

void setup()
{
  pinMode(pinSensorAberto, INPUT_PULLUP);
  pinMode(pinSensorFechado, INPUT_PULLUP);
  
  pinMode(pinMotorAbre, OUTPUT);
  pinMode(pinMotorFecha, OUTPUT);
  pinMode(pinLEDAberto, OUTPUT);
  pinMode(pinLEDFechado, OUTPUT);
  
}

void loop()
{
  if(analogRead(pinSensorLuz) < analogRead(pinPotenc)){
    if(!estaAberta()){
      abrir();
    }
  }else{
    if(!estaFechado()){
    
    fechar();
    }
  }

}

bool estaAberta(){
  return !digitalRead(pinSensorAberto);
}

bool estaFechado(){
  return !digitalRead(pinSensorFechado);
}

void abrir(){
  digitalWrite(pinLEDFechado, LOW);
  digitalWrite(pinMotorAbre, HIGH);
  while(!estaAberta()){
    piscaLED(pinLEDAberto);
    
  }
  digitalWrite(pinMotorAbre, LOW);
  digitalWrite(pinLEDAberto, HIGH);

}


void fechar(){
  digitalWrite(pinLEDAberto, LOW);
  digitalWrite(pinMotorFecha, HIGH);
  while(!estaFechado()){
    piscaLED(pinLEDFechado);
    
  }
  digitalWrite(pinMotorFecha, LOW);
  digitalWrite(pinLEDFechado, HIGH);


  
}

void piscaLED(int porta) {
  digitalWrite(porta, bitRead(millis(),6));
}