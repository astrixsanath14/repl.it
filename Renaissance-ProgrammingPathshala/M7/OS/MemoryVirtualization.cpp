#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double getTime()
{
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double)t.tv_sec + (double)t.tv_usec / 1e6;
}

void spin(int howLong)
{
    double t = getTime();
    while (getTime() - t < howLong)
        ;
}

int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     fprintf(stderr, "usage: mem<value>\n");
    //     exit(0);
    // }
    // int num = atoi(argv[1]);
    int num = 1;
    int *p;
    p = (int *)malloc(sizeof(int));
    // manually give a same used address...
    // p = (int *)0x7f87ddc05a00;
    printf("(%d) addr pointed to by p: %p\n", (int)getpid(), p);
    *p = num;
    printf("(%d) initial value of p: %d\n", getpid(), *p);
    while (1)
    {
        spin(1);
        *p = *p + 1;
        printf("(%d) value of p: %d\n", getpid(), *p);
    }
    return 0;
}

/*
gcc Renaissance-ProgrammingPathshala/M7/OS/MemoryVirtualization.cpp -o Renaissance-ProgrammingPathshala/M7/OS/MemoryVirtualization
Terminal 1:
Renaissance-ProgrammingPathshala/M7/OS/MemoryVirtualization 1
(18668) addr pointed to by p: 0x7fcd37405a00

Terminal 2:
Renaissance-ProgrammingPathshala/M7/OS/MemoryVirtualization 1
(18694) addr pointed to by p: 0x7f8421c05a00

0x7f8058c05a00
*/