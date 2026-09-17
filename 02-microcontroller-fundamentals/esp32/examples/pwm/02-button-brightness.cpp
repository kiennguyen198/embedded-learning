#include <Arduino.h>

const uint8_t LED_PIN = 2U;
const uint8_t BUTTON_PIN = 4U;

const uint8_t PWM_CHANNEL = 0U;
const uint32_t PWM_FREQUENCY = 5000U;
const uint8_t PWM_RESOLUTION = 8U;

const uint8_t BRIGHTNESS_LEVELS[] = {0U, 85U, 170U, 255U};
const uint8_t LEVEL_COUNT = sizeof(BRIGHTNESS_LEVELS) / sizeof(BRIGHTNESS_LEVELS[0]);
const unsigned long DEBOUNCE_TIME = 30UL;

uint8_t brightness_level = 0U;
int previous_button_state = HIGH;
unsigned long last_press_time = 0UL;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // Tao PWM 5 kHz, do phan giai 8 bit tren channel 0.
    ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, PWM_CHANNEL);
    ledcWrite(PWM_CHANNEL, BRIGHTNESS_LEVELS[brightness_level]);
}

void loop()
{
    unsigned long current_time = millis();
    int current_button_state = digitalRead(BUTTON_PIN);

    // Phat hien canh nhan: nut chuyen tu HIGH sang LOW.
    if (current_button_state == LOW && previous_button_state == HIGH)
    {
        if (current_time - last_press_time >= DEBOUNCE_TIME)
        {
            brightness_level++;

            if (brightness_level >= LEVEL_COUNT)
            {
                brightness_level = 0U;
            }

            // Moi lan nhan chuyen sang muc duty ke tiep.
            ledcWrite(PWM_CHANNEL, BRIGHTNESS_LEVELS[brightness_level]);
            last_press_time = current_time;
        }
    }

    previous_button_state = current_button_state;
}
