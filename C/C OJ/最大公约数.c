#include <stdio.h>
int find(int a, int b);
int main(void)
{
	int a, b;
	while (scanf("%d %d", &a, &b) && a != 0) 
	{
		printf("%d\n", find(a, b));
	}
	return 0;
}
int find(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	find(b, a % b);
}
