#include <stdio.h>
int main(void)
{
    unsigned short x, m, n;
    scanf("%hu %hu %hu", &x, &m, &n);
    x = x >> m;
    x = x << 16 - n;
    printf("%hu", x);
    return 0;
}