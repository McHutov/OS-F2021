#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <string.h>

int main(){
    for(int i = 0; i < 10; i++){
        // Allocating memory 10 MB == 10000000bites
        int* test = (int*)malloc(10000000);
        
        // Filling it with 0
        memset(test, 0, 10000000);
        
        //Sleeping 1sec
        sleep(1);
    }
    return 0;
}
