#include <stdio.h>

int main()
{
    int n, tq;
    int AT[100], BT[100], pid[100];
    int CT[100], WT[100], TAT[100];
    int remaining_BT[100];
    int queue[100], front = 0, rear = 0;
    int visited[100] = {0};

    int completed = 0, current_time = 0;
    float AvgWT, AvgTAT;
    int SumWT = 0, SumTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter AT of P%d: ", i);
        scanf("%d", &AT[i]);

        printf("Enter BT of P%d: ", i);
        scanf("%d", &BT[i]);

        pid[i] = i;
        remaining_BT[i] = BT[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    queue[rear++] = 1;
    visited[1] = 1;

    while (completed < n)
    {
        if (front == rear)
        {
            current_time++;
            for (int i = 1; i <= n; i++)
            {
                if (AT[i] <= current_time && visited[i] == 0)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];

        if (remaining_BT[i] > tq)
        {
            current_time += tq;
            remaining_BT[i] -= tq;
        }
        else
        {
            current_time += remaining_BT[i];
            remaining_BT[i] = 0;

            CT[i] = current_time;
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - BT[i];

            completed++;
        }

        for (int j = 1; j <= n; j++)
        {
            if (AT[j] <= current_time && visited[j] == 0)
            {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        if (remaining_BT[i] > 0)
            queue[rear++] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        SumWT += WT[i];
        SumTAT += TAT[i];
    }

    AvgWT = (float)SumWT / n;
    AvgTAT = (float)SumTAT / n;

    printf("\n--- Round Robin Scheduling ---\n");
    printf("Process\tAT\tBT\tCT\tWT\tTAT\n");

    for (int i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], AT[i], BT[i],
               CT[i], WT[i], TAT[i]);
    }

    printf("\nTime Quantum: %d\n", tq);
    printf("Average WT: %.2f\n", AvgWT);
    printf("Average TAT: %.2f\n", AvgTAT);

    return 0;
}
