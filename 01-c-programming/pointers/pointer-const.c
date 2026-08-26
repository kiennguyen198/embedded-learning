#include <stdio.h>
#include <stdint.h>
int main(void)
{
    uint8_t a=10U;
    uint8_t b=20U;

    // 1: Con trỏ tới dữ liệu const 
    const uint8_t *ptr_to_const=&a; // con trỏ trỏ tới const 
    // Đổi nơi trỏ được nhưng không đổi được dữ liệu qua con trỏ
    // Giảm quyền con trỏ không cho sửa a qua con trỏ (nhưng bản thân a vẫn thay đổi được)

    printf("ptr_to_const -> %u\n",(unsigned)*ptr_to_const);

    ptr_to_const=&b; // được đổi từ a sang b
    printf("ptr_to_const -> %u\n",(unsigned)*ptr_to_const);

    // 2: Con trỏ const
    // Không đổi được nơi trỏ, nhưng sửa được dữ liệu
    uint8_t *const const_ptr =&a;
    *const_ptr=30U;
    printf("a=%u\n",(unsigned)a);

    // 3: Con trỏ const trỏ tới dữ liệu const
    // Không đổi nơi trỏ được và không sửa dữ liệu được
    const uint8_t *const const_ptr_to_const=&b;
    printf("const_ptr_to_const -> %u\n",(unsigned)*const_ptr_to_const);
    // const_ptr_to_const = &a;  // Lỗi: không được đổi nơi trỏ
    // *const_ptr_to_const = 40U; // Lỗi: không được sửa dữ liệu
}