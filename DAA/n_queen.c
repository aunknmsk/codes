#include<stdio.h>
#include<stdlib.h>
int n;

int place(int k,int col,int x[])
{
	for(int i=1;i<k;i++)
	{	
		if(col == x[i] || abs(i-k) == abs(x[i]-col))  // condition to check that col is not repeating and next queen is not in diagonal of other
		
		return 0;
	}
	
	return 1;
}

//if(col == x[i] || abs(i-k) == abs(x[i]-col))  // condition to


void nqueen(int x[],int k,int n)                      // x - >solution array , k -> queen number , n -> total number of queens/ dimensions 
{
	for (int col=1;col<=n;col++)
	{
		if (place(k,col,x))
		{
			x[k] = col;
			if(k==n) 
			{ 
				for(int i=1;i<=n;i++)                          // if its the last queen condition
				{
					printf(" %d ",x[i]);
				}
				
				printf("\n");
				
				
				for(int m=1;m<=n;m++)
				{
					for(int l=1;l<=n;l++)
					{
						if(l==x[m] )
							printf(" Q ");
						else
						
							printf(" _ ");
					}
					
					printf("\n");
				}
				
				
		        }
		        
		        printf("\n");
			nqueen(x,k+1,n);
		}
	}	
}




int main()
{
	printf("\nEnter the number of queens:\n");
	scanf("%d",&n);	
	
	int x[n];                     //solution array 
	
	nqueen(x,1,n);
	
	
	
	
	
	return 0;
}
