#include <Arduino.h>

const uint8_t LED_PIN = 2U;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_PIN, HIGH);
    delay(1000);

    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
