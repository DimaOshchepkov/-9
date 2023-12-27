#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("Command line arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    printf("Enviroment params:\n");
    int i = 0;
    while (envp[i] != NULL) {
        printf("%s\n", envp[i]);
        i++;
    }
    return 0;
}