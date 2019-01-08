#include <stdio.h>
#include <stdlib.h>
#define N 5
char *del(char *p);
int main(void)
{
    char *ptr[N];
    int i;
    for (i = 0; i < N; i++)
    {
        ptr[i] = (char *)malloc(sizeof(char) * 81);
        gets(ptr[i]);
        ptr[i] = del(ptr[i]);
    }
    for (i = 0; i < N; i++)
    {
        printf("%s\n", ptr[i]);
        free(ptr[i]);
    }
    return 0;
}

char *del(char *p)
{
    int i = 0;
    int isSpace = 0;
    char *temp = (char *)malloc(sizeof(char) * 81);
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            if (isSpace == 0)
            {
                isSpace = 1;
                *(temp + i) = *p;
                i++;
                p++;
            }
            else
            {
                p++;
            }
        }
        else
        {
            isSpace = 0;
            *(temp + i) = *p;
            p++;
            i++;
        }
    }
    *(temp + i) = '\0';
    return temp;
}