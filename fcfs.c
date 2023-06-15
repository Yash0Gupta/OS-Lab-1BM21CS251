#include <stdio.h>
struct process{
    int B_time;
    int arr_time;
    int turnAround_time;
    int waiting_time;
};
typedef struct process procs;

int main(){
    int n;
    printf("enter the number of the processes\n");
    scanf("%d",&n);
    procs processes[n];
    for(int i=0;i<n;i++){
        printf("enter the burst time for process:%d\n",i+1);
        scanf("%d",&processes[i].B_time);
        printf("enter the arrival time for process:%d\n",i+1);
        scanf("%d",&processes[i].arr_time);
    }
    int comp_time=0;
    int avg_tat=0;
    for(int i=0;i<n;i++){
        comp_time+=processes[i].B_time;
        processes[i].turnAround_time=comp_time-processes[i].arr_time;
        avg_tat+=processes[i].turnAround_time;
    }
    printf("printing turn around time\n");
    for(int i=0;i<n;i++){
        printf("the Turn Around time for process:%d is %d\n",i+1,processes[i].turnAround_time);
    }
    printf("avg turn around time of all the processes is %d\n",avg_tat/n);
    int avg_wait=0;
    for(int i=0;i<n;i++){
        processes[i].waiting_time=processes[i].turnAround_time-processes[i].B_time;
        avg_wait+=processes[i].waiting_time;
    }
    printf("\n printing waiting time\n");
    for(int i=0;i<n;i++){
        printf("the Waiting time for process:%d is %d\n",i+1,processes[i].waiting_time);
    }
    printf("avg turn around time of all the processes is %d\n",avg_wait/n);
    return 0;
}
