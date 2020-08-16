#include <stdio.h>
#define N 5
#define M 3
void averageStudent(double (*grades)[M]);
void averageSubject(double (*grades)[M]);
void belowAverage(double (*grades)[M], double average, int classname);
void aboveNinty(double (*grades)[M]);
int main(void)
{
    int i, j;
    double grades[N][M];
    for (i = 0; i < N; i++)
    {
        printf("student%d and %d classes\n", i + 1, M);
        for (j = 0; j < M; j++)
            scanf("%lf", *(grades + i) + j);
    }
    averageStudent(grades);
    averageSubject(grades);
    aboveNinty(grades);
    return 0;
}

void averageStudent(double (*grades)[M])
{
    int i, j;
    double sum;
    for (i = 0; i < N; i++)
    {
        sum = 0;
        for (j = 0; j < M; j++)
        {
            sum += *(*(grades + i) + j);
        }
        printf("%d average : %lf\n", i + 1, sum / M);
    }
}

void averageSubject(double (*grades)[M])
{
    int i, j;
    double average[M], sum;
    for (i = 0; i < M; i++)
    {
        sum = 0;
        for (j = 0; j < N; j++)
        {
            sum += *(*(grades + j) + i);
        }
        printf("%d class : %lf\n", i + 1, sum / N);
        *(average + i) = sum / N;
    }
    for (i = 0; i < M; i++)
        belowAverage(grades, *(average + i), i);
}

void belowAverage(double (*grades)[M], double average, int classname)
{
    int i, count;
    for (i = 0, count = 0; i < N; i++)
    {
        if (*(*(grades + i) + classname) < average)
            count++;
    }
    printf("%d below average : %d\n", classname + 1, count);
}

void aboveNinty(double (*grades)[M])
{
    int i, j, belowSix, aboveNine;
    for (i = 0; i < M; i++)
    {
        belowSix = 0;
        aboveNine = 0;
        for (j = 0; j < N; j++)
        {
            if (*(*(grades + j) + i) >= 90.0)
                aboveNine++;
            else if (*(*(grades + j) + i) < 60.0)
                belowSix++;
        }
        printf("%d class above 90 : %d below 60 : %d\n", i + 1, aboveNine, belowSix);
    }
}