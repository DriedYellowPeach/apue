#include <apue/apue.h>

int main(int argc, char *argv[])
{
    int status;

    if (argc < 2) {
        err_quit("command-line argument required");
    }

    printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
    if ((status = system(argv[1])) < 0) {
        err_sys("system() error");
    }

    pr_exit(status);

    return 0;
}