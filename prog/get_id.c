#include "tlpi_hdr.h"
#include <fcntl.h>
#include <time.h>

int
main(int argc,char *argv[])
{
    uid_t uid,euid;
    gid_t gid,egid;
    pid_t pid;

    pid = getpid();

    uid = getuid();
    euid = geteuid();
    gid = getgid();
    egid = getegid();
    
    printf("my pid is %d\n",(int)pid);

    printf("user real id is %d\n",(int)uid);
    printf("user real group id is %d\n",(int)gid);
    printf("user effective id is %d\n",(int)euid);
    printf("user effective group id is %d\n",(int)egid);
    sleep(10);
    exit(EXIT_SUCCESS);
}
