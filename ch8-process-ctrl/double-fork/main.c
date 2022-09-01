#include <apue/apue.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid1;
    pid_t pid2;

    if ((pid1 = fork()) < 0) {
        err_sys("fork error");
    } else if (pid1 == 0) {
        if ((pid2 = fork()) < 0) {
            err_sys("fork error");
        } else if (pid2 > 0) {
            return 0;
        }

        sleep(2);
        printf("second child, parent pid: %ld\n", (long)getppid());
        return 0;
    }

    int opt = 0;
    if (waitpid(pid1, NULL, opt) < 0) {
        err_sys("wait error");
    }

    return 0;
}