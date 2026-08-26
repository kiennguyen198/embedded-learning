#include <stdio.h>
#include <stdint.h>
#include <stddef.h> // size_t

static void print_buffer(const uint8_t *buffer, size_t length)
{
    for(size_t i=0U;i<length;i++)
    {
        printf("%u ",(unsigned)buffer[i]);
    }
    printf("\n");
}

int main(void)
{
    uint8_t data[]={10U,20U,30U,40U};
    uint8_t *ptr=data;

    // Hai cách truy cập tương đương
    printf("data[0]=%u\n",(unsigned)data[0]);
    printf("*ptr=%u\n",(unsigned)*ptr);

    // Dịch sang phần tử kế tiếp
    ptr++;
    printf("*ptr=%u\n",(unsigned)*ptr);

    // array[i] tương đương *(array + i)
    printf("data[2] = %u\n", (unsigned)data[2]);
    printf("*(data + 2) = %u\n", (unsigned)*(data + 2));

    // Sửa phần tử mảng qua con trỏ
    *(data + 3) = 99U;

    size_t length = sizeof(data) / sizeof(data[0]);
    print_buffer(data, length);

    return 0;

}