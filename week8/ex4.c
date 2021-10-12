/*
 0: 10719232
 1: 20729856
 2: 30732288
 3: 40734720
 4: 50737152
 5: 60739584
 6: 70742016
 7: 80744448
 8: 90746880
 9: 100749312
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>


int main()
{
    // Structure to store resources
    struct rusage data;
    for(int i=0; i<10; i++)
    {
        // Allocating memory 10 MB == 10000000bites
        int* block=(int*)malloc(10000000);
        // Filling it with 0
        memset(block,0,10000000);
        // Using the function getrusage() to get the statics of proccess
        getrusage(RUSAGE_SELF, &data);
        // print maximum memory usage
        printf("%d: %ld\n",i,data.ru_maxrss);
    
        sleep(1);
    }
    return 0;
}


