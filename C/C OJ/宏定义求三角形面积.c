#include<stdio.h>
#include<math.h>
#define halfcircumference(a,b,c) ((a)+(b)+(c))/2
#define AREA(s,a,b,c) sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c)))
int main(void)
{
	int a, b, c, s;
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		s = halfcircumference(a, b, c);
		printf("%d %lf\n", s, AREA(s, a, b, c));
	}
	return 0;
}
