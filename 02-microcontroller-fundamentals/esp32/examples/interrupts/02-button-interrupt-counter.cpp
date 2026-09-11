#include <Arduino.h>

const uint8_t BUTTON = 4U;

// Bien duoc thay doi trong ISR nen can volatile.
volatile uint32_t interrupt_count = 0U;
uint32_t previous_count = 0U;

// ISR chi lam cong viec ngan gon, khong in Serial tai day.
void IRAM_ATTR on_button_pressed()
{
    interrupt_count++;
}

void setup()
{
    Serial.begin(115200);
    pinMode(BUTTON, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(BUTTON),
        on_button_pressed,
        FALLING
    );
}

void loop()
{
    uint32_t current_count;

    // Tam chan interrupt khi sao chep bien dung chung voi ISR.
    noInterrupts();
    current_count = interrupt_count;
    interrupts();

    // Chi in khi so dem thay doi.
    if (current_count != previous_count)
    {
        Serial.printf("So lan interrupt: %lu\n", (unsigned long)current_count);
        previous_count = current_count;
    }
}
