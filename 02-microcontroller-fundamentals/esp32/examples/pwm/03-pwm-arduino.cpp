#include <Arduino.h>
const int LED=2;
void setup()
{
    pinMode(LED,OUTPUT);
}
void loop()
{
    analogWrite(LED,0);
    delay(1000);
    analogWrite(LED,64);
    delay(1000);
    analogWrite(LED,128);
    delay(1000);
    analogWrite(LED,192);
    delay(1000);
    analogWrite(LED,255);
    delay(1000);
}