#include <Arduino.h>
const uint8_t BUTTON=4U;
const uint8_t LED=2U;

volatile bool button_event=false;
bool led_state=false;

void IRAM_ATTR on_button_pressed()
{
    button_event=true;

}

void setup()
{
    pinMode(BUTTON,INPUT_PULLUP);
    pinMode(LED,OUTPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON),on_button_pressed,FALLING);
}

void loop()
{
    if(button_event==true)
    {
        button_event=false;
        led_state=!led_state;
        digitalWrite(LED,led_state);
    }
}