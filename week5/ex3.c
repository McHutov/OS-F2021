#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 100

char s[N];
int bConsumerSleeping;
int bProducerSleeping;
int position;

void* Produce(void* args){
    
    while(1){
        if(bProducerSleeping){
            continue;
        }
        
        if(position == N){
            bConsumerSleeping = 0;
            bProducerSleeping = 1;
            printf("BUFFER IS A FULL!\n");
        }
        
        s[position] = rand();
        printf("Produce: New data [Index #%d: %c]\n",position,s[position]);
        position++;
    }
    
    return NULL;
}

void* Consume(void* args){
    while(1){
        if(bConsumerSleeping){
            continue;
        }
        
        if(position == 0){
            bConsumerSleeping = 1;
            bProducerSleeping = 0;
            printf("BUFFER IS AN EMPTY!\n");
        }
        
        s[position] = 0;
        printf("Consumer: Data consumed [Index #%d: EMPTY]\n",position);
        position--;
    }
    return NULL;
}

int main(){
    bConsumerSleeping = 1;
    
    pthread_t tProducer;
    pthread_t tConsumer;
    
    pthread_create(&tProducer, NULL, &Produce, NULL);
    pthread_create(&tProducer, NULL, &Consume, NULL);
    pthread_join(tProducer,NULL);
    pthread_join(tConsumer,NULL);
    
}
