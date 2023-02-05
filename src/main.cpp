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
  while(1)
  {
    ledcWrite(0, Serial.println(map(analogRead(LDR),0,4095,0,255)));
    //delay(5);
  }

}