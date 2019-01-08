#include <stdio.h>
int main(void)
{
    char ch;
    FILE *fp;
    int f = 1;
    fp = freopen("./test.txt", "w", stdout);
    while ((ch = getchar()) != '\n')
    {
        if (f)
        {
            if (ch >= 97 && ch <= 122)
            {
                ch -= 32;
            }
            f = 0;
        }
        if (ch == ' ')
        {
            f = 1;
        }
        putchar(ch);
    }
    fclose(fp);
    return 0;
}