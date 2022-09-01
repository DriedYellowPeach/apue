#include <apue/apue.h>
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

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