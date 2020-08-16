#include<stdio.h>
#include<ctype.h>
int main(void)
{
	int n,i,num=0;
	char ch;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++,num=0)
	{
		getchar();
		getchar();
		while ((ch=getchar())!='\n')
		{
			if (ch >= '0'&&ch <= '9')
				num = num * 16 + (ch - '0');
			else if (ch >= 'a'&&ch <= 'z')
				num = num * 16 + 10 + (ch - 'a');
			else if (ch >= 'A'&&ch <= 'Z')
				num = num * 16 + 10 + (ch - 'A');
		}
		printf("%d\n", num);
	}
	return 0;
}