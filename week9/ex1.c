#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct frame {
    unsigned int page;
    unsigned int age;
    unsigned int r;
}frame_t;

int findPage(int page, int size, frame_t frames[]){
    for (int i = 0; i < size; i++){
        if (frames[i].page == page){
            return i;
        }
    }
    return -1;
}

int findLeastCounter(frame_t frames[], int size){
    int index = 0;
    int min = INT_MAX;
    
    for(int i = 0; i < size; i++){
        if (frames[i].age < min){
            min = frames[i].age;
            index = i;
        }
    }
    
    return index;
}

void updateAge(frame_t frames[], int size)
{
    for(int i = 0; i < size; i++)
    {
        frames[i].age = frames[i].age >> 1;
        frames[i].age = frames[i].age | (frames[i].r << 30);
        frames[i].r = 0;
    }
}
int main(){
    int frameSize = 0;
    int hits = -1;
    int misses = 0;
    int cTick = 0;
    
    printf("Enter numer(size) of frames: ");
    scanf("%d", &frameSize);
    
    frame_t frames[frameSize];
    
    for(int i=0; i< frameSize; i++)
    {
        frames[i].age = 0;
        frames[i].page = -1;
        frames[i].r = 0;
    }

    FILE *pageRef = fopen("Lab 09 input.txt", "r");
    while (!feof(pageRef)) {
        int page;
        fscanf(pageRef, "%d", &page);
        int index = findPage(page, frameSize, frames);
        
        if(index == -1) {
            misses++;
            int changeIndex = findLeastCounter(frames,frameSize);
            
            frames[changeIndex].page = page;
            frames[changeIndex].age = 1 << 30;
            frames[changeIndex].r = 1;
        } else {
            
            hits++;
            frames[index].r = 1;
        }
        
        if(cTick % 1 == 0){
            updateAge(frames, frameSize);
        }
        
        cTick++;
    }
    
    printf("Hits: %d.\nMisses: %d.\nRatio: %f.\n", hits, misses, (float)hits/misses);
    return 0;
}
