#include <stdio.h>
#include <string.h>
void sort(int grade[], char name[][40], int n);
int findgrade(int grade[], int num, int begin, int end);
int k = -1, l = 0;
int main(void)
{
    int grade[20];
    char name[20][40];
    int i = 0, n, find, j;
    printf("how many:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("name:");
        scanf("%s", name[i]);
        printf("grades:");
        scanf("%d", &grade[i]);
    }
    sort(grade, name, n);
    for (i = 0; i < n; i++)
        printf("%6s : %6d\n", name[i], grade[i]);
    while (scanf("%d", &find) == 1)
    {
        j = findgrade(grade, find, 0, n);
        if (j == -1)
            printf("not found!\n");
        else
            printf("%-6s : %-6d\n", name[j], grade[j]);
        k = -1;
        l = 0;
    }
    return 0;
}
void sort(int grade[], char name[][40], int n)
{
    if (n <= 0)
        return;
    int temp, i, min = 0;
    char tempname[40];
    strcpy(tempname, name[0]);
    temp = grade[0];
    for (i = 0; i < n; i++)
        if (grade[i] < temp)
        {
            temp = grade[i];
            strcpy(tempname, name[i]);
            min = i;
        }
    grade[min] = grade[n - 1];
    grade[n - 1] = temp;
    strcpy(name[min], name[n - 1]);
    strcpy(name[n - 1], tempname);
    sort(grade, name, n - 1);
}
int findgrade(int grade[], int num, int begin, int end)
{
    if (begin == end)
        l++;
    if (begin == end && l > 1)
        return k;
    if (begin > end)
        return k;
    int n = (begin + end) / 2;
    int x = grade[n];
    if (x == num)
    {
        k = n;
        return k;
    }
    else if (num > x)
    {
        findgrade(grade, num, begin, n);
    }
    else if (num < x)
    {
        findgrade(grade, num, n + 1, end);
    }
}