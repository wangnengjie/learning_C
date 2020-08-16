#include <stdio.h>
struct bits
{
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
};
void f0(unsigned int b)
{
    printf("the function 0 is called, value: %d!\n", b);
}
void f1(unsigned int b)
{
    printf("the function 1 is called, value: %d!\n", b);
}
void f2(unsigned int b)
{
    printf("the function 2 is called, value: %d!\n", b);
}
void f3(unsigned int b)
{
    printf("the function 3 is called, value: %d!\n", b);
}
void f4(unsigned int b)
{
    printf("the function 4 is called, value: %d!\n", b);
}
void f5(unsigned int b)
{
    printf("the function 5 is called, value: %d!\n", b);
}
void f6(unsigned int b)
{
    printf("the function 6 is called, value: %d!\n", b);
}
void f7(unsigned int b)
{
    printf("the function 7 is called, value: %d!\n", b);
}
int main(void)
{
    union {
        unsigned int num;
        struct bits b;
    } bit;
    void (*p_fun[8])(unsigned int) = {f0, f1, f2, f3, f4, f5, f6, f7};
    scanf("%d", &bit.num);
    if (bit.b.bit0)
        p_fun[0](bit.b.bit0);
    if (bit.b.bit1)
        p_fun[1](bit.b.bit1);
    if (bit.b.bit2)
        p_fun[2](bit.b.bit2);
    if (bit.b.bit3)
        p_fun[3](bit.b.bit3);
    if (bit.b.bit4)
        p_fun[4](bit.b.bit4);
    if (bit.b.bit5)
        p_fun[5](bit.b.bit5);
    if (bit.b.bit6)
        p_fun[6](bit.b.bit6);
    if (bit.b.bit7)
        p_fun[7](bit.b.bit7);
    return 0;
}