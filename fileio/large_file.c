#include "tlpi_hdr.h"
#include <fcntl.h>

int
main(int argc,char *argv[])
{
    int fd;
    fd = open("w.log",O_WRONLY);
    off_t offset;
    offset = atoll(argv[1]);
    if(lseek(fd,offset,SEEK_SET)==-1)
        errExit("lseek");
    if(write(fd,"test",4)!=4)
        errExit("write");

    exit(EXIT_SUCCESS);

}
