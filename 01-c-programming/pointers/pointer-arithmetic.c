#include <stdio.h>
#include <stdint.h>

uint8_t arr[5]={1,2,3,4,5};

uint8_t *ptr8;
uint32_t *ptr32;

int main()
{
    ptr8=&arr[0];
    ptr32=(uint32_t*)&arr[0];

    ptr8++;
    ptr32++; // tăng 32 bit
    // nếu muốn tăng ít hơn thì dùng lệnh ptr32+=sizeof(uint8_t)
    printf("ptr8: %d\n",*ptr8); //2
    printf("ptr32: %d\n",ptr32); //5

}