#include "tlpi_hdr.h"
#include <pwd.h>

static void
display(struct passwd *mypass)
{ 
    printf("my name is : %s\n",mypass->pw_name);
    printf("my passwd is : %s\n",mypass->pw_passwd);
    printf("my user id is : %d\n",mypass->pw_uid);
    printf("my group id is : %d\n",mypass->pw_gid);
    printf("my discript is : %s\n",mypass->pw_gecos);
    printf("my home dir is : %s\n",mypass->pw_dir);
    printf("my shell is : %s\n",mypass->pw_shell);
}

int
main(int argc,char *argv[])
{
    struct passwd *mypass=NULL,*mypass1=NULL;
    if(argc <= 1)
        usageErr("%s user-name\n",argv[0]);

    mypass = getpwnam(argv[1]);
    errno=0;
    if(mypass == NULL)
        if(errno==0){
            printf("no such user\n");
            exit(EXIT_SUCCESS);
        }
        else
            errExit("getpwnam");
    mypass1 = getpwuid(mypass->pw_uid);
    display(mypass);
    display(mypass1);
    exit(EXIT_SUCCESS);
}
