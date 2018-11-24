#include<stdio.h>
int main(void)
{
	int N;
	int i;
	char ch;
	int isspace = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		while ((ch = getchar()) != '\n')
		{
			if (ch == ' '&&isspace != 1)
			{
				isspace = 1;
				putchar(ch);
				continue;
			}
			else if (ch == ' '&& isspace = 1)
				continue;
			else
			{
				isspace = 0;
				putchar(ch);
			}
		}
	}
	return 0;
}
