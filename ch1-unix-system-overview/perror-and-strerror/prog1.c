#include <apue/apue.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACESS: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    return 0;
}