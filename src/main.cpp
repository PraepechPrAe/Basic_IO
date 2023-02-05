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
}

void loop()
{
    ledcWrite(0, (map(analogRead(LDR),2000,4000,0,255)));

    debouncer.update();
    if ( debouncer.fell() ) { 
        cnt++;
    }
    if (cnt == 1){
        digitalWrite(GREEN,1);
        digitalWrite(RED,0);
        digitalWrite(YELLOW,0);
    }
    if (cnt == 2){
        digitalWrite(GREEN,0);
        digitalWrite(RED,0);
        digitalWrite(YELLOW,1);
    }
    if (cnt == 3){
        digitalWrite(GREEN,1);
        digitalWrite(RED,0);
        digitalWrite(YELLOW,1);
    }
    if (cnt == 4){
        digitalWrite(GREEN,0);
        digitalWrite(RED,1);
        digitalWrite(YELLOW,0);
    }
    if (cnt == 5){
        digitalWrite(GREEN,1);
        digitalWrite(RED,1);
        digitalWrite(YELLOW,0);
    }
    if (cnt == 6){
        digitalWrite(GREEN,0);
        digitalWrite(RED,1);
        digitalWrite(YELLOW,1);
    }
    if (cnt == 7){
        digitalWrite(GREEN,1);
        digitalWrite(RED,1);
        digitalWrite(YELLOW,1);
    }
    if (cnt == 8){
        digitalWrite(GREEN,0);
        digitalWrite(RED,0);
        digitalWrite(YELLOW,0);
        cnt = 0;
    }
}