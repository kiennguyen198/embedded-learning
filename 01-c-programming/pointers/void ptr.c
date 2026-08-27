// void * là con trỏ có thể giữ địa chỉ của bất kỳ dữ liệu nào
/*Một vùng dữ liệu con trỏ void đang duwx địa chỉ, nhưng không biết kiểu 
=> ép về con trỏ đúng kiểu để đọc/ghi dữ liệu
Ví dụ: 
uint16_t number=10000;
void *ptr=&number;  // ptr giữ địa chỉ chưa biết kiểu
uint16 *typed=ptr;  // typed diễn giải địa chỉ đó là uint16_t
*/
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

static void print_value(const void *data, uint8_t size)
{
    if(size==sizeof(uint8_t))
    {
        const uint8_t *value=data;
        printf("uint8_t: %u\n", (unsigned)*value);
    }
    else if (size==sizeof(uint16_t))
    {
        const uint16_t *value=data;
        printf("uint16_t: %u\n",(unsigned)*value);
    }
}

static void set_value(void *data,uint8_t size)
{
    if(size==sizeof(uint8_t))
    {
        uint8_t *value=data;
        *value=0x12U;
    }
    else if(size==sizeof(uint16_t))
    {
        uint16_t *value=data;
        *value=0x1234U;
    }
}
int main(void)
{
    uint8_t byte_value=0;
    uint16_t word_value=0;

     // Mỗi hàm xử lý được 2 kiểu dữ liệu uint8 và uint16

    set_value(&byte_value,sizeof(byte_value));
    set_value(&word_value,sizeof(word_value));

    print_value(&byte_value,sizeof(byte_value));
    print_value(&word_value,sizeof(word_value));
}