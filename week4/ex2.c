#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int n;
    for(int i = 0; i < 5; i++){
        n = fork();
    }
    sleep(5);
}
