#include<stdio.h>
#include<math.h>
 
int board[20],count;
 void queen(int a,int n);
int main()
{
int n,i,j;

 
printf(" - N Queens Problem Using Backtracking -");
printf("\n\nEnter number of Queens:");
scanf("%d",&n);
queen(1,n);
return 0;
}
 
//function for printing the solution
void print(int n)
{
int i,j;
printf("\n\nSolution %d:\n\n",++count);
 
for(i=1;i<=n;++i)
  printf("\t%d",i);
 
for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
}
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
 
return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void queen(int a,int n)
{
int column=1,row=1;
while(row>0)
{
	while(column<=n)
		{
			if(place(row,column))
 			 {
 			   board[row]=column; //no conflicts so place queen
 			  if(row==n) //dead end
 			  {
 			   print(n); //printing the board configuration
 			   }
 			   row++;
 			   column=1;
 		   	}
   			else //try queen with next position
  			 {
  				column++;
			}  
  		}
  if(column>n)
  {
  	row--;
  	column=board[row]+1;
  }
  }
}


/*OUTPUT:
[student@master ~]$ gcc queen1.c
[student@master ~]$ ./a.out
 - N Queens Problem Using Backtracking -

Enter number of Queens:4


Solution 1:

	1	2	3	4

1	-	Q	-	-

2	-	-	-	Q

3	Q	-	-	-

4	-	-	Q	-

Solution 2:

	1	2	3	4

1	-	-	Q	-

2	Q	-	-	-

3	-	-	-	Q

4	-	Q	-	-*/	


