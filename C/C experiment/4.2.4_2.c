#include <stdio.h>
#define CHANGE 0
int main(void)
{
    char ch;
#if CHANGE == 1
    while ((ch = getchar()) != '\n')
    {
        if (ch == 'a')
            ch = 'A';
        else if (ch == 'D')
            ch = 'd';
        putchar(ch);
    }
#elif CHANGE == 0
    while ((ch = getchar()) != '\n')
    {
        putchar(ch);
    }
#endif
    return 0;
}