#include <stdio.h>
#define M 10
#define N 3
int main(void)
{
    int a[M] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int b[M];
    int i, j = 0, k, q = 0;
    for (i = 0; i < M; i++)
    {
        for (k = 0; j <= M; j++)
        {
            if (j > M - 1)
                j = 0;
            if (a[j] == 0)
                continue;
            k++;
            if (k % N == 0)
            {
                a[j] = 0;
                break;
            }
        }
        b[q++] = j + 1;
    }
    for (i = 0; i < M; i++) /* 按次序输出出圈人的编号 */
        printf("%6d", b[i]);
    printf("\n");
    return 0;
}