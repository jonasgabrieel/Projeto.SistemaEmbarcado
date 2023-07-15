// C++ code
//
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(34,16,2);


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(10, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Sistema Ativado");
  lcd.setCursor(0,1);
  lcd.print("Monitorando...");
  Serial.println(digitalRead(10));
  while (digitalRead(10) == 1) {
    if (0.01723 * readUltrasonicDistance(4, 3) >= 336 && 0.01723 * readUltrasonicDistance(6, 5) >= 336) {
      digitalWrite(2, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    } else {
      if (0.01723 * readUltrasonicDistance(4, 3) < 336 || 0.01723 * readUltrasonicDistance(6, 5) < 336) {
        digitalWrite(2, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
      }
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}