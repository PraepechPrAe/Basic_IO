#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define LDR 32
#define GREEN 33
#define YELLOW 25
#define RED 26
int cnt =0;
Bounce debouncer = Bounce();
void setup() {
    Serial.begin(115200);
    debouncer.attach(BUTTON, INPUT_PULLUP);
    debouncer.interval(25); 
    pinMode(GREEN, OUTPUT);
    digitalWrite(GREEN,0);
    pinMode(RED, OUTPUT);
    digitalWrite(RED,0);
    pinMode(YELLOW, OUTPUT);
    digitalWrite(YELLOW,0);

    ledcSetup(0, 5000, 8);
    ledcSetup(1, 5000, 8);
    ledcSetup(2, 5000, 8);
    ledcAttachPin(GREEN, 0);
    ledcAttachPin(YELLOW, 1);
    ledcAttachPin(RED, 2);
}

void loop()
{
  debouncer.update();
  if ( debouncer.fell() ) { 
      cnt++;
      cnt = cnt%8;
  }
  int num = cnt;
  for(int i=0; i<3; i++)
  {
    int a=num%2;
    ledcWrite(i, a*(map(analogRead(LDR),2000,4000,0,255)));
    num = num/2;
  }
}