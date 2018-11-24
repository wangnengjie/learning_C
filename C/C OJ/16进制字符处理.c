#include<stdio.h>
#define N 99999
int main(void)
{
	char arr[N];
	int j,i;
	scanf("%d", &i);
	while (getchar() != '\n')
		continue;
	for (j = 0; j < i; j++)
	{
		scanf("%c", &arr[j]);
		while (getchar()!= '\n')
			continue;
		if (arr[j] <= '9'&&arr[j] >= '0')
			printf("%hd\n", arr[j] - '0');
		else if (arr[j] <= 'f'&&arr[j] >= 'a')
			printf("%hd\n", arr[j] - 'a' + 10);
		else if (arr[j] <= 'F'&&arr[j] >= 'A')
			printf("%hd\n", arr[j] - 'A' + 10);
		else
			printf("%hd\n", arr[j]);
	}
	return 0;
}