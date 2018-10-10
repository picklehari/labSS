#include<stdio.h>

void main() {
	int n;
	printf("Enter the no. size of queue: ");
	scanf("%d", &n);
	int q[n];
	int newQ[n+1];
	int head;
	int headPos;
  int diskSize;
	int seek = 0;
	int i, j;
	int step;
    printf("Enter the disk size: ");
    scanf("%d", &diskSize);
	printf("Enter the elements of the queue: ");
	for(i = 0;i < n; i ++) {
		scanf("%d", &q[i]);
	}
	printf("Enter the initial head position: ");
	scanf("%d", &head);
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(q[i]>q[j]) {
				q[j] += q[i];
				q[i] = q[j] - q[i];
				q[j] = q[j] - q[i];
			}
		}
	}
	for(i=0;q[i]<=head;i++) {
		newQ[i] = q[i];
	}
	newQ[i] = head;
	headPos = i;
	for(;i<n;i++) {
		newQ[i+1] = q[i];
	}
	if((newQ[headPos]-newQ[headPos-1]) < (newQ[headPos+1]-newQ[headPos])) {
		step = -1;
	}
	if(step==-1) {
		for(i=headPos;i>0;i--) {
      printf("%d\n",newQ[i]);
      seek+=newQ[i]-newQ[i-1];
		}
		seek+=newQ[i];
    printf("%d\n",newQ[i]);
		seek+=newQ[headPos+1];
		for(i=headPos+1;i<n;i++) {
      printf("%d\n",newQ[i]);
			seek+=newQ[i+1]-newQ[i];
		}
	}
	else {
		for(i=headPos;i<n;i++) {
      printf("%d\n",newQ[i]);
			seek+=newQ[i+1]-newQ[i];
		}
		seek+=diskSize-newQ[i];
    printf("%d\n",newQ[i]);
		seek+=diskSize-newQ[headPos-1];
    		for(i=headPos-1;i>0;i--) {
      printf("%d\n",newQ[i]);
      seek+=newQ[i]-newQ[i-1];
		}
	}

	printf("Seek time: %d\n", seek);
	printf("Average seek time: %d\n", seek/n);
}
