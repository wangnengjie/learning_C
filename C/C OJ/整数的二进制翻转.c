#include <stdio.h>
#include <math.h>
void print(int x);
int main(void)
{
    int x,p,n;
    int i;
    unsigned int mask=0;
    scanf("%d %d %d",&x,&p,&n);
    print(x);
    for(i=p;i<n+p;i++)
        mask+=pow(2,i%32);
    print(x^mask);
    return 0;
}
void print(int x)
{
    int mask=1<<31;
    int i;
    for (i=1;i<=32;i++)
    {
        putchar(x&mask?'1':'0');
        x<<=1;
        if(i%8==0&&i!=32)
            putchar(' ');
    }
    putchar('\n');
}
