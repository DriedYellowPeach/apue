#include <apue/apue.h>

#define BUFFSIZE 4096

int main(int argc, char *argv[])
{
    char buf[BUFFSIZE];
    int n;
    while(n = read(STDIN_FILENO, buf, BUFFSIZE)) {
        if (n != write(STDOUT_FILENO, buf, n)) {
            err_sys("write error");
        }
    }

    if (n < 0) {
        err_sys("read error");
    }
}

// function read and write