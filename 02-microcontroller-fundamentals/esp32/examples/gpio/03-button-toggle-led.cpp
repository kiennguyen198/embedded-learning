#include <Arduino.h>
const uint8_t BUTTON=4U;
const uint8_t LED=2U;
bool led_state=false;
int previous=HIGH;
void setup()
{
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}
void loop()
{
  int current=digitalRead(BUTTON);
  if(current==LOW&&previous==HIGH)
  {
    led_state=!led_state;
    digitalWrite(LED,led_state);
  }
  previous=current;
}
