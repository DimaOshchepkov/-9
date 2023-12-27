#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void foo()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void bar()
{
    for (int i = 5; i < 10; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    pid_t pid = fork();

    switch (pid)
    {
    case 0:
        printf("Child process\n");
        printf("PID = %d\n", (int)getpid());
        printf("PPID = %d\n", (int)getppid());
        foo();
        break;

    case -1:
        printf("ERROR\n");
        break;

    default:
        printf("Parent process");
        printf("PID = %d\n", (int)getpid());
        printf("PPID = %d\n", (int)getppid());
        bar();
        break;
    }
    return 0;
}