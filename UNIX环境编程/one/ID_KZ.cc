#include <stdio.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAXLINE 1024

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while ( fgets(buf, MAXLINE, stdin) != NULL )
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }
        if ( (pid = fork()) < 0 )
        {
            printf("fork error");
            exit(1);
        } else if (pid == 0)
        {
            execlp(buf, buf, (char *)0);
            printf("couldn't execute: %s", buf);
            exit(127);
        }

        if ( (pid = waitpid(pid, &status, 0)) )
        {
            printf("waitpid error");
            exit(0);
        }
        printf("%% ");
    }
    return 0;
}
