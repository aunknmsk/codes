#include<stdio.h>
#include<math.h>

void heapify(int a[10],int n,int i)
{
	int largest=i,temp;
	int l= 2*i+1;
	int r= 2*i+2;
	
	if(l<n && a[l]>a[largest])
	{
		largest=l;
	}
	
	if(r<n && a[r]> a[largest])
	{
		largest=r;
	}
	
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;	
		heapify(a,n,largest);
	}
}

void heapsort(int a[10],int n)
{
	int i,temp;
	for(i= n/2 -1;i>=0;i--)
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

int print(int a[10],int n)
{
	int i;
	printf("\nProgram:");
	for(i=0;i<n;i++)
	printf("\t%d",i+1);
	printf("\nLength:");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
}

void accept(int a[10],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter the length of the program %d",i+1);
		scanf("%d",&a[i]);
	}
}

void optimal(int a[10],int n)
{
	int i,k=0,k1,temp=0,s[10];
	for(i=0;i<n;i++)
	{
		temp=a[i]+temp;
		s[i]=temp;
	}
	for(i=0;i<n;i++)
		k=s[i]+k;
	printf("\nTotal time retrival is: %d",k);
	k1=k/n;
	printf("\nMean time retrival is %d",k1);
}
		
void main()
{
	int opt,n,a[10];
	printf("\nEnter the number:=");
	scanf("%d",&n);
	do
	{
		printf("\n1.Accept\n2.Display in order\n4.Exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:accept(a,n);
				break;
				
			case 2:heapsort(a,n);
				break;
				
			case 3:optimal(a,n);
				break;
				
			case 4:break;
		}
	}while(opt!=4);
}

