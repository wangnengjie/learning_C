#include <stdio.h>
int main(void)
{
    int i;
    unsigned long k,mask;
    unsigned short arr[4];
    scanf("%ld",&k);
    mask=0x000000ff;
    for(i=0;i<4;i++)
    {
        arr[i]=k&mask;
        k=k>>8;
    }
    printf("%hu.%hu.%hu.%hu",arr[0],arr[1],arr[2],arr[3]);
    return 0;
}