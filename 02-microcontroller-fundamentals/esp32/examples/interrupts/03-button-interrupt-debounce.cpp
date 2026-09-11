#include <Arduino.h>

const uint8_t BUTTON=4U;
const uint8_t LED=2U;

volatile bool button_event=false;

const unsigned long DEBOUNCE_TIME=30UL;

unsigned long start_time=0UL;

bool ledstate=false;
bool debounce_active=false;

void IRAM_ATTR on_button_pressed()
{
    button_event=true;
}
void setup()
{
    pinMode(LED,OUTPUT);
    pinMode(BUTTON,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON),on_button_pressed,FALLING);
}

void loop()
{
    bool event_received;
    noInterrupts();
    event_received=button_event;
    button_event=false;
    interrupts();
    if(event_received)
    {
        start_time=millis();
        debounce_active=true;
    }
    if(debounce_active&&millis()-start_time>=DEBOUNCE_TIME)
    {
        debounce_active=false;
        //sau 30ms vẫn đc nhấn
        if(digitalRead(BUTTON)==LOW)
        {
            ledstate=!ledstate;
            digitalWrite(LED,ledstate);
        }
    }
}