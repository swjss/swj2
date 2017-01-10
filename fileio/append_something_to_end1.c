#include "tlpi_hdr.h"
#include <fcntl.h>

int main(int argc,char *argv[])
{
    size_t fd;
    fd=open("w.log",O_WRONLY|O_APPEND);
    if(fd == -1)
        errExit("open");
    if(write(fd,"456",3)!=3)
        fatal("Partial/failed write");
    close(fd);
    exit(EXIT_SUCCESS);
}
