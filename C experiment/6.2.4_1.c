#include <stdio.h>
int main(void)
{
    long num;
    int mask = 0x1;
    int i;
    char arr[33];
    scanf("%ld", &num);
    for (i = 31; i >= 0; i--)
        arr[i] = ((num >> (31 - i)) & mask) + 48;
    arr[32] = '\0';
    for (i = 0; i < 32; i++)
    {
        putchar(arr[i]);
        if (!((i + 1) % 4))
            putchar(' ');
        if (!((i + 1) % 8))
            putchar('\n');
    }
    return 0;
}