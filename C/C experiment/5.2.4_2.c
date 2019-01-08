#include <stdio.h>
int main(void)
{
    char arr[sizeof(int) * 8 + 1];
    int num, i, ch;
    scanf("%d", &num);
    int mask = 0x1;
    for (i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        ch = num & mask;
        arr[i] = ch + 48;
        num >>= 1;
    }
    arr[sizeof(int) * 8] = '\0';
    printf("%s", arr);
    return 0;
}