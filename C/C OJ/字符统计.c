#include<stdio.h>
int main(void)
{
	char ch;
	int num[10], alpha[26], i, j, m, other = 0;
	for (i = 0; i < 10; i++)
		num[i] = 0;
	for (i = 0; i < 26; i++)
		alpha[i] = 0;
	while ((ch = getchar()) != EOF)
	{
		i = ch - '0';
		j = ch - 'a';
		m = ch - 'A';
		if (i >= 0 && i <= 9)
			num[i]++;
		else if (j >= 0 && j <= 25)
			alpha[j]++;
		else if (m >= 0 && m <= 25)
			alpha[m]++;
		else
			other++;
	}
	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			printf("%d:%d", i, num[i]);
		else
			printf(" %d:%d", i, num[i]);
	}
	putchar('\n');
	for (i = 0; i < 26; i++)
	{
		if (i == 0)
			printf("%c:%d", 'a' + i, alpha[i]);
		else
			printf(" %c:%d", 'a' + i, alpha[i]);
	}
	putchar('\n');
	printf("other:%d\n", other);
	return 0;
}