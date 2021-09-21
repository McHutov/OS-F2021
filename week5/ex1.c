#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void *myThread (int *arg){
    printf("  -> Hellow from myThread %d\n", *arg);
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter the N: ");
    scanf("%d", &n);
    
    pthread_t thread;
    for(int i = 0; i < n; i++) {
        printf("Creating Thread #%d\n", i);
        if(pthread_create(&thread, NULL, myThread, &i)) {
            printf(" >> ERROR IN CREATING Thread #%d!\n", i);
            pthread_exit(NULL);
            return 1;
        } else {
            printf(" >> Thread %d created!\n", i);
        }
        pthread_join(thread,NULL);
    }
     return 0;
}
