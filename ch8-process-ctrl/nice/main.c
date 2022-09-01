#include <apue/apue.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/param.h>

unsigned long long count;
struct timeval end;

static void checktime(const char *str)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    if (tv.tv_sec >= end.tv_sec && tv.tv_usec >= end.tv_usec) {
        printf("%s count = %lld\n", str, count);
        exit(0);
    }

    return;
}

int main(int argc, char *argv[])
{
     pid_t pid;
     char *s;
     int nzero, ret;
     int adj = 0;

     setbuf(stdout, NULL);
     nzero = NZERO;
     printf("NZERO = %d\n", nzero);
     if (argc == 2) {
        adj = strtol(argv[1], NULL, 10);
     }
     gettimeofday(&end, NULL);
     end.tv_sec += 10;

     if ((pid = fork()) < 0) {
        err_sys("fork failed");
     } else if (pid == 0) {
        s = "child";
        printf("current nice value in child is %d, adjusting by %d\n", nice(0)+nzero, adj);
        // we must clear errno
        errno = 0;
        if ((ret = nice(adj)) == -1 && errno != 0) {
            err_sys("child set nice failed");
        }
        //printf("%d %d\n", adj, ret);
        printf("child now nice value is %d\n", ret+nzero);
     } else {
        s = "parent";
        printf("current nice value in parent is %d\n", nice(0) + nzero);
     }

     for (;;) {
        if (++count == 0) {
            err_quit("%s counter wrap", s);
        }
        checktime(s);
     }
}