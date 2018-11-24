#include<stdio.h>
#define N 99999
int main(void)
{
	unsigned short arr[N];
	int i, j;
	arr[0] = 1;
	for (j = 0; j < arr[0] + 1; j++)
	{
		scanf("%hu", &arr[j]);
	}
	for (j = 1; j < arr[0] + 1;j++)
	{
		i = (arr[j] & 0xF000) >> 12 | (arr[j] & 0x000F) << 12|(arr[j]&0x0FF0);
		printf("%hu\n", i);
	}
	return 0;
}
