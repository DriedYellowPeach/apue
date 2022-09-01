#include <apue/apue.h>

static void charatatime(const char *);

int main(void)
{
    pid_t pid;

    TELL_WAIT();

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        WAIT_PARENT();
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
        TELL_CHILD(pid);
    }
    return 0;
}

static void charatatime(const char *str)
{
    const char *ptr;
    int i;

    setbuf(stdout, NULL);
    for (i = 0; i < 1; i++) {
        for (ptr = str; *ptr != 0; ptr++) {
            putc(*ptr, stdout);
        }
    }

    return;
}