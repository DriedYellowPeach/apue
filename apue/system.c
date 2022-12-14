#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include "apue.h"

int mysystem(const char *cmdstring)
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        status = -1;
    } else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127); /* if execl error */
    } else {
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1;
                break;
            }
        }
    }

    return status;
}