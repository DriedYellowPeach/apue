#include <apue/apue.h>
#include <stdio.h>
#include <sys/times.h>

#define MAXSZ 50

static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend);
static void do_cmd(char *str);

int main(void)
{
    char buf[MAXSZ];
    printf("%%");
    while(fgets(buf, MAXSZ, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        do_cmd(buf);
        printf("%%");
    }
}

static void 
do_cmd(char *cmd)
{
    struct tms tmsstart, tmsend;
    clock_t start, end;
    int status;

    if((start = times(&tmsstart)) == -1) {
        err_sys("times error");
    }

    if ((status = system(cmd)) < 0) {
        err_sys("system error");
    }

    if ((end = times(&tmsend)) == -1) {
        err_sys("times error");
    }

    pr_times(end-start, &tmsstart, &tmsend);
    pr_exit(status);
}

static void
pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
    static long clktck = 0;

    if(clktck == 0) {
        if ((clktck = sysconf(_SC_CLK_TCK)) < 0) {
            err_sys("sysconf error");
        }
    }

    double user = (tmsend->tms_utime - tmsstart->tms_utime) / (double) clktck;
    double sys = (tmsend->tms_stime - tmsstart->tms_stime) / (double) clktck;
    double cusr = (tmsend->tms_cutime - tmsstart->tms_cutime) / (double) clktck;
    double csys = (tmsend->tms_cstime - tmsstart->tms_cstime) / (double) clktck;

    printf("\treal: %7.2f\n", real / (double) clktck);
    printf("\tuser: %7.2f\n", user);
    printf("\t sys: %7.2f\n", sys);
                         
    printf("\tcusr: %7.2f\n", cusr);
    printf("\tcsys: %7.2f\n", csys);
}