#include "tlpi_hdr.h"
#include <fcntl.h>


int
main(int argc,char *argv[])
{
    int fd,flags;
    fd = open("w.log",O_WRONLY|O_CREAT|O_APPEND);
    if(fd == -1)
        errExit("open");
    flags = fcntl(fd,F_GETFL);
    if(flags == -1)
        errExit("fcntl");
    if(flags && O_CREAT)
        printf("create have\n");
    if(flags && O_APPEND)
        printf("append flags have \n");
    exit(EXIT_SUCCESS);
}

