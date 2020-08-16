#include <stdio.h>
int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\na=%d b=%d",a,b);
    return 0;
}