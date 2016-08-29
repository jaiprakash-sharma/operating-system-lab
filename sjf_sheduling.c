#include<stdio.h>
#include<conio.h>
void main()
{
	int p[10],i,j,n,temp1;
	float bt[10],awt=0,temp;
	printf("JAI PRAKASH SHARMA(CE-2190-2K14)\n");
	printf("Enter the number of processes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time for process %d:",i+1);
		p[i]=i+1;
		scanf("%f",&bt[i]);
	}
	printf("Given data is:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:%f",p[i],bt[i]);
		printf("\n");	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(bt[j]>bt[j+1])
		{
			temp=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=temp;
			temp1=p[j];
			p[j]=p[j+1];
			p[j+1]=temp1;
		}
	}
	printf("Updated data is:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:%f",p[i],bt[i]);
		printf("\n");	
	}
	float gc[10];
	gc[0]=0;
	for(i=0;i<n-1;i++)
	{
		gc[i+1]=gc[i]+bt[i];
	}
	printf("Ghantt chart is:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:%f",p[i],gc[i]);
		printf("\n");	
	}
	for(i=0;i<n;i++)
	{
		awt=awt+gc[i];
	}
	printf("Average waiting time using Shortest Job First is:%f",awt/n);
}
