#include<stdio.h>
struct sjf
{
	int p[100];
	int bt[100];
	int at[100];
};
struct gc
{
	int p[100],t1[100],t2[100];
};
void main()
{
	struct sjf a,temp1;
	struct gc x;
	int awt=0;
	int temp,val,loc;
	int i,n,j,k,tval,flag,wt[100],wp[100],fval;
	int gt[1000];
	printf("JAI PRAKASH SHARMA(CE-2190-2K14)\n");
	printf("Enter the count of processes:");
	scanf("\n%d",&n);
	for(i=0;i<n;i++)
	{
		a.p[i]=i+1;
		printf("Enter data for %d process:",i+1);
		scanf("\t\t%d\t%d",&a.bt[i],&a.at[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a.at[i]>=a.at[j])
			{
				if(a.at[i]==a.at[j])
				{
					if(a.bt[i]>a.bt[j])
					{
						temp=a.p[i];
						a.p[i]=a.p[j];
						a.p[j]=temp;
						temp=a.bt[i];
						a.bt[i]=a.bt[j];
						a.bt[j]=temp;
						temp=a.at[i];
						a.at[i]=a.at[j];
						a.at[j]=temp;
					}
				}
				else
				{
					temp=a.p[i];
					a.p[i]=a.p[j];
					a.p[j]=temp;
					temp=a.bt[i];
					a.bt[i]=a.bt[j];
					a.bt[j]=temp;
					temp=a.at[i];
					a.at[i]=a.at[j];
					a.at[j]=temp;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("data for %d process is:",i+1);
		printf("\tP%d\t%d\t%d\n",a.p[i],a.bt[i],a.at[i]);
	}
	j=0;
	int in;
	int y=0;
	for(i=a.at[0];i<=a.at[n-1];i++)
	{
		j=0;
		in=0;
		while(a.at[j]<=i)
		{
			j++;
			in++;
		}
			val=a.bt[0];
			loc=0;
			for(k=0;k<in;k++)
			{
				if((val>a.bt[k])&&(a.bt[k]>0))
				{
					val=a.bt[k];
					loc=k;
				}
			}
				a.bt[loc]=a.bt[loc]-1;
				x.p[y]=a.p[loc];
				x.t1[y]=i;
				x.t2[y]=i+1;
				y++;
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
					if(a.bt[i]>a.bt[j])
					{
						temp=a.p[i];
						a.p[i]=a.p[j];
						a.p[j]=temp;
						temp=a.bt[i];
						a.bt[i]=a.bt[j];
						a.bt[j]=temp;
						temp=a.at[i];
						a.at[i]=a.at[j];
						a.at[j]=temp;
					}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a.bt[i]>0)
		{
			x.p[y]=a.p[i];
			x.t1[y]=x.t2[y-1];
			x.t2[y]=x.t1[y]+a.bt[i];
			y++;	
		}
	}
	printf("\nGhantt chart is:\n");
	for(i=0;i<y;i++)
	{
		printf("\nP%d\t%d\t%d",x.p[i],x.t1[i],x.t2[i]);
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		tval=0;
		fval=0;
		for(j=0;j<y;j++)
		{
			if(a.p[i] == x.p[j])
			{
				if(flag==1)
				{
					wt[i]=x.t1[j]-tval+fval;
					wp[i]=a.p[i];
					fval=wt[i];
					tval=x.t2[j];
				}
				if(flag==0)
				{
					flag=1;
					wt[i]=x.t1[j]-a.at[i];
					wp[i]=a.p[i];
					fval=wt[i];
					tval=x.t2[j];
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(wp[i]<wp[j])
			{
				temp=wp[i];
				wp[i]=wp[j];
				wp[j]=temp;
				
				temp=wt[i];
				wt[i]=wt[j];
				wt[j]=temp;
			}
		}
	}
	printf("\nWaiting time is:\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d",wp[i],wt[i]);
	}
	for(i=0;i<n;i++)
	{
		awt=wt[i]+awt;
	}
	printf("\nAverage waiting time is: %d",awt/n);
}
