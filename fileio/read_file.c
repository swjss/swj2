#include "tlpi_hdr.h"
#include <fcntl.h>

int
main(int argc,char *argv[])
{
    int fd;
    char buf[10];
    fd = open("w.log",O_RDWR|O_APPEND);
    if(fd == -1)
        errExit("open");
    if(lseek(fd,0,SEEK_SET)==-1)
        errExit("lseek");
    int num;
    if((num=read(fd,buf,4))==-1)
        errExit("read");
    if(write(fd,buf,num)!=num)
        errExit("write");
    exit(EXIT_SUCCESS);
}

