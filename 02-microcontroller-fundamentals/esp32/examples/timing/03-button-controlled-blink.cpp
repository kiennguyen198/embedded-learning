#include <Arduino.h>

const uint8_t LED_PIN = 2U;
const uint8_t BUTTON_PIN = 4U;
const unsigned long LED_INTERVAL = 500UL;
const unsigned long DEBOUNCE_TIME = 30UL;

bool led_state = false;
bool blinking_enabled = true;
int previous_button = HIGH;
unsigned long previous_led_time = 0UL;
unsigned long last_press_time = 0UL;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    unsigned long current_time = millis();
    int current_button = digitalRead(BUTTON_PIN);

    // Nhan nut hop le: dao che do nhap nhay
    if ((current_button == LOW) &&
        (previous_button == HIGH) &&
        (current_time - last_press_time >= DEBOUNCE_TIME))
    {
        blinking_enabled = !blinking_enabled;
        last_press_time = current_time;

        if (!blinking_enabled)
        {
            led_state = false;
            digitalWrite(LED_PIN, LOW);
        }
        else
        {
            previous_led_time = current_time;
        }
    }

    previous_button = current_button;

    // Nhap nhay LED ma khong chan chuong trinh
    if (blinking_enabled &&
        (current_time - previous_led_time >= LED_INTERVAL))
    {
        led_state = !led_state;
        digitalWrite(LED_PIN, led_state);
        previous_led_time = current_time;
    }
}
