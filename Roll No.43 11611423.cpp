#include<stdio.h>
#include<conio.h>
#define N 100
int ct=0;
int ppt=0;
int nk=100;
int tick=0;
struct process
{
    int at,bt,prt,pid,copy_array[N],cbt;
};
struct process2
{
    int at2,bt2,prt2,pid2;
    int wt,ta;
    int flage;
}
proc2[N]; 
void copyfun(struct process record)
{   
proc2[ppt].bt2=record.bt;
proc2[ppt].at2=record.at;
proc2[ppt].prt2=record.prt;
proc2[ppt].pid2=record.pid;
ppt++;       
}
//-------------------------------------------------------
void RR()
{
  int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      limit=ct;
      x = limit;
      for(i = 0; i <limit ; i++)
      {
           
            arrival_time[i]=proc2[i].at2;
            burst_time[i]=proc2[i].bt2;           
            temp[i] = burst_time[i];
      }
      printf("\nEnter Time Quantum:\t");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", proc2[i].pid2, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
}
//----------------------------------------------------- 
int main()
{
    int nump,j=0,i=0,k=1,count=0,flag=0,time;
    printf("Enter the number of processes :");
    scanf("%d",&nump);
    struct process proc[nump];
for(i=0;i<nump;i++)
    {       printf("Enter the process id here\n ");
            scanf("%d",&proc[i].pid);
            printf("Enter the arrival time of %d :",proc[i].pid);
            scanf("%d",&proc[i].at);
            printf("Enter the burst time of %d :",proc[i].pid);
            scanf("%d",&proc[i].bt);
            proc[i].cbt=proc[i].bt;
            printf("Enter the priority time of %d :",proc[i].pid);
            scanf("%d",&proc[i].prt);}
            int fl=0   
        for(int i=0;i<nump;i++)
        {  //1.1
        int btd=proc[i].cbt;
        int scale=0;
        k=1;
            for(int j=0;j<btd;j++){  //1.2
    //  printf("\n  the burst time= %d of  process :%d  of value j:%d",proc[i].bt,proc[i].pid,j);
            if(i==0 && proc[i].at==0 && scale==0){
                for(int l=0;l<proc[i+1].at;l++){
                    count++;
                    proc[i].bt--;
                }
            fl=1;
                printf("\n%d --------- %d",proc[i].at,count);
                time=proc[i].at+count;  
            }
            if(i==(nump-1)){
                if(tick==1)count--;
                for(int m=0;m<proc[i].bt;m++){
                    count++;
                    proc[i].bt--;
                }
    printf("\n%d --------- %d",time,count);
    break;
   }            
                if( count!=0 && ((count%2)==0) && (proc[k+i].prt>proc[i].prt))
                {
                    printf("\n%d --------- %d",time,count);
                    time=count;
                    count++;
                    proc[i].bt--;
                    flag++;
                    k++;
                    scale=1;
                    continue;  
                }
                else if( count!=0 && ((count%2)==0) && (proc[i+k].prt < proc[i].prt)){
                    if(fl!=1)
                    printf("\n%d --------- %d",time,count);//printing the first quque
                    fl=0;
                    if(proc[i].bt>0){
                    ct++;
                copyfun(proc[i]);}
                scale=1;
                time=count;
                count++;
                proc[i+1].bt--;
                tick=1;
                    break;
                    }
                else
                {
                flag++;
                proc[i].bt--;
                count++;
                scale=1;
                }   
            }
        }
    RR();
}

