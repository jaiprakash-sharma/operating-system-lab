#include<stdio.h>
#include<conio.h>
void main()
{
	int p[10],pr[10],i,j,n,temp2,temp1;
	float bt[10],awt=0,temp;
	printf("Enter the number of processes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time and priority for process %d:",i+1);
		p[i]=i+1;
		scanf("%f%d",&bt[i],&pr[i]);
	}
	printf("Given data is:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:%f %d",p[i],bt[i],pr[i]);
		printf("\n");	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(pr[j]>pr[j+1])
		{
			temp=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=temp;
			temp1=p[j];
			p[j]=p[j+1];
			p[j+1]=temp1;
			temp2=pr[j];
			pr[j]=pr[j+1];
			pr[j+1]=temp2;
		}
	}
	printf("Updated data is:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:%f %d",p[i],bt[i],pr[i]);
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
	printf("Average waiting time using Priority Job First is:%f",awt/n);
}

