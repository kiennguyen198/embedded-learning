#include <stdio.h>
#include <stdint.h>
int main(void)
{
    uint8_t value=0;
    value |=(1U<<3); //1U là unsigned 32 bit
    printf("%u\n",(unsigned)value); // bật bit 3

    value &= ~(1U<<3); // tắt bit 3
    printf("%u\n",(unsigned)value);

    value ^= (1U<<2); // Đảo bit 2 bằng xor
    printf("%u\n",(unsigned)value);

    value=0b00001000;
    if((value&(1U<<3))!=0U)
    {
        printf("Bit 3 is ON\n");
    }
    else 
    {
        printf("Bit 3 is OFF\n");
    }
    
    /*
    value |=  (1U << n);       // bật bit n
    value &= ~(1U << n);       // tắt bit n
    value ^=  (1U << n);       // đảo bit n
    value &   (1U << n);       // kiểm tra bit n
    */
}