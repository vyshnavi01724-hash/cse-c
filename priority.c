#include<stdio.h>
int main(){
int n,at[20],bt[20],ct[20],wt[20],tat[20],pr[20],completed[20] = {0};
int time = 0,completedCount = 0,min_pr,idx;
float avg_wt = 0 ,avg_tat = 0;
printf("Priority schedulling (non-preemptive)");
printf("Enter number of processes :");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("P%d Arrival time : ",i+1);
scanf("%d",&at[i]);
printf("P%d Burst time : ",i+1);
scanf("%d",&bt[i]);
printf("P%d Priority :",i+1);
scanf("%d",&pr[i]);
}
while(completedCount<n){
idx = -1;
min_pr = 999;
for(int i=0;i<n;i++){
if(at[i]<= time && completed[i] == 0&& pr[i]<min_pr){
min_pr = pr[i];
idx = i;
}
}
if(idx != -1){
time += bt[idx];
ct[idx] = time;
tat[idx] = ct[idx] - at[idx];
wt[idx] = tat[idx] - bt[idx];
completed[idx] = 1;
completedCount++;
}
else time++;
}
for(int i=0;i<n;i++){
avg_tat += tat[i];
avg_wt += wt[i];
}
printf("Process\tAT\tBT\tPR\tCT\tTAT\tWT\n");
for (int i=0;i<n;i++){
printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
}
printf("Average turn around time : %.2f",avg_tat/n);
printf("Average waiting time : %.2f",avg_wt/n);
return 0;
}

