#include<stdio.h>

int min,max,min1,max1,a[50];

void minmax(int i,int j,int min,int max)
{
	printf("\npart under consideration :");
	for(int k = i; k<j;k++)
	printf(" %d ",a[k]);
	
	
	if(i==j)
	{
		min1=max1=max=min=a[i];
	}
	
	else if(i==j-1)
	{
		if(a[i]>=a[j])
		{
			max=a[i];
			min=a[j];
		}
		else
		{
			max=a[j];
			min=a[i];
		}
	}
	
	else
	{
		int mid=(i+j)/2;
		minmax(i,mid,min,max);
	//	max1=max;min1=min;	
		minmax(mid+1,j,min1,max1);
		if(max<max1)
		max=max1;
		if(min>min1)
		min=min1;
	}
	
	printf("\n\nmin element -> %d max element -> %d",min,max );
}

int main()
{
	int num,i;
	printf("\nEnter the number of elements:");
	scanf("%d",&num);
	printf("\nelement the elements->\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}
	/*max=a[0];
	min=a[0];*/
	
	
	minmax(0,num,min,max);
	return 0;
}













