#include <stdio.h>
#define M 3
#define N 4
void zhuan(int a[][N], int n);
int main(void)
{
    int arr[M][N];
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("第%d行，第%d列：", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d", arr[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    zhuan(arr, M);
    return 0;
}
void zhuan(int a[][N], int n)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%4d", a[j][i]);
        }
        putchar('\n');
    }
}