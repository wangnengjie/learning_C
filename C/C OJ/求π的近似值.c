#include<stdio.h>
int main(void)
{
	double i,j=-1,s=0;
	for (i = 1; i-2<10000; i+=2)
	{
		if (j == -1)
			j = 1;
		else
			j = -1;
		s += j * (1 / i);
	}
	printf("%.9lf", s * 4);
	return 0;
}