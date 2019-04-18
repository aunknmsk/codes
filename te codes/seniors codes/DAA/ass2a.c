#include<stdio.h>
int a[10],n;

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
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}

void print(int a[10],int n)
{
	int i;
	printf("\nProgram:=\t");
	for(i=0;i<n;i++)
	printf("%d\t",i+1);
	printf("\nLength:\t");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
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
	print(a,n);
}

void optimal(int a[10],int n)
{
	int k=0,k1,temp=0,s1[10],i;
	for(i=0;i<n;i++)
	{	
		temp=a[i]+temp;
		s1[i]=temp;
	}
	
	for(i=0;i<n;i++)
	k=s1[i]+k;
	printf("\nTotal retrieval time is %d",k);
	k1=k/n;
	printf("\nTotal retrieval time is %d",k1);
}
void accept(int a[10],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter the program %d length",i+1);
		scanf("%d",&a[i]);
	}
}

void main()
{
	int n,opt;
	printf("\nEnter the number of prgrams:-");
	scanf("%d",&n);
	do
	{
		printf("\n1.Accept\n2.Display\n3.optimal\n4.exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:		
				accept(a,n);
				break;
				
			case 2:heap(a,n);
				break;
				
			case 3:optimal(a,n);
				break;
				
			case 4:break;
		}
	}while(opt!=4);
}
