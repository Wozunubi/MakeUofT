#include <math.h>

const int thresholdVal = 400, washTime = 10;
int sensorVal, count = -1;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);  
}

void loop() {
  sensorVal = analogRead(0);

  if (sensorVal > thresholdVal) {
    count++;
  } else {
    if (count != -1 && count < washTime) {
      // stinky
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
    }

    count = -1;
  }

  Serial.println(count);

  delay(1000);
}
