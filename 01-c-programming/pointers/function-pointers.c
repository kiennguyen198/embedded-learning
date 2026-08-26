#include <stdio.h>
#define CNT 3
static int add(int a, int b )
{
    return a+b;
}

static int subtract(int a, int b)
{
    return a-b;
}
void reg1()
{
    printf("reg1\n");
}
void reg2()
{
    printf("reg2\n");
}
void reg3()
{
    printf("reg3\n");
}


int main(void)
{
    int(*operation)(int,int); // con trỏ hàm với tham số int int tên operation
    operation=add;
    printf("10+5=%d\n",operation(10,5));

    operation=subtract;
    printf("10-5=%d\n",operation(10,5));
    
    void(*mFunction[CNT])()={reg1,reg2,reg3};
    for (int i=0;i<CNT;i++)
    {
        mFunction[i]();
    }
    return 0;
}
