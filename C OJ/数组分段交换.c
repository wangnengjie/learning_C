#include<stdio.h>
#define N 60
void swap(int arr[], int n,int k);
int main(void)
{
	int n, k,i;
	int u[N];
	while (scanf("%d %d", &n, &k) != EOF)
	{
		i = 0;
		while (i < n)
			scanf("%d", &u[i++]);
		swap(u, n, k);
		for (i = 0; i < n - 1; i++)
			printf("%d ", u[i]);
		printf("%d\n", u[n - 1]);
	}
	return 0;
}
void swap(int arr[], int n, int k)
{
	int temp[N];
	int i;
	for (i = 0; i < n - k; i++)
		temp[i] = arr[k + i];
	for (; i < n; i++)
		temp[i] = arr[i - n + k ];
	for (i = 0; i < n; i++)
		arr[i] = temp[i];
	return ;
}