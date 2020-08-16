#include<stdio.h>
int main(void)
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int mon2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int n, i, year, month, day, days, j;
	scanf("%d", &n);
	while (getchar() != '\n')
		continue;
	for (i = 0; i < n; i++)
	{
		days = 0;
		scanf("%d %d %d", &year, &month, &day);
		if (!(year % 4) && year % 100 || !(year % 400))
		{
			for (j = 0; j < month - 1; j++)
				days += mon2[j];
			days += day;
		}
		else
		{
			for (j = 0; j < month - 1; j++)
				days += mon[j];
			days += day;
		}
		printf("%d\n", days);
	}
	return 0;
}