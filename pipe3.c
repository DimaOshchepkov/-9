#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd_first[2], fd_second[2], result;
    size_t size;
    char resstring[14], newstring[14];

    if (pipe(fd_first) < 0)
    {
        printf("Can\'t create pipe_first\n");
        exit(-1);
    }
    if (pipe(fd_second) < 0)
    {
        printf("Can\'t create pipe_second\n");
        exit(-1);
    }

    result = fork();
    if (result == -1)
    {
        printf("Can\'t fork child\n");
        exit(-1);
    }
    else if (result > 0)
    {
        close(fd_first[0]);
        close(fd_second[1]);

        size = write(fd_first[1], "Hello, world!", 14);
        if (size != 14)
        {
            printf("Can\'t write all string\n");
            exit(-1);
        }

        close(fd_first[1]);
        size = read(fd_second[0], newstring, 14);
        if (size < 0)
        {
            printf("Can\'t read child string\n");
            exit(-1);
        }
        printf("%s from parent\n", newstring);
        close(fd_second[0]);
    }
    else
    {
        close(fd_first[1]);
        close(fd_second[0]);

        size = read(fd_first[0], resstring, 14);
        if (size < 0)
        {
            printf("Can\'t read string\n");
            exit(-1);
        }

        printf("%s from child\n", resstring);
        close(fd_first[0]);

        size = write(fd_second[1], "hHELLO, WORLD!", 14);
        if (size != 14)
        {
            printf("Can't write all child string\n");
            exit(-1);
        }
        close(fd_second[1]);
    }
    return 0;
}
