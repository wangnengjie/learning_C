#include <stdio.h>
#include <string.h>
int main(void)
{
    char *(*ptr[2])(char *, char *);
    char s1[40], s2[40], num, ch;
    int i = 0;
    ptr[0] = strcpy;
    ptr[1] = strcat;
    while ((ch = getchar()) != '\n')
    {
        s1[i++] = ch;
    }
    s1[i] = '\0';
    i = 0;
    while ((ch = getchar()) != '\n')
    {
        s2[i++] = ch;
    }
    s2[i] = '\0';
    printf("1 for strcpy 2 for strcat:");
    num = getchar();
    switch (num)
    {
    case '1':
        ptr[0](s1, s2);
        break;
    case '2':
        ptr[1](s1, s2);
        break;
    default:
        break;
    }
    printf("%s", s1);
    return 0;
}