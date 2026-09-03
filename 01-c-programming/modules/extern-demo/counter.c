#include <stdio.h>
#include "counter.h"

int main(void)
{
    printf("Initial counter: %u\n", (unsigned)counter);

    counter_increment();
    counter_increment();

    printf("Final counter: %u\n", (unsigned)counter);

    return 0;
}