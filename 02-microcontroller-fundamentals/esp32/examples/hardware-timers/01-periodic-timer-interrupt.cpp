#include <Arduino.h>

const uint8_t LED = 2U;

volatile bool timer_event = false;
bool led_state = false;

// Con tro quan ly hardware timer.
hw_timer_t *timer = nullptr;

// ISR chi bao da het mot chu ky timer.
void IRAM_ATTR on_timer()
{
    timer_event = true;
}

void setup()
{
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);

    // Timer 0, chia clock 80 MHz cho 80 -> 1 MHz.
    // Moi tick cua timer dai 1 microsecond.
    timer = timerBegin(0U, 80U, true);

    // Goi on_timer khi timer tao interrupt.
    timerAttachInterrupt(timer, on_timer, true);

    // 1 000 000 tick = 1 giay, true = tu dong lap lai.
    timerAlarmWrite(timer, 1000000ULL, true);
    timerAlarmEnable(timer);
}

void loop()
{
    bool event_received;

    // Lay va xoa co dung chung voi ISR.
    noInterrupts();
    event_received = timer_event;
    timer_event = false;
    interrupts();

    if (event_received)
    {
        led_state = !led_state;
        digitalWrite(LED, led_state);
    }
}
