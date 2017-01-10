#include "tlpi_hdr.h"
#include <fcntl.h>

int
main(int argc,char *argv[])
{
    if(argc < 3 || !strcmp(argv[1],"--help") )
        usageErr("%s file numbytes [x]",argv[0]);
    int fd,flags;
    fd = open(argv[1],O_RDWR|O_CREAT|O_APPEND);
    int i;
    for(i = 1; i < argc; i++)
        if(!strcmp(argv[i],"x"))
        {
            flags=fcntl(fd,F_GETFL);
            fcntl(fd,F_SETFL,flags&(~O_APPEND));
        }
    int nbytes = atoi(argv[2]);
    if(flags&O_APPEND)
        for(i=0;i<nbytes;i++)
            if(write(fd,"1",1)==-1)
                errExit("write 21");
    else
        for(i=0;i<nbytes;i++)
        {
            if(lseek(fd,0,SEEK_END)==-1)
                errExit("lseek");
            if(write(fd,"1",1)==-1)
                errExit("write 29");
        }
    exit(EXIT_SUCCESS);
}

