#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int isFirst;
} Process;

void countMetrics(Process processes[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(processes[j].AT > processes[j+1].AT){
                Process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
}

int main() {
    int size;
    double att;
    double awt;
    
    printf("Enter the amount of process:");
    scanf("%d", &size);
    
    Process processes[size];
    
    printf("Enter Arrival time and Burst time for each process:\n");
    for(int i = 0; i < size; i++){
        printf("Arrival time of process[%d]: ", i);
        scanf("%d", &(processes[i].AT));
        printf("Burst time of process[%d]: ", i);
        scanf("%d", &(processes[i].BT));
        processes[i].isFirst = 1;
    }
    
    countMetrics(processes, size);
    
    processes[0].CT = processes[0].AT + processes[0].BT;
    processes[0].TAT = processes[0].CT - processes[0].AT;
    processes[0].WT = processes[0].TAT - processes[0].BT;
    processes[0].isFirst = 0;
    
    for(int i = 1; i < size; i++){
        if(processes[i].isFirst){
            processes[i].CT=processes[i-1].CT+processes[i].BT;
            processes[i].TAT=processes[i].CT-processes[i].AT;
            processes[i].WT=processes[i].TAT-processes[i].BT;
            processes[i].isFirst=0;
        }
    }
    
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
    
    for(int i = 0; i < size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, processes[i].AT, processes[i].BT, processes[i].CT, processes[i].TAT, processes[i].WT);
        att += processes[i].TAT;
        awt += processes[i].WT;
    }
    
    printf("Average Turnaround Time = %f \n", att / size);
    printf("Average W T = %f \n", awt / size);
    return 0;
    
    
}

