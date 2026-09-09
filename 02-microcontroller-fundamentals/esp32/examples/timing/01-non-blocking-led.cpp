#include <Arduino.h>
const uint8_t LED=2U;
const unsigned long INTERVAL=1000UL;

bool led_state=false;
unsigned long previous_time=0UL;

void setup()
{
    pinMode(LED,OUTPUT);
}

void loop()
{
    if(millis()-previous_time>=INTERVAL)
    {
        led_state=!led_state;
        digitalWrite(LED,led_state);
        previous_time=millis();
    }
}