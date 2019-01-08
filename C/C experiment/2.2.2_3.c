#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, s, sum = 1;
    printf("Please enter s:");
    scanf("%d", &s);
    for (n = 1; sum < s; n++)
        sum *= n;
    printf("n=%d", n - 1);
    return 0;
}