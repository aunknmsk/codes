#include<stdio.h>
#include<math.h>

void heapify(int arr[10], int n, int i)
{
    int largest = i,temp;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    { 		
    	temp=arr[i];
    	arr[i]=arr[largest];
    	arr[largest]=temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[10], int n)
{
	int i,temp;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for ( i=n-1; i>=0; i--)
    {
    
    		temp=arr[i];
    		arr[i]=arr[0];
    		arr[0]=temp;
        heapify(arr, i, 0);
    }
    print(arr,n);
 }
 
int print(int arr[10], int n)
{
	int i;
	printf("\n  program::");
	for ( i=0; i<n; ++i)
	    	printf("\t%d",i+1);	
    	printf("\n");
    	printf("   length::");
    	for ( i=0; i<n; ++i)
      		printf("\t%d",arr[i]);
}
void accept(int a[10],int n)
{
	  int i;
	 
	  for(i=0;i<n;i++)
	  {
	  	printf("\nEnter length of program %d = ",i+1);
	  	scanf("%d",&a[i]);
	  }
}

void display(int a[10],int n)
{
	int i;
	printf("\n\nprogram order is: ");
	for(i=0;i<n;i++)
	{
		
		printf("\t%d",a[i]);
	}	    
}

void optimal(int a[10],int n)
{
	  int k=0,i,k1;
	  int temp,s[10];
	  for(i=0;i<n;i++)
	  {
	  			
	  		temp=a[i]+temp;	  			
	  		s[i]=temp;
	  }
	 
	  for(i=0;i<n;i++)
	  	k=s[i]+k;
	   printf("\ntotal retrieval time is %d ",k);
	  k1=k/n;
	  printf("\nmean retrieval time is %d ",k1);
}
void main()
{
		int i,j,ch,n,a[10];
		 printf("\nenter no. of programs : ");
	  	scanf("%d",&n);	 
		do
		{
					printf("\n1)accept\n2)display order\n3.optimal\n\nenter your choice : ");
					scanf("%d",&ch);
					switch(ch)
					{
								case 1:accept(a,n);
									break;
								case 2:heapSort(a,n);
									break;
								case 3:optimal(a,n);
									break;
					}
			}while(ch!=4);
}	


/*
 cc optimal_tape50.c
[Student@localhost ~]$ ./a.out

enter no. of programs : 3

1)accept
2)display order
3.optimal

enter your choice : 1

Enter length of program 1 = 3

Enter length of program 2 = 6

Enter length of program 3 = 9

1)accept
2)display order
3.optimal

enter your choice : 2

  program::	1	2	3
   length::	3	6	9
1)accept
2)display order
3.optimal

enter your choice : 3

total retrieval time is 30 
mean retrieval time is 10 
1)accept
2)display order
3.optimal

enter your choice : 
*/
	
