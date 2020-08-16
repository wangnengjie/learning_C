#include<stdio.h>
#define CHANGE(c) ((c)%2)
int main(void)
{
	int n, i;
	char c;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		c = getchar();
		if (CHANGE(c)) 
		{
			if (c >= 'a'&&c <= 'z')
				putchar(c - 32);
			else if (c >= 'A'&&c <= 'Z')
				putchar(c + 32);
			else
				putchar(c);
			while ((c = getchar()) != '\n')
			{
				if (c >= 'a'&&c <= 'z')
					putchar(c - 32);
				else if (c >= 'A'&&c <= 'Z')
					putchar(c + 32);
				else
					putchar(c);
			}
			putchar('\n');
		}
		else 
		{
			putchar(c);
			while ((c = getchar()) != '\n')
				putchar(c);
			putchar(c);
		}
	}
	return 0;
}