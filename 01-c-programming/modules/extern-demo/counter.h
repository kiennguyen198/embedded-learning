#ifndef COUNTER.H
#define COUNTER.H
#include <stdint.h>

extern uint32_t counter; // có một biến counter ở nơi khác không cấp phát bộ nhớ cho nó
void counter_increment(void);
#endif