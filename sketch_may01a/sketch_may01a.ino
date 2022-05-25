//ER3N

#include "NewPing.h"
#include <LiquidCrystal_I2C.h>
#define ECHO_PIN 7
#define TRIG_PIN 6
#define MAX_UZAKLIK 400


NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_UZAKLIK);
LiquidCrystal_I2C lcd(0x27,16,2);

float mesafe,boy;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(8, INPUT); //button
  pinMode(4, OUTPUT);//buzzer
  Serial.begin(9600);
}

void loop() {
  int yan = digitalRead(8);
  
  if(yan==1)
  { 
    lcd.clear();
    sistem();
    digitalWrite(4,1);
    delay(300);
    digitalWrite(4,0);
    delay(10000);
    lcd.clear();
    
    
  }
  else
  { 
    lcd.clear();
    lcd.print("OLCUM YOK");
    delay(1000);
    }
  
  //mesafe = sonar.ping_cm();
  //boy = 187 - mesafe;
  //lcd.setCursor(0,0);
  //lcd.print("|-BOYUNUZ-|");
  //lcd.setCursor(0,1);
  //lcd.print(boy);
  //delay(200);
  //lcd.clear();
}

void sistem(){
  mesafe = sonar.ping_cm();
  boy = 187 - mesafe;
  lcd.setCursor(0,0);
  lcd.print("|-BOYUNUZ-|");
  lcd.setCursor(0,1);
  lcd.print(boy);
  delay(200);
  
  Serial.println(boy);

}
