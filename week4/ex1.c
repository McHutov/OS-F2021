#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pid = fork();
    int n = 0;
    if (pid == 0) {
        printf("Hello from child [%d-%d]\n", pid, atoi(argv[1]));
    } else {
        printf("Hello from parent [%d-%d]\n", pid, atoi(argv[1]));
    }
    return 0;
}
