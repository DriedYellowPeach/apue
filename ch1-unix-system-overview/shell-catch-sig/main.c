#include <apue/apue.h>
#include <sys/wait.h>

static void sig_int(int signo);

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) < 0) {
        err_sys("signal error");
    }

    printf("%%");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            execlp(buf, buf, (char *)0);
            err_sys("execlp error");
            exit(127);
        }

        if (waitpid(pid, &status, 0) < 0) {
            err_sys("waitpid error");
        }

        printf("%%");
    }

    return 0;
}

static void
sig_int(int signo)
{
    printf("interrupt\n%%");
}