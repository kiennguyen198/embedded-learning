#include <stdio.h>
#include <stdint.h>

// struct -> mỗi thành viên có vùng nhớ riêng
// union -> tất cả thành viên cùng dùng chung một vùng nhớ

typedef union 
{
    // truy cập 8 bit một lúc
    uint8_t data;
    // truy cập riêng từng bit 
    struct
    {
        uint8_t BIT0 : 1;
        uint8_t BIT1 : 1;
        uint8_t BIT2 : 1;
        uint8_t BIT3 : 1;
        uint8_t BIT4 : 1;
        uint8_t BIT5 : 1;
        uint8_t BIT6 : 1;
        uint8_t BIT7 : 1;
    } BITS;
    
} Register8;

int main(void)
{
    Register8 reg;

    // Ban đầu toàn bộ 8 bit đều bằng 0
    reg.data = 0;

    // Bật bit số 3
    reg.BITS.BIT3 = 1;

    // 0000 1000 = 8
    printf("%u\n", (unsigned)reg.data);

    return 0;
}
