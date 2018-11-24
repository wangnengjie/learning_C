#include<stdio.h>
int main(void)
{
	int i, p, j, s, a;
	int arr[11];
	scanf("%d", &j);
	for (p = 0, s = 0, a = 0; p < j; p++,s=0,a=0)
	{
		scanf("%d %d %d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9], &arr[10]);
		if (arr[0] == 0)
		{
			for (i = 1; i <= 10; i++)
			{
				if (arr[i] >= 0)
				{
					s += arr[i];
					a++;
				}
				else
					continue;
			}
			if(a>0)
				printf("In \"continue\" way,numbers=%d,average=%f\n", a, (double)s / a);
		}
		else if (arr[0] == 1)
		{
			for (i = 1; i <= 10; i++)
			{
				if (arr[i] >= 0)
				{
					s += arr[i];
					a++;
				}
			}
			if (a>0)
				printf("In \"no continue\" way,numbers=%d,average=%f\n", a, (double)s / a);
		}
	}
	return 0;
}