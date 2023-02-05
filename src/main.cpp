#include <Arduino.h>
#define GREEN 33
#define LDR 32
void setup()
{
    ledcSetup(0, 5000, 8);
    ledcAttachPin(GREEN, 0);
    Serial.begin(115200);
    Serial.println("LDR");
}
void loop()
{
  ledcWrite(0, (map(analogRead(LDR),2000,4000,0,255)));
 
}