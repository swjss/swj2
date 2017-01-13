#include "tlpi_hdr.h"
#include <fcntl.h>

extern char **environ;

int
main()
{
    char **ep;
    for(ep = environ;*ep !=NULL;ep++)
        puts(*ep);
    return 0;
}
