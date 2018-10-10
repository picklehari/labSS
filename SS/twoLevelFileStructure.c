#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct
{
char directoryName[10],fileName[10][10];
int fCount;
}dirA;


void main()
{
int i,ch;
char fName[30];

dirA.fCount = 0;
printf("\nEnter name of directory -- ");
scanf("%s", dirA.directoryName);
while(1)
{
printf("\n\n 1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter the name of the file -- ");
scanf("%s",dirA.fileName[dirA.fCount]);
dirA.fCount++;
	break;
case 2: printf("\n Enter the name of the file -- ");
scanf("%s",fName);
	for(i=0;i<dirA.fCount;i++)
{
		if(strcmp(fName, dirA.fileName[i])==0)
{
printf("File %s is deleted ",fName);
strcpy(dirA.fileName[i],dirA.fileName[dirA.fCount-1]);
	break;
}
}
		if(i==dirA.fCount)
printf("File %s not found",fName);
	else
dirA.fCount--;
	break;
case 3: printf("\n Enter the name of the file -- ");
scanf("%s",fName);
	for(i=0;i<dirA.fCount;i++)
{
		if(strcmp(fName, dirA.fileName[i])==0)
{
printf("File %s is found ", fName);
	break;
}
}
		if(i==dirA.fCount)
printf("File %s not found",fName);
	break;
case 4:
	if(dirA.fCount==0)
printf("\n Directory Empty");
	else
{
  printf("\n The Files are -- ");
	for(i=0;i<dirA.fCount;i++)
    printf("\t%s",dirA.fileName[i]);
}
	break;
default: exit(0);
}
}
}
