#include<stdio.h>
int a[30];
void heapify(int a[],int n,int i)
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
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}

void heap(int a[],int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);
	}
}
void optimal(int a[],int n)
{
	int i,j,k=0,k1[30],temp[30],s[10][10],ntape,tape[20][20],p=-1,counter[10],final=0;
	
	printf("Enter the no of tape\n");
	scanf("%d",&ntape);
	
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
	printf("\n");
		for(i=0;i<ntape;i++)
		{
		for(j=0;j<=counter[i];j++)
		{
			printf("%d\t",tape[i][j]);
			temp[i]=temp[i]+tape[i][j];
			s[i][j]=temp[i];
			
		}
		printf("\n");
	}	
	
	for(i=0;i<30;i++)
		k1[i]=0,temp[i]=0;
	for(i=0;i<ntape;i++)
	{
		for(j=0;j<=counter[i];j++)
		{
			k1[i]=k1[i]+s[i][j];
		}
	}
	
	for(i=0;i<ntape;i++)
	{
		final=final+k1[i];
	}
	
	printf("min retrieval time = %d\n",final);
}
int main()
{
	int n,i;
	printf("Enter the number\n");
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
