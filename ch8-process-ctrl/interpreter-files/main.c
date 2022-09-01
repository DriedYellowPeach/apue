#include <apue/apue.h>
#include <sys/wait.h>

#define SCRIPT "/root/source/unix-programming/ch8-process-ctrl/interpreter-files/interp"

int main(void)
{
    pid_t pid;

    if((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        // the first argument is not used!!!
        if (execl(SCRIPT, "aaa", "arg1", "arg2", (char *)0) < 0) {
            err_sys("execl error");
        }
    }

    if (waitpid(pid, NULL, 0) < 0) {
        err_sys("waitpid error");
    }

    return 0;
}

/*
argv[0]: /root/source/unix-programming/ch7-process-env/echo-arg/a.out
argv[1]: foo
argv[2]: /root/source/unix-programming/ch8-process-ctrl/interpreter-files/interp
argv[3]: arg1
argv[4]: arg2
*/