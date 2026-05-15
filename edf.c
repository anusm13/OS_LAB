#include <stdio.h>

#define MAX 20

struct Process {
    int id;
    int execution;
    int period;

    int remaining;
    int next_arrival;
    int next_deadline;
    int count;
};

int main() {

    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[MAX];

    for (int i = 0; i < n; i++) {

        p[i].id = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("Execution Time: ");
        scanf("%d", &p[i].execution);

        printf("Period/Deadline: ");
        scanf("%d", &p[i].period);

        p[i].remaining = p[i].execution;
        p[i].next_arrival = 0;
        p[i].next_deadline = p[i].period;
        p[i].count = 0;
    }

    int t = 0;


    printf(" Time Interval \t Process      \n");


    while (1) {

        int done = 1;

        for (int i = 0; i < n; i++) {
            if (p[i].count < 2) {
                done = 0;
                break;
            }
        }

        if (done)
            break;

        int idx = -1;
        int earliest = 99999;

        for (int i = 0; i < n; i++) {

            if (t >= p[i].next_arrival &&
                p[i].remaining > 0 &&
                p[i].count < 2) {

                if (p[i].next_deadline < earliest) {

                    earliest = p[i].next_deadline;
                    idx = i;
                }
            }
        }

if (idx == -1) {

    int start = t;

    while (1) {

        t++;

        int found = 0;

        for (int i = 0; i < n; i++) {

            if (t >= p[i].next_arrival &&
                p[i].remaining > 0 &&
                p[i].count < 2) {

                found = 1;
                break;
            }
        }

        if (found)
            break;
    }

    printf(" %2d - %2d      \t Idle         \n",
           start, t);

    continue;
}


        while (p[idx].remaining > 0) {

            p[idx].remaining--;
            t++;

            int preempt = 0;

            for (int i = 0; i < n; i++) {

                if (i != idx &&
                    t >= p[i].next_arrival &&
                    p[i].remaining > 0 &&
                    p[i].next_deadline < p[idx].next_deadline) {

                    preempt = 1;
                    break;
                }
            }

            if (preempt)
                break;
        }

        printf(" %2d - %2d    \t   P%-12d \n",
               start, t, p[idx].id);

        if (p[idx].remaining == 0) {

            p[idx].count++;

            if (p[idx].count < 2) {

                p[idx].next_arrival += p[idx].period;
                p[idx].next_deadline += p[idx].period;
                p[idx].remaining = p[idx].execution;
            }
        }
    }


    return 0;
}

