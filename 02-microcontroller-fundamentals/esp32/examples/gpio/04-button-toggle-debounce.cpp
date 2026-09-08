#include <Arduino.h>

const uint8_t BUTTON = 4U;
const uint8_t LED = 2U;
const unsigned long DEBOUNCE_TIME = 30UL;

bool led_state = false;
int previous = HIGH;
unsigned long last_press_time = 0UL;

void setup()
{
    pinMode(BUTTON, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
}

void loop()
{
    int current = digitalRead(BUTTON);
    unsigned long now = millis();

    // Phat hien canh nhan va bo qua cac canh qua gan nhau
    if ((current == LOW) &&
        (previous == HIGH) &&
        (now - last_press_time >= DEBOUNCE_TIME))
    {
        led_state = !led_state;
        digitalWrite(LED, led_state);
        last_press_time = now;
    }

    previous = current;
}
