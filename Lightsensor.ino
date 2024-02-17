#include <math.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(0), thresholdVal, sensorR;
  sensorR = (float)(1023-sensorVal)*10/sensorVal;
  if (sensorR > thresholdVal) {
    Serial.println("Bright\n");
  } else {
    Serial.println("Dark\n");
  }
}
