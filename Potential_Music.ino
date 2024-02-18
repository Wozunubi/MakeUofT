	
#define BUZZER 5
 
void setup()
{  
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
}
 
void loop()
{
  digitalWrite(BUZZER, LOW);
  delayMicroseconds(2273);
  digitalWrite(BUZZER, HIGH);
  delayMicroseconds(2273);
}