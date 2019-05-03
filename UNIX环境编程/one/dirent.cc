#include <iostream>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>

int main( int argc, char* argv[] )
{
    DIR *dp;
    struct dirent *dirp;
    if ( argc != 2 )
    {
        perror( "usage: ls direstory_name" );
    }

    if ( (dp = opendir(argv[1])) == NULL )
    {
        printf( "open errno %s", argv[1] );
    }

    while ( (dp = opendir(argv[1])) == NULL )
    {
        printf(" %s\n ", dirp->d_name);
    }
    closedir(dp);
    exit(0);
}
