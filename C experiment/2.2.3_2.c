#include <stdio.h>
int main(void)
{
    int num, i, r, j;
    scanf("%d", &num);
    for (i = 1; num / i > 0; i *= 10)
    {
        printf("%d", (num / i) % 10);
    }
    return 0;
}