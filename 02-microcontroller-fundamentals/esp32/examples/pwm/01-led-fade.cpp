#include <Arduino.h>

const uint8_t LED_PIN = 2U;
const uint8_t PWM_CHANNEL = 0U;
const uint32_t PWM_FREQUENCY = 5000U;
const uint8_t PWM_RESOLUTION = 8U;
const int PWM_MAX_DUTY = 255;

const unsigned long FADE_INTERVAL = 20UL;

int duty = 0;
int duty_step = 5;
unsigned long previous_time = 0UL;

void setup()
{
    // Tao PWM 5 kHz voi do phan giai 8 bit tren kenh 0.
    ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);

    // Noi GPIO2 vao kenh PWM 0.
    ledcAttachPin(LED_PIN, PWM_CHANNEL);

    // Duty ban dau bang 0%, LED tat.
    ledcWrite(PWM_CHANNEL, 0U);
}

void loop()
{
    unsigned long current_time = millis();

    if (current_time - previous_time >= FADE_INTERVAL)
    {
        previous_time = current_time;
        duty += duty_step;

        // Khi dat cuc dai, doi huong de giam do sang.
        if (duty >= PWM_MAX_DUTY)
        {
            duty = PWM_MAX_DUTY;
            duty_step = -5;
        }
        // Khi ve 0, doi huong de tang do sang.
        else if (duty <= 0)
        {
            duty = 0;
            duty_step = 5;
        }

        ledcWrite(PWM_CHANNEL, (uint32_t)duty);
    }
}
