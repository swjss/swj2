#include<pwd.h>
#include "tlpi_hdr.h"

static struct passwd *
getpwnam1(char * name)
{
    setpwent();
    struct passwd * ss;
    errno = 0;
    while((ss = getpwent())!=NULL)
    {
        if(!strcmp(ss->pw_name,name))
        {
            endpwent();
            return ss;
        }
    }
    endpwent();
    return NULL;
}

int
main(int argc,char *argv[])
{
    struct passwd *ss;
    ss=getpwnam1(argv[1]);
    if(ss)
        printf("%d\n",ss->pw_uid);
    else
        printf("not found\n");
    exit(EXIT_SUCCESS);
}
