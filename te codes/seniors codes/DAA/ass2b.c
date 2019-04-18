#include<stdio.h>
int a[30];
void heapify(int a[10],int n,int i)
{
	int largest=i,temp;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && a[l]>a[largest])
	largest=l;
	
	if(r<n && a[r]>a[largest])
	largest=r;
	
	if(largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		heapify(a,n,largest);
	}
}

void heap(int a[10],int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
	heapify(a,n,i);
	for(i=n-1;i>=0;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);
	}
	//print(a,n);
}

void optimal(int a[20],int n)
{
	int temp[10],s[20][20],k1[20],p=-1,k=0,i,tape[20][20],counter[20],j,final=0;
	int ntape;
	printf("\nEnter the number of tape:=");
	scanf("%d",&ntape);
	for(i=0;i<30;i++)
	k1[i]=0,temp[i]=0;
	for(i=0;i<n;i++)
	{
		k=i%ntape;
		if(k==0)
		{
			p++;
		}
		tape[k][p]=a[i];
		counter[k]=p;
	}
	
	for(i=0;i<ntape;i++)
	{
		for(j=0;j<=counter[i];j++)
		{
			printf("%d\t",tape[i][j]);
			temp[i]=tape[i][j]+temp[i];
			s[i][j]=temp[i];
		}
		printf("\n");
	}
	
	for(i=0;i<ntape;i++)
	{
		for(j=0;j<=counter[i];j++)
		{
			k1[i]=s[i][j]+k1[i];
		}
	}
	for(i=0;i<ntape;i++)
	{
		final=final+k1[i];
	}
		printf("\nRetrival time %d\n",final);
}

void main()
{
	int a[100],i,n;
	printf("\nEnter no:=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	heap(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n\n");
	optimal(a,n);
}
	
