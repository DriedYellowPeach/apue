#include <apue/apue.h>
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globVal;

int main(void)
{
    int autoVal;
    register int regiVal;
    volatile int volaVal;
    static int statVal;

    globVal = 1; autoVal = 2; regiVal = 3; volaVal = 4; statVal = 5;

    if (setjmp(jmpbuffer) != 0) {
        printf("after long jmp: \n");
        printf("%d %d %d %d %d\n", globVal, autoVal, regiVal, volaVal, statVal);
        exit(0);
    }

    globVal = 95; autoVal = 96; regiVal = 97; volaVal = 98; statVal = 99;
    f1(autoVal, regiVal, volaVal, statVal);
    exit(0);
}

static void f1(int i, int j, int k, int l)
{
    printf("in f1(): \n");
    printf("%d %d %d %d %d\n", globVal, i, j, k, l);
    f2();
}

static void f2(void)
{
    longjmp(jmpbuffer, 1);
}