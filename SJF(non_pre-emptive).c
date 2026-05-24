#include<stdio.h>
int main()
{
    int n,at[20],bt[20],pid[20],completed[20],tat[20],ct[20],wt[20];
    float avg_wt,avg_tat,sum_wt=0,sum_tat=0;
    printf("enter number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the arrival time:");
        scanf("%d",&at[i]);
        printf("enter the burst time:");
        scanf("%d",&bt[i]);
        pid[i]=i+1;
        completed[i]=0;
    }
    int current_time=0;
    int completed_count=0;
    while(completed_count<n){
        int idx=-1;
        int min_bt=10000;
        for(int i=0;i<n;i++){
            if(at[i]<=current_time && completed[i]==0){
                if(bt[i]<min_bt){
                    min_bt=bt[i];
                    idx=i;
                }
            }
        }
        if(idx==-1){
                    current_time++;
                }
                else{

                    ct[idx]=current_time+bt[idx];
                    tat[idx]=ct[idx]-at[idx];
                    wt[idx]=tat[idx]-bt[idx];
                    completed[idx]=1;
                    current_time=ct[idx];
                    completed_count=completed_count+1;
                }
    }
    for(int i=0;i<n;i++){
        sum_wt=sum_wt+wt[i];
        sum_tat=sum_tat+tat[i];
    }
    avg_wt=sum_wt/n;
    avg_tat=sum_tat/n;
    printf("pid\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("average waiting time:%f\n",avg_wt);
    printf("average turn around time:%f\n",avg_tat);
}
