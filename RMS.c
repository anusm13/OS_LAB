#include <stdio.h>

struct Task
{
    int pid;
    int burst;
    int period;
    int remaining;
    int nextArrival;
};

int main()
{
    int n, i, time;
    int maxPeriod = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task t[n];

    for(i = 0; i < n; i++)
    {
        t[i].pid = i + 1;

        printf("\nTask %d\n", i + 1);

        printf("Execution Time: ");
        scanf("%d", &t[i].burst);

        printf("Period: ");
        scanf("%d", &t[i].period);

        t[i].remaining = 0;
        t[i].nextArrival = 0;

        if(t[i].period > maxPeriod)
            maxPeriod = t[i].period;
    }

    printf("\n===== Rate Monotonic Scheduling =====\n\n");

    printf("Step\tTime Interval\tRunning\n");

    int previousTask = -2;
    int startTime = 0;
    int step = 1;

    for(time = 0; time < maxPeriod * 2; time++)
    {

        for(i = 0; i < n; i++)
        {
            if(time == t[i].nextArrival)
            {
                t[i].remaining = t[i].burst;
                t[i].nextArrival += t[i].period;
            }
        }

        int selected = -1;
        int highestPriority = 9999;

        for(i = 0; i < n; i++)
        {
            if(t[i].remaining > 0)
            {
                if(t[i].period < highestPriority)
                {
                    highestPriority = t[i].period;
                    selected = i;
                }
            }
        }

        if(time > 0 && selected != previousTask)
        {
            if(previousTask == -1)
                printf("%d\t%d - %d\t\tIdle\n",
                       step++, startTime, time);
            else
                printf("%d\t%d - %d\t\tP%d\n",
                       step++, startTime, time, previousTask + 1);

            startTime = time;
        }

        previousTask = selected;

        if(selected != -1)
        {
            t[selected].remaining--;
        }
    }

    if(previousTask == -1)
        printf("%d\t%d - %d\t\tIdle\n",
               step, startTime, time);
    else
        printf("%d\t%d - %d\t\tP%d\n",
               step, startTime, time, previousTask + 1);

    return 0;
}
