#include<stdio.h>
double callif(double num1, double num2, char k);
double callswitch(double num1, double num2, char k);
int main(void)
{
	char ch;
	char k;
	double num1, num2;
	while ((ch=getchar())!=EOF)
	{
		scanf("%lf %lf %c", &num1, &num2, &k);
		switch (ch)
		{
		case '0':
			printf("After if-else processing,the result is : %.2lf\n", callif(num1,num2,k));
			break;
		case '1':
			printf("After switch processing,the result is : %.2lf\n", callswitch(num1,num2,k));
			break;
		case '2':
			printf("After if-else processing,the result is : %.2lf\n", callif(num1,num2,k));
			printf("After switch processing,the result is : %.2lf\n", callswitch(num1,num2,k));
			break;
		default:
			break;
		}
		putchar('\n');
		while (getchar() != '\n')
			continue;
	}
	return 0;
}
double callif(double num1, double num2, char k)
{
	double result;
	if (k == '+')
		result = num1 + num2;
	else if (k == '-')
		result = num1 - num2;
	else if (k == '*')
		result = num1 * num2;
	else if (k == '/')
		result = num1 / num2;
	return result;
}

double callswitch(double num1, double num2, char k)
{
	double result;
	switch (k)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	default:
		break;
	}
	return result;
}