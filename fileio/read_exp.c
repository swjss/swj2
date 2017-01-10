#include "tlpi_hdr.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    #define max_read 20
    char buff[max_read];
    if(read(STDIN_FILENO,buff,max_read)==-1)
        errExit("read");
    printf("The input data was %s\n",buff);
    exit(EXIT_SUCCESS);
}
