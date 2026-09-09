#include <Arduino.h>
const unsigned long LED_INTERVAL=500UL;
const unsigned long PRINT_INTERVAL=2000UL;

unsigned long previous_led_time=0UL;
unsigned long previous_print_time=0UL;

bool ledstate=false;

const uint32_t LED=2U;

void setup()
{
    pinMode(LED,OUTPUT);
    Serial.begin(115200);
}
void loop()
{
    if(millis()-previous_led_time>=LED_INTERVAL)
    {
        ledstate=!ledstate;
        digitalWrite(LED,ledstate);
        previous_led_time=millis();
    }
    if(millis()-previous_print_time>=PRINT_INTERVAL)
    {
        Serial.println(millis());
        previous_print_time=millis();
    }
}