#include "debug_log.h"

int main(void)
{
    int temperature = 30;

    /* Các dòng này chỉ in khi MCU_DEBUG khác 0. */
    DEBUG_LOG("Program started\n");
    DEBUG_LOG("Temperature = %d C\n", temperature);

    /*
     * Không đặt phép tính quan trọng trong DEBUG_LOG().
     * Khi tắt log, toàn bộ đối số cũng không được thực thi.
     */
    temperature++;
    DEBUG_LOG("New temperature = %d C\n", temperature);

    return 0;
}
