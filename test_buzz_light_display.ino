#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int thresholdVal = 400, washTime = 10;
int sensorVal, count = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  void display();				// turn on display  
  void clear();
  pinMode(6, OUTPUT);
  lcd.setRGB(255, 255, 255);
  lcd.print("Waiting...");
  delay(3000);
}

void loop() {
  sensorVal = analogRead(0);

  if (sensorVal > thresholdVal) {
    
    count++;
    lcd.clear();
    lcd.setRGB(0, 255, 0);
    lcd.print("Good Boy!");
    if(count > 10){
      lcd.clear();
      lcd.print("ure done!");
    }
    } 
    else{
      if (count != -1 && count < washTime) {
        // stinky
        lcd.clear();
        lcd.setRGB(255,0,0);
        lcd.print("Bad! Stinky!!");
        digitalWrite(6, HIGH);
        delay(50);
        digitalWrite(6, LOW);
      }

      else if(count != -1){
        lcd.clear();
        lcd.setRGB(0, 255, 0);
        lcd.print("Done!");
        count = 0;
        delay(1000);
      }
      count = -1;
    }
  Serial.println(count);
  delay(1000);
}