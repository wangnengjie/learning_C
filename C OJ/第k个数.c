#include<stdio.h>
int main(void)
{
	unsigned long long n, k;
	unsigned long long a,b;
	while (scanf("%llu %llu", &n, &k) != EOF)
	{
		for (a = 1, b = 1; a < k; a++)
			b *= 10;
		if (n / b == 0)
		{
			printf("%d\n", -1);
		}
		else
		{
			printf("%d\n", (n % b)/b);
		}
	}
	return 0;
}