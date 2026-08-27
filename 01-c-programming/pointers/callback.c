#include <stdio.h>
#include <stdint.h>

typedef void (*ButtonCallback)(uint8_t pin);

// Các hàm sẽ được đăng ký làm callback
static void turn_on_led(uint8_t pin)
{
    printf("Pin %u: bat LED\n",(unsigned)pin);
}
static void send_warning(uint8_t pin)
{
    printf("Pin %u: gui canh bao\n",(unsigned)pin);
}

// Hàm nhận callback và gọi lại khi nút được nhấn
static void process_button(uint8_t pin,ButtonCallback callback)
{
    printf("Nut tai pin %u da duoc nhan\n",(unsigned)pin);
    if(callback!=NULL)
    {
        callback(pin);
    }
}
int main(void)
{
    // Lần này chọn hành động bật LED
    process_button(5U,turn_on_led);

    // Lần sau chọn hành động gửi cảnh báo
    process_button(6U,send_warning);

    // Không có callback
    process_button(7U,NULL);
}