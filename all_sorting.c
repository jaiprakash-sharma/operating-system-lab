#include<stdio.h>
#include<conio.h>
int b[100];
void merge(int a[],int low,int high);
void merge_sort(int a[],int low,int mid,int high);
void quick_sort(int b[],int low,int high);
int partition(int b[],int low,int high);
void main()
{
	int z[100],i,j,n,temp,low,high,ch;
	printf("JAI PRAKASH SHARMA(CE-2190-2K14)\n");
	printf("Enter the size of list:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element:\n",i+1);
		scanf("%d",&z[i]);	
	}
	do
	{
		int a[1000];
		for(i=0;i<n;i++)
		{
			a[i]=z[i];
		}
		printf("======MENU======\n");
		printf("1-Selection Sort\n");
		printf("2-Bubble sort\n");
		printf("3-Insertion Sort\n");
		printf("4-Merge Sort\n");
		printf("5-Quick Sort\n");
		printf("6-Exit\n");
		printf("Enter your chooice\n");
		scanf("\t%d",&ch);
		switch(ch)
		{
			case 1:
			{
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
				for(i=0;i<n;i++)
				{
					for(j=i+1;j<n;j++)
					{
						if(a[i]>a[j])
						{
							temp=a[i];
							a[i]=a[j];
							a[j]=temp;
						}
					}
				}
				printf("The sorted list is:\n");
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
			}
			break;
			case 2:
			{
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
				for(i=0;i<(n);i++)
				{  
					for(j=0;j<n-1-i;j++)
					{
						if(a[j]>a[j+1])
						{
							temp=a[j];
							a[j]=a[j+1];
							a[j+1]=temp;
						}
					}
				}
				printf("The sorted list is:\n");
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
			}
			break;
			case 3:
			{
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
				for(i=1;i<n;i++)
				{
					j=i-1;
					temp=a[i];
 			       while((temp<a[j])&&(j>=0))
					{
						if(temp<a[j])
						{
							a[j+1]=a[j];
							j=j-1;
					    }
					}
					a[j+1]=temp;
				}
				printf("The sorted list is:\n");
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
			}
			break;
			case 4:
			{
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
				merge(a,0,n-1);
				printf("The sorted list is:\n");
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
			}
			break;
			case 5:
			{
				for(i=0;i<n;i++)
				printf("%d\n",z[i]);
				low=0;
				high=n-1;
				quick_sort(a,low,high);	
				printf("The sorted list is:\n");
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
			}
			break;
				
		}
	}
	while(ch!=6);
}
void merge(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		merge(a,low,mid);
		merge(a,mid+1,high);
		merge_sort(a,low,mid,high);
	}
}
void merge_sort(int a[],int low,int mid,int high)
{
 int i=low;
 int p,n;
 int k=low;
 int j=mid+1;
 while((i<=mid)&&(j<=high))
 {
 	if(a[i]<a[j])
 	{
 		b[k]=a[i];
 		i++;
 		k++;
 	}
 	else
 	{
 		b[k]=a[j];
 		j++;
 		k++;
 	}
 }
 if(i>mid)
 {
 	for(p=j;p<=high;p++)
 	{
 		b[k]=a[p];
 		k++;
 	}
 }
 if(j>high)
 {
 	for(p=i;p<=mid;p++)
 	{
 		b[k]=a[p];
 		k++;
 	}
 }
 for(i=low;i<=high;i++)
 {
 	a[i]=b[i];
 }
}
void quick_sort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}
int partition(int a[],int low,int high)
{
	int pivot,i,j,temp;
	pivot=a[low];
	i=low+1;
	j=high;
	while(i<=j)
	{
		while(a[i]<=pivot)
		i=i++;
		while(a[j]>pivot)
		j=j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	a[low]=j;
	a[j]=pivot;
	return(j);
}
