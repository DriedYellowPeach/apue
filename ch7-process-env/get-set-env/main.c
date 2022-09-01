#include <apue/apue.h>
#include <stdlib.h>

#define KEY "BANANA"

int main(void)
{
    // set
    if(putenv(KEY"=yellow") != 0) {
        err_sys("can't putenv");
    }

    //get
    char *val = NULL;
    val = getenv(KEY);
    printf(KEY "= %s\n", val);

    // remove using put
    if(putenv(KEY) != 0) {
        err_sys("can't unset");
    }

    if(putenv(KEY"=yellow") != 0) {
        err_sys("can't putenv");
    }

    // remove using unsetenv
    if (unsetenv(KEY) != 0) {
        err_sys("can't unsetenv");
    }

    if(putenv(KEY"=yellow") != 0) {
        err_sys("can't putenv");
    }

    int update = 1;
    if (setenv(KEY, "green", update) != 0) {
        err_sys("can't update env");
    }
    val = getenv(KEY);
    printf(KEY "= %s\n", val);

}