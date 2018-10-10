#include<stdio.h>

void findturn(int n,int wait[],int burst[],int turn[],int pty[]){
	int i;
	printf("Priority   Waiting Time   Burst Time   Turnaround Time \n");
	for(i=0;i<n;i++){
		printf("%d         %d               %d               %d \n",pty[i],wait[i],burst[i],turn[i]);
	}
}
void findwait(int n,int wait[],int burst[],int turn[],int pty[]){
	int i,temp;
	wait[0]=0;
	turn[0]=burst[0];
	for(i=1;i<n;i++)
		wait[i]=burst[i-1]+wait[i-1];
		turn[i]= turn[i-1]+burst[i];
	for(i=0;i<n;i++){

			temp = burst[pty[i]];
			burst[pty[i]]= burst[i];
			burst[i]=temp;
			
	}
		
	findturn(n,wait,burst,turn,pty);
}


void main()
{
	int i,n,wait[10],burst[10],turn[10],pty[10],temp;
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of process %d \n",i+1);
		scanf("%d",&burst[i]);
			
	}
	for(i=0;i<n;i++)
	{
		printf("Enter priority of process %d \n",i+1);
		scanf("%d",&pty[i]);
		}	findwait(n,wait,burst,turn,pty);

}