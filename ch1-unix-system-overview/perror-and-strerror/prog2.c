#include <apue/apue.h>
#include <errno.h>

#define MAXSZ 30

int main(int argc, char *argv[])
{

    char buf[MAXSZ];
    
    /*
    // we don't need this because | only redirect stdin and stdout, stderr not affectted.
    while (fgets(buf, MAXSZ, stdin) != NULL) {
        printf("buf: %s", buf);
        fputs(buf, stdout);
    }
    */
    
    errno = EAGAIN;
    perror(argv[0]);
    return 0;
}

/*
> ./prog1 | ./prog2 | ./prog2
EACESS: Permission denied
./prog1: No such file or directory
./prog2: Resource temporarily unavailable
./prog2: Resource temporarily unavailable
*/