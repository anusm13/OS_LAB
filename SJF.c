#include <stdio.h>
int main()
{
    int n,i;
    int AT[20],BT[20],RT[20],CT[20],TAT[20],WT[20];
    int completed=0,current_time=0,min_index,minRt;
    float avgWT=0,avgTAT=0;
    printf("enter number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter arrival time for P%d:",i+1);
        scanf("%d",&AT[i]);
        printf("enter burst time for P%d:",i+1);
        scanf("%d",&BT[i]);
        RT[i]=BT[i];
    }
    while(completed<n){
        minRt=10000;
        int min_index=-1;
        for(i=0;i<n;i++){
            if(AT[i]<=current_time && RT[i]>0 && RT[i]<minRt){
                minRt=RT[i];
                min_index=i;
            }
        }
        if(min_index==-1){
            current_time++;
        }
        else{
            RT[min_index]--;
            current_time++;
        }
        if(RT[min_index]==0){
            completed++;
            CT[min_index]=current_time;
            TAT[min_index]=CT[min_index]-AT[min_index];
            WT[min_index]=TAT[min_index]-BT[min_index];
            avgWT += WT[min_index];
            avgTAT += TAT[min_index];
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
    printf("Average waiting time : %2f\n",avgWT/n);
    printf("Average Turn around time : %2f",avgTAT/n);
    return 0;
}