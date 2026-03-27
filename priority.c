#include <stdio.h>

int main()
{
    int n, at[20], bt[20], pid[20], ct[20], tat[20], wt[20], pri[20], com[20];
    float sum_wt = 0, sum_tat = 0, avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
        printf("Enter priority: ");
        scanf("%d", &pri[i]);
        com[i] = 0;
    }

    int completed = 0, current_time = 0;

    while(completed < n) {
        int high_pri = -1;
        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && com[i] == 0) {
                if(high_pri == -1 || pri[i] < pri[high_pri]) {
                    high_pri = i;
                }
            }
        }

        if(high_pri == -1) {
            current_time++;
        } else {
            ct[high_pri] = current_time + bt[high_pri];
            tat[high_pri] = ct[high_pri] - at[high_pri];
            wt[high_pri] = tat[high_pri] - bt[high_pri];

            current_time = ct[high_pri];
            com[high_pri] = 1;
            completed++;
        }
    }

    for(int i = 0; i < n; i++) {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    avg_wt = sum_wt / n;
    avg_tat = sum_tat / n;

    printf("\nPID\tAT\tBT\tPRI\tCT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pri[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
