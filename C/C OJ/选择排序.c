#include<stdio.h>
#define N 20
void sort(int arr[], int n);
int main(void)
{
	int arr[N];
	int n, i = 0;
	scanf("%d", &n);
	while (i < n)
		scanf("%d", &arr[i++]);
	sort(arr, n);
	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}
	return 0;
}
void sort(int arr[], int n)
{
	
	for (; n > 0; n--) 
	{
		int temp, i, max = 0;
		temp = arr[0];
		for (i = 0; i < n; i++)
			if (arr[i] > temp)
			{
				temp = arr[i];
				max = i;
			}
		arr[max] = arr[n - 1];
		arr[n - 1] = temp;
	}
	return;
}