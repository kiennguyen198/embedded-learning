#include <stdio.h>
#include <stdint.h>

typedef struct
{
    int16_t temperature;
    uint16_t humidity;
    uint8_t ready;
} SensorData;

// Nhận con trỏ thường vì hàm cần sửa dữ liệu
static void update_sensor(SensorData *sensor)
{
    sensor->temperature = 275; // 27.5 độ C
    sensor->humidity = 650U;   // 65.0%
    sensor->ready = 1U;
}

// Nhận con trỏ tới const vì hàm chỉ đọc
static void print_sensor(const SensorData *sensor)
{
    printf("Temperature: %.1f C\n",
           sensor->temperature / 10.0);

    printf("Humidity: %.1f %%\n",
           sensor->humidity / 10.0);

    printf("Ready: %u\n",
           (unsigned)sensor->ready);
}

int main(void)
{
    SensorData data = {0};

    SensorData *ptr = &data;

    update_sensor(ptr);
    print_sensor(ptr);

    // Hai cách truy cập thành viên tương đương
    printf("%d\n", ptr->temperature);
    printf("%d\n", (*ptr).temperature);

    return 0;
}