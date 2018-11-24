#include<stdio.h>
int count(char *ch);
int main(void)
{
	char s[9999];
	int n,i;
	scanf("%d", &n);
	while (getchar() != '\n')
		continue;
	for (i = 0; i < n; i++)
	{
		fgets(s, 9999, stdin);
		printf("%d\n", count(s));
	}
	return 0;
}
int count(char *ch)
{
	if (*ch != '\n')
		return count(++ch) + 1;
	else
		return 0;
}