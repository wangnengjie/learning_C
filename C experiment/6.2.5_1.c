#include <stdio.h>
#define N 21
#define M 11
int countFloat(char float1[], char float2[], char resultfloat[]);
void countInt(char int1[], char int2[], char resultInt[], int addOne);
int main(void)
{
    char int1[N], int2[N], float1[M], float2[M];
    int resultInt[N + 1], resultfloat[M];
    int i = 0;
    char ch;
    while ((ch = getchar()) != '.')
    {
        int1[i++] = ch;
    }
    int1[i] = '\0';
    i = 0;
    while ((ch = getchar()) != '\n')
    {
        float1[i++] = ch;
    }
    float1[i] = '\0';
    i = 0;
    while ((ch = getchar()) != '.')
    {
        int2[i++] = ch;
    }
    int2[i] = '\0';
    i = 0;
    while ((ch = getchar()) != '\n')
    {
        float2[i++] = ch;
    }
    float2[i] = '\0';
    countInt(int1, int2, resultInt, countFloat(float1, float2, resultfloat));
    printf("%s.%s", resultInt, resultfloat);
    return 0;
}
int countFloat(char float1[], char float2[], char resultfloat[])
{
    int i = 0, j = 0;
    int flag = 0;
    while (float1[i++])
        ;
    while (float2[j++])
        ;
    i -= 2;
    j -= 2;
    if (i > j)
    {
        resultfloat[i + 1] = '\0';
        while (i > j)
        {
            resultfloat[i] = float1[i];
            i--;
        }
    }
    else if (j > i)
    {
        resultfloat[j + 1] = '\0';
        while (i < j)
        {
            resultfloat[j] = float2[j];
            j--;
        }
    }
    else
    {
        resultfloat[i + 1] = '\0';
    }
    for (; i >= 0 && j >= 0; i--, j--)
    {
        flag = float1[i] + float2[j] - '0' - '0' + flag;
        if (flag >= 10)
        {
            resultfloat[i] = flag % 10 + '0';
            flag = 1;
        }
        else
        {
            resultfloat[i] = flag + '0';
            flag = 0;
        }
    }
    return flag;
}

void countInt(char int1[], char int2[], char resultInt[], int addOne)
{
    int i = 0, j = 0;
    int flag = addOne;
    while (int1[i++])
        ;
    while (int2[j++])
        ;
    i -= 2;
    j -= 2;
    resultInt[i + 2] = '\0';
    for (; i >= 0 || j >= 0; i--, j--)
    {
        if (i < 0)
        {
            flag = int2[j] - '0' + flag;
        }
        else if (j < 0)
        {
            flag = int1[i] - '0' + flag;
        }
        else
        {
            flag = int1[i] + int2[j] - '0' - '0' + flag;
        }
        if (flag >= 10)
        {
            resultInt[i + 1] = flag % 10 + '0';
            flag = 1;
        }
        else
        {
            resultInt[i + 1] = flag + '0';
            flag = 0;
        }
    }
    if (flag == 1)
    {
        resultInt[0] = '1';
    }
    else
    {
        resultInt[0] = ' ';
    }
}