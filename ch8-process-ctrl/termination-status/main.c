#include <sys/wait.h>
#include <apue/apue.h>

// static void pr_exit(int);

int main(void)
{
    pid_t pid;
    int status;

    //fork and exit
    if ((pid = fork()) < 0) {
        err_sys("can't fork");
    } else if (pid == 0) {
        exit(7);
    }

    //wait
    if (wait(&status) != pid) {
        err_sys("wait error");
    }
    pr_exit(status);

    //fork and abort
    if ((pid = fork()) < 0) {
        err_sys("can't fork");
    } else if (pid == 0) {
        abort();
    }

    //wait
    if (wait(&status) != pid) {
        err_sys("wait error");
    }
    pr_exit(status);

    //fork and /0
    if ((pid = fork()) < 0) {
        err_sys("can't fork");
    } else if (pid == 0) {
        //sleep(1);
        status / 0;
        return 0;
        //abort();
    }

    //wait
    if (wait(&status) != pid) {
        err_sys("wait error");
    }
    pr_exit(status);

    return 0;
}

void pr_exit(int status)
{
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
#ifdef WCOREDUMP
        printf("abnormal termination, signal number = %d\n", WTERMSIG(status));
#else
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status), \
        WCOREDUMP(status) ? " (core file generated)" : "");
#endif
    else if (WIFSTOPPED(status))
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}