#include <Arduino.h>

const uint8_t BUTTON_PIN = 4U;
const uint8_t LED_PIN = 2U;

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}
