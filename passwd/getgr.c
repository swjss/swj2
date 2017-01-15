#include "tlpi_hdr.h"
#include <grp.h>

void static
display(struct group *mygroup)
{
    char **i;
    printf("my group name is : %s\n",mygroup->gr_name);
    printf("my group id is : %d\n",mygroup->gr_gid);
    printf("my group passwd is : %s\n",mygroup->gr_passwd);
    for(i = mygroup->gr_mem;*i !=NULL; i++)
        printf("my group member is : %s\n",*i);
}

int
main(int argc,char *argv[])
{
    struct group *mygroup;

    mygroup = getgrnam(argv[1]);
    errno=0;
    if(mygroup == NULL)
        if(errno==0)
        {
            printf("no such group\n");
            exit(EXIT_SUCCESS);
        }
        else
            errExit("getgrnam");

    display(mygroup);
    exit(EXIT_SUCCESS);
}
