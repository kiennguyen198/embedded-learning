#include <stdio.h>
#include <stdint.h>

// Không được thay đổi
static const uint16_t ADC_MAX = 4095U;

// Giữ giá trị giữa các lần gọi
static void count_calls(void)
{
    static uint8_t count = 0U;

    count++;
    printf("Count: %u\n", (unsigned)count);
}

// Sau này biến này có thể được interrupt thay đổi
static volatile uint8_t data_ready = 0U;
 // biến volatile hay dùng khi có ngắt vì chương trình hay lấy biến trực tiếp từ thanh ghi mà không đọc lại ram


int main(void)
{
    printf("ADC max: %u\n", (unsigned)ADC_MAX);

    count_calls();
    count_calls();

    printf("Data ready: %u\n", (unsigned)data_ready);

    return 0;
}