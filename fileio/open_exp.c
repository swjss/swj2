#include "tlpi_hdr.h"
#include <fcntl.h>
int 
main(int argc,char *argv[])
{
    int fd;
/*    fd = open("startup",O_RDONLY);

    if(fd == -1)
        errExit("open"); */
/*    fd = open("myfile",O_RDONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
    if(fd == -1)
        errExit("open");*/

    fd = open("w.log",O_WRONLY|O_CREAT|O_TRUNC|O_APPEND,S_IRUSR|S_IWUSR);
    if(fd == -1 )
        errExit("open");
    return 0;
}

