#include <EEPROM.h>

#define PinSensorLuz A5
#define PinSensorPIR 12
#define PinPotenc    A4
#define PinRele      10
#define PinLedEstado  7
#define PinLedPIR     6
#define PinLedLuz     5

bool automatico;

void setup(){
  pinMode(PinSensorPIR, INPUT);
  pinMode(PinSensorLuz, INPUT);
  pinMode(PinPotenc   , INPUT);
  
  
  pinMode(PinRele     , OUTPUT);
  pinMode(PinLedEstado, OUTPUT);
  pinMode(PinLedPIR   , OUTPUT);
  pinMode(PinLedLuz   , OUTPUT);
  
 
  automatico = iniciaEstado();
}
 
void loop(){
  digitalWrite(PinLedLuz,estaEscuro());
  digitalWrite(PinLedPIR,temGente());
  digitalWrite(PinLedEstado,automatico);
  
  
  if (automatico){
    if (temGente && estaEscuro()){
      ligarLampada(true,PinRele);
      }else{ 
        desligaLampada();
  
    }  
   }else{
      ligarLampada();
  
 }
}

bool estaEscuro(){
  int valorSensor = analogRead(PinSensorLuz);
  int valorPotenc = analogRead(PinPotenc);
  return (valorSensor > valorPotenc);
}

bool temGente(){
  return(digitalRead(PinSensorPIR));
  
}
void ligarLampada(){
  digitalWrite(PinRele,HIGH);
}

void ligarLampada(bool estado){
  digitalWrite(PinRele,estado);
}

void ligarLampada(bool estado, int porta){
  digitalWrite(porta,estado);
}

void desligaLampada(){
 digitalWrite(PinRele,LOW); 
}


bool iniciaEstado(){
  
  bool gravado = EEPROM.read(0);
  EEPROM.write(0,!gravado);
  return !gravado;
}