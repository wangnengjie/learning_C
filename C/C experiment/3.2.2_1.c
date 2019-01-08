#include "stdio.h"
long sum_fac(int n);
void main(void)
{
    int k;
    for (k = 1; k < 6; k++)
        printf("k=%d\tthe sum is %ld\n", k, sum_fac(k));
}
long sum_fac(int n)
{
    static long s = 0;
    int i;
    long fac;
    for (i = 1, fac = 1; i <= n; i++)
        fac *= i;
    s += fac;

    return s;
}