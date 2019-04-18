/*Write a recursive program to find the solution of placing n queens on chessboard so that no two queens attack each other using Backtracking.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x[30],soln=0;
 
void  print(int n)
{
	int i,j;
	printf("\nSolution no %d\t:",soln++);
	for(i=0;i<n;i++)
	{
		printf("\t%d",i);
	}
	for(i=0;i<n;i++)
	{
		printf("\n\t\t");
		printf("%d",i);
		for(j=0;j<=n-1;j++)
		{
			if(x[i]==j)
			printf("\tQ");
			else
			printf("\t-");
		}
	}
	printf("\n\t");
}
  
int place(int k,int i)
{
	for(int j=0;j<k;j++)
	{
		if(x[j]==i)
			return 0;
		else if(abs(x[j]-i)==abs(j-k))
			return 0;
	}	
	return 1;
}

 
void Nqueens(int k,int n)
{
 	for(int i=0;i<n;i++)
 	{
 		if(place(k,i))
 		{
 			x[k]=i;
 			if(k==n-1)
 			{
 				print(n);
 				printf("\n\nVector is:");
 				for(k=0;k<=n-1;k++)
					printf("%d\t",x[k]);
 			}
 			else
 			{
 				Nqueens(k+1,n);
 			}
 		}
 	}
 }
 

int main()
{
int i,j,n;

printf("\n\nEnter number of Queens:");
scanf("%d",&n);
Nqueens(0,n);
printf("\n\ntotal solution: %d\n",soln);
return 0;
} 
