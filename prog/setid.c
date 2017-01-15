#include "tlpi_hdr.h"
#include <fcntl.h>


int
main(int argc,char *argv[])
{
    if(seteuid(1000)==-1)
        errExit("setuid");    
    if(seteuid(0)==-1)
        errExit("setudi");
    exit(EXIT_SUCCESS);
}
