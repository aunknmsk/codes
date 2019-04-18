#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999 

//20 30 10 11 15 16 4 2 3 5 2 4 19 6 18 3 16 4 7 16
int lb,cost[10],path[10],rcount,visited[10],rnode[10],pcount=1,temp[20][20];

void init(int g[][20], int nov)
{
int i,j;
for(i=1;i<=nov;i++)			
	{
	for(j=1;j<=nov;j++)
	g[i][j]=INFINITY;
	}
}

void init_visited(int visited[10], int nov)
{
int i,j;
for(i=1;i<=nov;i++)			
	{
	visited[i]=0;
	}

}


void accept(int g[][20],int nov)
{
	int i,j,val;
	
	for(i=1;i<=nov;i++)			
	{
		for(j=1;j<=nov;j++)
		{
			if(i!=j)
			{
			printf("Enter the value for %d and %d\n",i,j);
			scanf("%d",&val);
			g[i][j]=val;
			}
		}
	}
	

}

void display(int g[][20],int nov)
{
int i,j;

	
	for(i=1;i<=nov;i++)			
	{
		printf("\n");
		for(j=1;j<=nov;j++)
			printf("%d \t",g[i][j]);
	}
}

void copy(int g[][20],int rm[][20],int nov)
{
int i,j;

	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			rm[i][j]=g[i][j];
		}
	}
}

int reduced(int rm[][20],int nov)
{
int i,j,totalrow=0,totalcol=0,min;
	for(i=1;i<=nov;i++)
	{
		min= INFINITY;
		for(j=1;j<=nov;j++)
		{
			if(min>rm[i][j])
			min =rm[i][j];
		}

		if(min !=0 && min != INFINITY)
		{
			for(j=1;j<=nov;j++)
			{
				if(rm[i][j] != INFINITY)
				rm[i][j]=rm[i][j] - min;
			}
			totalrow=totalrow + min;
		}
	}
	
	//column reduced logic same as row reduce logic,just change the loop-it will be opp
	
	for(j=1;j<=nov;j++)
	{
		min= INFINITY;
		for(i=1;i<=nov;i++)
		{
			if(min>rm[i][j])
			min =rm[i][j];
		}

		if(min !=0 && min != INFINITY)
		{
			for(i=1;i<=nov;i++)
			{
				if(rm[i][j] != INFINITY)
				rm[i][j]=rm[i][j] - min;
			}
			totalcol = totalcol + min;
		}
	}
return totalrow + totalcol;
}

void calrnodes(int rnode[],int nov)
{
int v;
	rcount=1;

	for(v=1;v<nov;v++)
	{
		
		if(visited[v]==0)
		{
			rnode[rcount]=v;
			rcount++;
		}
	}
}

void findmin(int cost[],int rnode[], int rcount)
{
int min=INFINITY;
int i,nextnode;
	for(i=1;i<rcount;i++)
	{
		if(min>cost[i])
                      {
                       min=cost[i];
		       nextnode=rnode[i];
                      }
	}
	visited[nextnode]=1;
	path[pcount]=nextnode;
	pcount++;
printf("\n\n Selected a node with mini cost is=%d",nextnode);
printf("\n-----------------------------------------------------");
}

void tsp(int rm[][20],int nov)
{
	int i,j,k,val,p,finalcost;

	for(i=1;i<rcount;i++)
	{
			copy(rm,temp,nov);
	

			for(j=1;j<pcount;j++)
			{	
				for(k=1;k<=nov;k++)
				{
				temp[path[j]][k]=INFINITY;
			
				if(j!=1)
					temp[k][path[j]]=INFINITY;			
				}			
			}
		
			for(k=1;k<=nov;k++)
			{
				temp[k][rnode[i]]=INFINITY;	
			}
		
			temp[rnode[i]][1]=INFINITY;
			val=reduced(temp,nov);

			cost[i]=lb+val;
		
		
			for(p=1;p<pcount-1;p++)
			{
			 cost[i]=cost[i]+rm[path[p]][path[p+1]];
		
			}
		        cost[i]=cost[i]+rm[path[p]][rnode[i]];
			printf("\n\t Cost of %d remaining node =  %d",rnode[i],cost[i]);
		
		}
			findmin(cost,rnode,rcount);
			calrnodes(rnode,nov);		

			if(rcount!=1)
			       tsp(rm,nov);
			else
			{
				printf("\nTSP path is :\n");
				for(k=1;k<pcount;k++)
				{
				      printf("%d->",path[k]);
				}
				printf("%d",path[1]);

				finalcost=lb;
				for(p=1;p<pcount-1;p++)
				      finalcost=finalcost+rm[path[p]][path[p+1]];
				printf("\nMinimum TSP path is :%d",finalcost);
			}
		
	
}

void main()
{
int opt,nov,x[20],g[20][20],rm[20][20];
	do
	{
	printf("\nEnter your choice:\n 1.Accept the graph\n 2.display\n 3.Reduce \n 4.TSP \n 5.stop\n");
	scanf("%d",&opt);

		switch(opt)
		{
		case 1:
		printf("Enter no of vertices: \n");	//accept no of vertices
		scanf("%d",&nov);
		init(g,nov);
		accept(g,nov);
		break;
		case 2:
		display(g,nov);
		break;
		case 3:
		copy(g,rm,nov);
		lb=reduced(rm,nov);
		printf("Lower Bound on tsp is %d",lb);
		display(rm,nov);
		break;
		case 4:
		init_visited(visited,nov);
			pcount=1;
			path[1]=1;
			pcount++;
			visited[1]=1;
		
			calrnodes(rnode,nov);
			tsp(rm,nov);
		break;
		}
	}while(opt!=5);
}

/*Output:

[Student@localhost ~]$ cd 331033
[Student@localhost 331033]$ gcc ass6.c
[Student@localhost 331033]$ ./a.out

Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
1
Enter no of vertices: 
4
Enter the value for 1 and 2
10
Enter the value for 1 and 3
13
Enter the value for 1 and 4
20
Enter the value for 2 and 1
13
Enter the value for 2 and 3
2
Enter the value for 2 and 4
4
Enter the value for 3 and 1
8
Enter the value for 3 and 2
4
Enter the value for 3 and 4
3
Enter the value for 4 and 1
8
Enter the value for 4 and 2
8
Enter the value for 4 and 3
9

Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
2

9999 	10 	13 	20 	
13 	9999 	2 	4 	
8 	4 	9999 	3 	
8 	8 	9 	9999 	
Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
3
Lower Bound on tsp is 23
9999 	0 	3 	10 	
11 	9999 	0 	2 	
5 	1 	9999 	0 	
0 	0 	1 	9999 	
Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
4

	 Cost of 2 remaining node =  23
	 Cost of 3 remaining node =  28

 Selected a node with mini cost is=2
-----------------------------------------------------
	 Cost of 3 remaining node =  23

 Selected a node with mini cost is=3
-----------------------------------------------------
TSP path is :
1->2->3->1
Minimum TSP path is :23
Enter your choice:
 1.Accept the graph
 2.display
 3.Reduce 
 4.TSP 
 5.stop
5
[Student@localhost 331033]$ 
*/

