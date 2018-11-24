#include <stdio.h>
int main(void)
{
    int num,move,i,r,t;
    scanf("%d %d",&num,&move);
    for(i=0,t=num;t!=0;i++)
        t/=2;
    r=(num>>move%32)|(num<<(-(move%32)+32));
    printf("%d\n",r);
    return 0;
}
