#include "tlpi_hdr.h"
#include <fcntl.h>

int
main(int argc,char *argv[])
{
    int fd;
    fd = open("w.log",O_WRONLY);
    if(fd == -1)
        errExit("open");
    int newfd;
    newfd=dup(fd);
    if(write(newfd,"123\n",4)!=4)
        errExit("write");
    if(dup2(fd,2)==-1)
        errExit("dup2");
    if(write(2,"456\n",4)!=4)
        errExit("write");
    close(fd);
    close(newfd);
    exit(EXIT_SUCCESS);
}
