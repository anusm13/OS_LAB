#include <stdio.h>

int CT[100], WT[100], TAT[100];

int preemptive(int n, int BT[], int AT[], int priority[], int pid[])
{
    int remaining_BT[100];
    int completed = 0, current_time = 0;
    int min_priority, high;

    float AvgWT, AvgTAT;
    int SumWT = 0, SumTAT = 0;

    for (int i = 1; i <= n; i++)
    {
        remaining_BT[i] = BT[i];
    }

    while (completed < n)
    {
        high = -1;
        min_priority = 999;

        for (int i = 1; i <= n; i++)
        {
            if (AT[i] <= current_time && remaining_BT[i] > 0)
            {
                if (priority[i] < min_priority)
                {
                    min_priority = priority[i];
                    high = i;
                }
            }
        }

        if (high == -1)
        {
            current_time++;
            continue;
        }

        remaining_BT[high]--;
        current_time++;

        if (remaining_BT[high] == 0)
        {
            CT[high] = current_time;
            TAT[high] = CT[high] - AT[high];
            WT[high] = TAT[high] - BT[high];

            completed++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        SumWT += WT[i];
        SumTAT += TAT[i];
    }

    AvgWT = (float)SumWT / n;
    AvgTAT = (float)SumTAT / n;

    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               pid[i], AT[i], BT[i], priority[i],
               CT[i], WT[i], TAT[i]);
    }

    printf("\nAverage Waiting Time: %.2f", AvgWT);
    printf("\nAverage Turnaround Time: %.2f\n", AvgTAT);

    return 0;
}

int main()
{
    int n;
    int AT[100], BT[100], priority[100], pid[100];

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Arrival Time of process %d: ", i);
        scanf("%d", &AT[i]);

        printf("Enter Burst Time of process %d: ", i);
        scanf("%d", &BT[i]);

        printf("Enter Priority of process %d: ", i);
        scanf("%d", &priority[i]);

        pid[i] = i;
    }

    preemptive(n, BT, AT, priority, pid);

    return 0;
}
