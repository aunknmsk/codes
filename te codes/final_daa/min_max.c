#include<stdio.h>
int arr[100];
int min,max;
int n;


void min_max(int i,int j)
{

	int min1,max1,mid;
	
	if(i==j)
	{
		min = max = arr[i];
	}
	
	else if(i == j-1)
	{
		if(arr[i] < arr[j])
		{
			min = arr[i];
			max = arr[j];
	        }
	        
	        else
	        
	        {	
	        	min = arr[j];
	        	max = arr[i];
	        }
	        
	 }
	 
	 
	 else
	 {
	 	mid = (i+j)/2;
	 	
	 	min_max(i,mid);
	 	min1 = min;
	 	max1 = max;
	 	
	 	min_max(mid+1,j);
	 	
	 	
	 	if(min > min1)
	 		min = min1;
	 	
	 		
	 	if(max < max1)
	 		max = max1;
	 		
	 	
	 }       
	 
	 
	 
	 
	 
}

int main()
{
	printf("\n Enter array size:");
	scanf("%d",&n);
	
	printf("\nEnter elements in array:");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	min=arr[0];
	max = arr[0];
	
	min_max(1,n);
	
	printf("\n\nmin = %d max = %d",min,max );
	
	return 0;
}
