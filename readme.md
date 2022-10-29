# to compile apue 
```shell
cp apue.h /usr/local/include/apue
gcc error.c print_exit.c system.c -fPIC -shared -o libapue.so
cp libapue.so /usr/local/lib
```

# to compile main
```shell
gcc main.c -lapue
```