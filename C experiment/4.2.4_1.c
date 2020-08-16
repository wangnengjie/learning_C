#include <stdio.h>
#include <math.h>
#define halfcircumference(a, b, c) ((a) + (b) + (c)) / 2
#define AREA(s, a, b, c) sqrt((s) * ((s) - (a)) * ((s) - (b)) * ((s) - (c)))
int main(void)
{
    double a, b, c, s;
    scanf("%lf %lf %lf", &a, &b, &c);
    s = halfcircumference(a, b, c);
    printf("The area is=%lf", AREA(s, a, b, c));
    return 0;
}