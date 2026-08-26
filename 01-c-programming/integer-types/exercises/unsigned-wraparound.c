#include <stdio.h>
#include <stdint.h>
#include <limits.h>
int main(void)
{
    uint8_t maximum=255;
    printf("%u\n",(unsigned)maximum);
    maximum++;
    printf("%u\n",(unsigned)maximum);

    uint8_t minimum=0;
    minimum--;
    printf("%u\n",(unsigned)minimum);

    uint8_t value=250;
    value+=10; // 250+10=260%256=4
    printf("%u\n",(unsigned)value); // 4 

    value=3;
    value-=5;
    printf("%u\n",(unsigned)value); //254

    printf("uint8_t:  %zu byte\n", sizeof(uint8_t)); // zu in giá trị size_t
}