#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char ch;
    FILE *fp;
    if (argc != 2)
    {
        printf("Arguments error!\n");
        exit(-1);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    { /* fp 指向 filename */
        printf("Can't open %s file!\n", argv[1]);
        exit(-1);
    }
    freopen(argv[1], "w", stdout);
    fclose(fp); /* 关闭filename */
    return 0;
}