#include<stdio.h> 

int arrivalTime[10],burstTime[10],remainingTime[10];

int main() 
{ 
 
  int count=0,n,time,remain,flag=0,timeQuantum; 
  int waitTime=0,turnaround_time=0; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&arrivalTime[count]); 
    scanf("%d",&burstTime[count]); 
    remainingTime[count]=burstTime[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&timeQuantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(remainingTime[count]<=timeQuantum && remainingTime[count]>0) 
    { 
      time+=remainingTime[count]; 
      remainingTime[count]=0; 
      flag=1; 
    } 
    else if(remainingTime[count]>0) 
    { 
      remainingTime[count]-=timeQuantum; 
      time+=timeQuantum; 
    } 
    if(remainingTime[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-arrivalTime[count],time-arrivalTime[count]-burstTime[count]); 
      waitTime+=time-arrivalTime[count]-burstTime[count]; 
      turnaround_time+=time-arrivalTime[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(arrivalTime[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",waitTime*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}