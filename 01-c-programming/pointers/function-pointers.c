#include <stdio.h>
static int add(int a, int b )
{
    return a+b;
}

static int subtract(int a, int b)
{
    return a-b;
}

int main(void)
{
    int(*operation)(int,int); // con trỏ hàm với tham số int int tên operation
    operation=add;
    printf("10+5=%d\n",operation(10,5));

    operation=subtract;
    printf("10-5=%d\n",operation(10,5));
    return 0;
}
