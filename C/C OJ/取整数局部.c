#include <stdio.h>
int main(void)
{
	int i, j, line;
	int num = 1;
	while (scanf("%d", &line) && line != 0)
	{
		for (i = 0; i < line; i++, num = 1)
		{
			for (j = 0; j < ((line * 4 - (i + 1) * 4) / 2); j++)
				putchar(' ');
			for (j = 0; j <= i; j++)
				if (j == 0)
					printf("%d", num);
				else
				{
					num = num * (i - j + 1) / j;
					printf("%4d", num);
				}
			for (j = 0; j < (line * 4 - (i + 1) * 4) / 2; j++)
				putchar(' ');
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}