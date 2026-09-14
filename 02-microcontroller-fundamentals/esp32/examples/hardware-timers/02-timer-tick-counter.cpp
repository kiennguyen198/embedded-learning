#include <Arduino.h>

const uint8_t LED = 2U;

volatile uint32_t tick_count = 0U;

uint32_t led_ticks = 0U;
uint32_t print_ticks = 0U;
bool led_state = false;

hw_timer_t *timer = nullptr;

// Moi 100 ms, ISR chi tang bien dem tick.
void IRAM_ATTR on_timer()
{
    tick_count++;
}

void setup()
{
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    Serial.begin(115200);

    // 80 MHz / 80 = 1 MHz, moi tick dai 1 microsecond.
    timer = timerBegin(0U, 80U, true);
    timerAttachInterrupt(timer, on_timer, true);

    // 100 000 tick = 100 ms, true = tu dong lap lai.
    timerAlarmWrite(timer, 100000ULL, true);
    timerAlarmEnable(timer);
}

void loop()
{
    uint32_t received_ticks;

    // Lay toan bo tick da phat sinh, sau do dua bien chung ve 0.
    noInterrupts();
    received_ticks = tick_count;
    tick_count = 0U;
    interrupts();

    led_ticks += received_ticks;
    print_ticks += received_ticks;

    // 5 x 100 ms = 500 ms.
    while (led_ticks >= 5U)
    {
        led_ticks -= 5U;
        led_state = !led_state;
        digitalWrite(LED, led_state);
    }

    // 10 x 100 ms = 1 giay.
    while (print_ticks >= 10U)
    {
        print_ticks -= 10U;
        Serial.println("1 second");
    }
}
