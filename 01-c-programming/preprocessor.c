#include <stdio.h>

#define PI 3.14

#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
static void print_debug(void)
{
    printf("Debug mode is enable\n");
}
#else
static void print_debug(void)
{
    printf("Debug mode is disable\n");
}
#endif

int main(void)
{
    printf("PI= %.2f\n",PI);
    print_debug();
}
