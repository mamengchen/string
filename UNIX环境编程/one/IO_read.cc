//这是一个将标准输入复制到标准输出的demo
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int c;
    while ( ( c = getc(stdin) ) != EOF )
    {
        if ( putc(c, stdout) == EOF )
        {
            printf( " output error " );
            exit(1);
        }
    }
    if (ferror(stdin))
    {
        printf( " input error " );
        exit(1);
    }
    return 0;
}
