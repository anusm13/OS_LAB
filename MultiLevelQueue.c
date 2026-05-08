#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    char name[20];
    int AT,BT,CT,WT,TAT;
};


void FCFS(struct Process queue[], int n, int *currentTime) {
    for (int i = 0; i < n; i++) {
        if (*currentTime < queue[i].AT) {
            *currentTime = queue[i].AT;
        }
        queue[i].CT = *currentTime + queue[i].BT;
        queue[i].TAT = queue[i].CT - queue[i].AT;
        queue[i].WT = queue[i].TAT - queue[i].BT;
        *currentTime = queue[i].CT;
    }
}
void Display(struct Process queue[], int n, char type[]) {
    printf("\n--- %s Processes ---\n", type);
    printf("Name\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               queue[i].name,
               queue[i].AT,
               queue[i].BT,
               queue[i].CT,
               queue[i].TAT,
               queue[i].WT);
    }
}

int main() {
    int nSystem, nUser;
    int currentTime = 0;

    printf("Enter number of system processes: ");
    scanf("%d", &nSystem);
    struct Process systemQueue[nSystem];

    for (int i = 0; i < nSystem; i++) {
        printf("Enter name, arrival time, burst time for system process %d: ", i + 1);
        scanf("%s %d %d", systemQueue[i].name, &systemQueue[i].AT, &systemQueue[i].BT);
    }

    printf("Enter number of user processes: ");
    scanf("%d", &nUser);
    struct Process userQueue[nUser];

    for (int i = 0; i < nUser; i++) {
        printf("Enter name, arrival time, burst time for user process %d: ", i + 1);
        scanf("%s %d %d", userQueue[i].name, &userQueue[i].AT, &userQueue[i].BT);
    }


    FCFS(systemQueue, nSystem, &currentTime);
    Display(systemQueue, nSystem, "System");


    FCFS(userQueue, nUser, &currentTime);
    Display(userQueue, nUser, "User");



    return 0;
}
