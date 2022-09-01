#include <apue/apue.h>

int main(void)
{
    uid_t real_uid;
    uid_t euid;
    real_uid = getuid();
    euid = geteuid();
    printf("because of set-user ID bit is on,\nreal uid: %u\neffective uid: %u\nis different\n", (unsigned int)real_uid, (unsigned int)euid);
    
    //switch uid back
    int ret;
    ret = setuid(real_uid);
    if (ret != 0) {
        err_quit("setuid error");
    }
    real_uid = getuid();
    euid = geteuid();
    printf("after setuid\nread uid: %u\neffective uid: %u\n is the same\n", (unsigned int)real_uid, (unsigned int)euid);

    return 0;
}

/*
neil@oak:/root/source/unix-programming/ch8-process-ctrl/uid-ctrl$ ./a.out 
because of set-user ID bit is on,
real uid: 1000
effective uid: 0
is different

after setuid
read uid: 1000
effective uid: 1000
is the same
 */