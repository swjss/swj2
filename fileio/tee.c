#include "tlpi_hdr.h"
#include <fcntl.h>

int
main(int argc,char *argv[])
{
    #define buff_size 500
    size_t flags=O_WRONLY|O_CREAT|O_TRUNC,numread;
    int i;
    size_t fds[1000];
    char buff[buff_size];
    for(i=1;i<argc;i++)
        if(!strcmp(argv[i],"--help"))
            {
                printf("./tee [-a] file...\n");
                exit(EXIT_SUCCESS);
            }
    for(i=1;i<argc;i++)
        if(!strcmp(argv[i],"-a"))
        {
            flags|=O_APPEND;
            flags&=~O_TRUNC;
        }
    int numfile=0;
    for(i=1;i<argc;i++)
        if(argv[i][0]!='-')
            fds[numfile++]=open(argv[i],flags,S_IRUSR|S_IWUSR);

            
    while((numread=read(STDIN_FILENO,buff,buff_size))!=0)
    {
        if(numread == -1)
            errExit("read");
        buff[numread]='\0';
        if(write(STDOUT_FILENO,buff,numread)!=numread)
            errExit("write");
        for(i=0;i<numfile;i++)
            if(write(fds[i],buff,numread)!=numread)
                errExit("write");
    }

    for(i=0;i<numfile;i++)
        if(close(fds[i])==-1)
            errExit("close");
    exit(EXIT_SUCCESS);
}
