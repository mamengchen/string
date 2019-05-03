//这是一个进程的demo
#include <stdio.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}
