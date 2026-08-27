#include <stdio.h>
#include "sensor.h"
int main(void)
{
    int temperature=sensor_read();
    printf("Temperature: %d C\n",temperature);
    return 0;
}