#include <stdio.h>
#define MAX 20
typedef struct Process {
    int pid;
    int burst;
    int remaining;
    int weight;
} Process;
int main() {
    int n, time = 0, completed = 0;
    Process p[MAX];
    int total_weight = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Weight (Share): ");
        scanf("%d", &p[i].weight);
        p[i].remaining = p[i].burst;
        total_weight += p[i].weight;
    }
    printf("\nExecution Order (Proportional Scheduling):\n");
    while(completed < n) {
        for(int i = 0; i < n; i++) {
            if(p[i].remaining > 0) {
                int slice = p[i].weight;
                if(slice > p[i].remaining)
                    slice = p[i].remaining;
                    printf("Time %d to %d : P%d\n",time,time + slice,p[i].pid);
                time += slice;
                p[i].remaining -= slice;
                if(p[i].remaining == 0)
                    completed++;
            }
        }
    }
    printf("\nAll processes completed.\n");
    return 0;
}