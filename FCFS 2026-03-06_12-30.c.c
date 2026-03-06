#include<stdio.h>
int main()
{
    int n,at[20],bt[20],pid[20],ct[20],tat[20],wt[20];
    float sum_wt=0,sum_tat=0;
    printf("enter the number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter arrival time:");
        scanf("%d",&at[i]);
        printf("enter burst time:");
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int temp1=at[i];
                at[i]=at[j];
                at[j]=temp1;
                int temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=temp2;
                int temp3=pid[i];
                pid[i]=pid[j];
                pid[j]=temp3;
            }
        }
    }
    int current_time=0;
    for(int i=0;i<n;i++){
        if(current_time<at[i]){
            current_time=at[i];
        }
        ct[i]=current_time+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        current_time=ct[i];
    }
    for(int i=0;i<n;i++){
        sum_wt=sum_wt+wt[i];
        sum_tat=sum_tat+tat[i];
    }
    float avg_wait_time=(sum_wt)/n;
    float avg_tat_time=(sum_tat)/n;
    printf("pid\t arrival_time\t burst_time\t completion_time\t wait_time\t total_turn_around_time\n");
    for(int i=0;i<n;i++){

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("Average waiting time:%f\n",avg_wait_time);
    printf("Average turn around time:%f",avg_tat_time);
    return 0;
}
