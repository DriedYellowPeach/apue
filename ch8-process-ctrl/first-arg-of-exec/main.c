#include <apue/apue.h>
#include <sys/wait.h>

#define PROG "/root/source/unix-programming/ch7-process-env/echo-arg/a.out"

int main(void)
{
    pid_t pid;

    if((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if (execl(PROG, "a.out", "arg1", "arg2", (char *)0) < 0) {
            err_sys("execl error");
        }
    }

    if (waitpid(pid, NULL, 0) < 0) {
        err_sys("waitpid error");
    }

    return 0;
}