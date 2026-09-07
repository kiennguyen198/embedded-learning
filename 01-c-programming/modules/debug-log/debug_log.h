#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

/*
 * Nếu build system chưa truyền MCU_DEBUG từ bên ngoài,
 * mặc định bật log để dễ quan sát khi học.
 *
 * Có thể ghi đè lúc build:
 *   gcc -DMCU_DEBUG=0 main.c -o debug-off.exe
 */
#ifndef MCU_DEBUG
#define MCU_DEBUG 1
#endif  

#if MCU_DEBUG

/* printf() chỉ cần được khai báo khi log đang bật. */
#include <stdio.h>

/*
 * ... nhận số lượng đối số tùy ý.
 * __VA_ARGS__ chuyển toàn bộ đối số sang printf().
 *
 * Ví dụ:
 *   DEBUG_LOG("Value = %d\n", value);
 * trở thành:
 *   printf("Value = %d\n", value);
 */
#define DEBUG_LOG(...) ((void)printf(__VA_ARGS__)) // không dùng hàm printf mà dùng hàm DEBUG_LOG để print

#else

/*
 * Khi MCU_DEBUG bằng 0, mỗi lệnh DEBUG_LOG(...)
 * được thay bằng một biểu thức không làm gì.
 */
#define DEBUG_LOG(...) ((void)0)

#endif /* MCU_DEBUG */

#endif /* DEBUG_LOG_H */
