#include <apue/apue.h>

#define KEY "USER"

int main(void)
{
    extern char **environ;

    // delete
    printf("before delete: addr(environ): %p\n", environ);
    if (unsetenv(KEY) != 0) {
        err_sys("can't delete env");
    }
    printf("after delete: addr(environ): %p\n", environ);

    // add
    printf("before add: addr(environ): %p\n", environ);
    if (putenv("BANABA=yellow") != 0) {
        err_sys("can't put env");
    }
    printf("after add: addr(environ): %p\n", environ);

    // add again 
    printf("before add: addr(environ): %p\n", environ);
    if (putenv("APPLE=red") != 0) {
        err_sys("can't put env");
    }
    printf("after add: addr(environ): %p\n", environ);

    int update = 1;
    // modify short
    printf("before modify short: addr(environ): %p\n", getenv("HOME"));
    if (setenv("HOME", "here", update) != 0) {
        err_sys("can't update env");
    }
    printf("after modify short: addr(environ): %p\n", getenv("HOME"));

    // modify long
    printf("before modify long: addr(environ): %p\n", getenv("HOME"));
    if (setenv("HOME", "Nordic", update) != 0) {
        err_sys("can't update env");
    }
    printf("after modify long: addr(environ): %p\n", getenv("HOME"));
    
    return 0;
}