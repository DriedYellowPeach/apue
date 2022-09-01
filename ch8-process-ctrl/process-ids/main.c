#include <apue/apue.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid_t ppid; 
    uid_t uid;
    uid_t euid;
    gid_t gid;
    gid_t egid;

    pid = getpid();
    ppid = getppid();
    uid = getuid();
    euid = geteuid();
    gid = getgid();
    egid = getegid();

    printf("%ld %ld %lu %lu %lu %lu", (long)pid, (long)ppid, (unsigned long)uid, \
    (unsigned long)euid, (unsigned long)gid, (unsigned long)egid);

    return 0;
}