#include<stdio.h>
#define N 99999
int main(void)
{
	short arr[N];
	int j;
	char a, b;
	arr[0] = 1;
	for (j = 0; j < arr[0] + 1; j++)
	{
		scanf("%hd", &arr[j]);
	}
	for (j = 1; j < arr[0] + 1; j++)
	{
		a = (arr[j] & 0xff00) >> 8;
		b = arr[j] & 0x00ff;
		printf("%c,%c\n",a,b);
	}
	return 0;
}