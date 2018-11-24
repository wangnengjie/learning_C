#include<stdio.h>
#include<math.h>
int main(void)
{
	int i,N;
	float a, b, c,area,s;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%f %f %f", &a, &b, &c);
		s = (a + b + c) / 2;
		area = s * (s - a)*(s - b)*(s - c);
		area = sqrt(area);
		printf("area=%f\n", area);
	}
	return 0;
}