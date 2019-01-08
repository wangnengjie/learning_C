#include <stdio.h>
int main(void)
{
    char ch;
    ch = getchar();
    if (ch >= 'a' && ch <= 'z')
        putchar(ch);
    else
        putchar(ch + 32);
    return 0;
}