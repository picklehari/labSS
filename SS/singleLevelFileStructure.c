#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct
{
char fileName[10][10];
int fCount;
}homeDir;


void main()
{
int i,ch;
char fName[30];
homeDir.fCount = 0;
	while(1):{
		printf("\n\n 1. Create File\t2. Delete File\n 3. Display Files\t4. Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\n Enter the name of the file : ");
					scanf("%s",homeDir.fileName[homeDir.fCount]);
					homeDir.fCount++;
				 	break;
			case 2: printf("\n Enter the name of the file : ");
					scanf("%s",fName);
					for(i=0;i<homeDir.fCount;i++){
						if(strcmp(fName, homeDir.fileName[i])==0){
							printf("File %s is deleted ",fName);
							strcpy(homeDir.fileName[i],homeDir.fileName[homeDir.fCount-1]);
					 break;
}
}
case 3:
		if(homeDir.fCount==0)
			printf("\n Directory Empty");
		else{
			printf("\n The Files are : ");
			for(i=0;i<homeDir.fCount;i++)
				printf("\t%s",homeDir.fileName[i]);
}
	break;
default: exit(0);
}
}
}
