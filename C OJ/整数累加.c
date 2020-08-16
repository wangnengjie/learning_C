#include<stdio.h>
#define N 10
int main(void)
{
    int arr[N];
    int s,i,j;
    arr[0]=1;
    for(j=0; j<arr[0]+1; j++)
    {
        scanf("%d",&arr[j]);
    }
    for(j=1; j<arr[0]+1; j++)
    {
        for(i=1,s=0; i<=arr[j]; i++)
            s+=i;
        printf("%d\n",s);
    }
    return 0;
}
