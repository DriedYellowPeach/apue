#include <apue/apue.h>
#include <stdlib.h>

int main(void)
{
    extern char **environ;
    int i = 0;

    for (i = 0; environ[i] != NULL; i++) {
        printf("environ[%d]: %s\n", i,environ[i]);
    }

    return 0;
}