#include<stdio.h>
int main(void)
{
	int arr[99999];
	int su[9999];
	int i,j,f,m,n,a,b=0;
	scanf("%d", &i);
	for (j = 0; j < i; j++)
		scanf("%d", &arr[j]);
	for (j = 0; j < i; j++)
	{
		a = 0;
		for (f = 2; f <= arr[j]; f++)
		{
			for (m = 1, n = 0; m*m <= f; m++)
				if (f%m == 0)
					n++;
			if (n == 1)
			{
				su[a] = f;
				a++;
			}
		}
		for (m = 0,b=0; m < a - 1; m++)
		{
			if (b == 1)
				break;
			for (n = m; n < a; n++)
				if (arr[j] == su[m] + su[n])
				{
					printf("%d=%d+%d\n", arr[j], su[m], su[n]);
					b = 1;
					break;
				}
		}
	}
	return 0;
}