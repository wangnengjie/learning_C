#include<stdio.h>
int main(void)
{
	double money;
	while (scanf("%lf",&money)&&money)
	{
		if (money <= 1000)
			printf("%lf", 0);
		else if (money <= 2000)
			printf("%lf", (money-1000)*0.05);
		else if (money <= 3000)
			printf("%lf", 50+(money-2000)*0.1);
		else if (money <= 4000)
			printf("%lf", 50+100+(money-3000)*0.15);
		else if (money <= 5000)
			printf("%lf", 50+100+150+(money-4000)*0.2);
		else
			printf("%lf", 50+100+150+200+(money-5000)*0.25);
		putchar('\n');
	}
	return 0;
}