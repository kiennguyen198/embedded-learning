#include "counter.h"

// Định nghĩa thật và cấp phát bộ nhớ
uint32_t counter = 0U;

void counter_increment(void)
{
    counter++;
}