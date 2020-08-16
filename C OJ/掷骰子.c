#include <stdio.h>
int point(unsigned int n);
int main(void)
{
	unsigned int i, n;
	unsigned int first, second;
	unsigned int plus;
	unsigned int k;
	scanf("%u", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%u %u", &first, &second);
		plus = point(first) + point(second);
		if (plus == 7 || plus == 11)
			printf("success!\n");
		else if (plus == 2 || plus == 3 || plus == 12)
			printf("fail!\n");
		else
		{
			int pre = plus;
			for (k = 2; 1; k++)
			{
				first = first + k - 1;
				second = second + k - 1;
				plus = point(first) + point(second);
				if (plus == 7)
				{
					printf("fail!\n");
					break;
				}
				else if (plus == pre)
				{
					printf("success!\n");
					break;
				}
			}
		}
	}
	return 0;
}
int point(unsigned int n)
{
	int sum = 0;
	for (; n > 0;)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum % 6 + 1;
}
