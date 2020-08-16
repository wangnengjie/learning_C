#include<stdio.h>
void mycpy(char s[], char t[], int n);
int main(void)
{
	char s[9999], t[9999];
	int N,n,i;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++)
	{
		fgets(t, 9999, stdin);
		scanf("%d", &n);
		getchar();
		mycpy(s, t, n);
		printf("%s\n", s);
	}
	return 0;
}
void mycpy(char s[], char t[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		s[i] = t[i];
	s[i] = '\0';
}