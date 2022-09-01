#include <apue/apue.h>
#include <sys/wait.h>

#define CNT 100

static int slow_input(char);

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        slow_input('C');
        return 0;
    } else {
        slow_input('P');
    }

    wait(NULL);
    return 0;
}

static int slow_input(char c)
{
    int i = 0;
    char buf[1];
    buf[0] = c;

    for (i = 0; i < CNT; i++) {
        if (write(STDOUT_FILENO, buf, sizeof(buf)) != sizeof(buf)) {
            err_sys("write error");
            return -1;
        }
        sleep(1);
    }

    return 0;
}