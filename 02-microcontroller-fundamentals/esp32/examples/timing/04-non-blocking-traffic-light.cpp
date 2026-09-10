#include <Arduino.h>

const uint8_t LED_RED = 25U;
const uint8_t LED_YELLOW = 26U;
const uint8_t LED_GREEN = 27U;

const unsigned long INTERVAL_RED = 5000UL;
const unsigned long INTERVAL_YELLOW = 2000UL;
const unsigned long INTERVAL_GREEN = 5000UL;

typedef enum
{
    RED,
    GREEN,
    YELLOW
} TrafficState;

TrafficState current_state = RED;
unsigned long previous_time = 0UL;

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);

    // Trang thai ban dau: chi bat den do
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);

    previous_time = millis();
}

void loop()
{
    unsigned long current_time = millis();

    switch (current_state)
    {
        case RED:
            if (current_time - previous_time >= INTERVAL_RED)
            {
                digitalWrite(LED_RED, LOW);
                digitalWrite(LED_GREEN, HIGH);

                current_state = GREEN;
                previous_time = current_time;
            }
            break;

        case GREEN:
            if (current_time - previous_time >= INTERVAL_GREEN)
            {
                digitalWrite(LED_GREEN, LOW);
                digitalWrite(LED_YELLOW, HIGH);

                current_state = YELLOW;
                previous_time = current_time;
            }
            break;

        case YELLOW:
            if (current_time - previous_time >= INTERVAL_YELLOW)
            {
                digitalWrite(LED_YELLOW, LOW);
                digitalWrite(LED_RED, HIGH);

                current_state = RED;
                previous_time = current_time;
            }
            break;
    }
}
