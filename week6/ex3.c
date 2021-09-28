#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct process{
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int isFirst;
    int reminder;
} Process;

void countMetrics(Process processes[], int size, int quantum){
    int time = 0;
    int count = 0;
    do{
        int minA = 0;
        for (int j = 0; j < size; j++){
            if (processes[j].AT < minA && processes[j].reminder != 0) {
                minA = processes[j].AT;
            }
        }
        
        if(time < minA){
            time = minA;
        }
        

        for (int j = 0; j < size; j++){
            if (processes[j].AT <= time && processes[j].reminder != 0) {
                
                    if (processes[j].reminder <= quantum) {
                        time += processes[j].reminder;
                        processes[j].reminder=0;
                        processes[j].CT=time;
                        count++;
                        continue;
                    }
                    processes[j].reminder-=quantum;
                    time+=quantum;
                
            }
        }
    } while (count < size);
}

int main() {
    int size;
    int quantum;
    double att;
    double awt;
    
    printf("Enter the amount of process:");
    scanf("%d", &size);
    printf("Enter the amount of quantums:");
    scanf("%d", &quantum);
    
    Process processes[size];
    
    printf("Enter Arrival time and Burst time for each process:\n");
    for(int i = 0; i < size; i++){
        printf("Arrival time of process[%d]: ", i);
        scanf("%d", &(processes[i].AT));
        printf("Burst time of process[%d]: ", i);
        scanf("%d", &(processes[i].BT));
        processes[i].isFirst = 1;
        processes[i].reminder = processes[i].BT;
    }
    
    countMetrics(processes, size, quantum);
    
    for(int i = 0; i < size; i++){
        if(processes[i].isFirst){
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



