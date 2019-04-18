#include<stdio.h>
#include<stdlib.h>

#define INFINITY 9999

int g[10][10],rm[10][10],parent_cost=0,nov,visited[10],val;
int rnodes[10],rcount,path[10],pcount,final_cost=0,temp[10][10],cost[10];

void init(int g[10][10],int nov)
{
	int i,j;
	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			g[i][j]=INFINITY;
		}
	}
}

void accept(int g[10][10],int nov)
{
	int i,j;
	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			if(i!=j)
			{
				printf("\nEnter the %d and %d value:=",i,j);
				scanf("%d",&g[i][j]);
			}
		}
	}
}

void display(int g[10][10],int nov)
{
	int i,j;
	for(i=1;i<=nov;i++)
	{
		printf("\n");
		for(j=1;j<=nov;j++)
		{	
			printf("%d\t",g[i][j]);
		}
	}
}

void copy(int g[10][10],int rm[10][10],int nov)
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

int reduce(int rm[10][10],int nov)
{
	int i,j,totalrow=0,totalcol=0;
	int min;
	for(i=1;i<=nov;i++)
	{
		min=INFINITY;
		for(j=1;j<=nov;j++)
		{
			if(min>rm[i][j])
			min=rm[i][j];
		}
		
		if(min!=0 && min!=INFINITY)
		{
			for(j=1;j<=nov;j++)
			{
				if(rm[i][j]!=INFINITY)
				rm[i][j]=rm[i][j]-min;
			}
		totalrow=totalrow+min;
		}
	}
	
	for(j=1;j<=nov;j++)
	{
		min=INFINITY;
		for(i=1;i<=nov;i++)
		{
			if(min>rm[i][j])
			min=rm[i][j];
		}
		
		if(min!=0 && min!=INFINITY)
		{
			for(i=1;i<=nov;i++)
			{
				if(rm[i][j]!=INFINITY)
				rm[i][j]=rm[i][j]-min;
			}
		totalcol=totalcol+min;
		}
	}
	display(rm,nov);
	printf("\nthe reduced matrix is: ");
	printf("\ntotal row min value %d",totalrow);
	printf("\ntotal col  min value %d",totalcol);
	return (totalrow+totalcol);
}

void findmin(int cost[10],int rnodes[10],int rcount)
{
	int i,nextnode;
	int min=INFINITY;
	for(i=1;i<rcount;i++)
	{
		if(min>cost[i])
		{
			min=cost[i];
			nextnode=rnodes[i];
		}
	}
		visited[nextnode]=1;
		printf("\nSelected node in path is %d ",nextnode);
		path[pcount]=nextnode;
		pcount++;

}
		
void calcrnode()
{
	int v;
	rcount=1;
	for(v=1;v<=nov;v++)
	{
		if(visited[v]==0)
		{
			rnodes[rcount]=v;
			rcount++;
		}
	}
}

int TSP(int rm[10][10],int nov)
{ int i,j,k;
	
	
	//a.cal cost for rnodess..
	for(i=1;i<rcount;i++)
	{
		copy(rm,temp,nov);//copy into temp matrix
			
			for(j=1;j<pcount;j++)
			{
				for(k=1;k<=nov;k++)
				{
					temp[path[j]][k]=9999;//set row inf
					if(j!=1)//except 1 vettex in path become col inf
						temp[k][path[j]]=9999;
					

				}
			}
			//set new vertex rnodes as finity..		
			for(k=1;k<=nov;k++)
			{
				temp[k][rnodes[i]]=9999;
			}
			temp[rnodes[i]][1]=9999;//set (i,1)=infinity

			val=reduce(temp,nov);
			
			cost[i]=parent_cost+val;
                       printf("\n Lower bound=%d val=%d",parent_cost,val);
			for(j=1;j<pcount-1;j++)
			{
				cost[i]=cost[i]+ rm[path[j]][path[j+1]];
				
			}
			cost[i]=cost[i]+rm[path[j]][rnodes[i]];
			printf("\n Cost of %d remaing node is %d",rnodes[i],cost[i]);
	}
	
			
			findmin(cost,rnodes,rcount);
			calcrnode();
			if(rcount!=1)
			{
				TSP(rm,nov);
			}
			else
			{
				for(j=1;j<pcount;j++)
					{
						printf("\t%d-",path[j]);
					}
				final_cost=parent_cost;
				for(j=1;j<pcount-1;j++)
				{
					final_cost=final_cost+rm[path[j]][path[j+1]];
				}
			}
	
	return final_cost;
}
		
void main()
{
	int opt,v,finalcost,val;
	do
	{
	      printf("\n 1.Accept  \n 2.Display \n  3.Reduce matrix \n 4.TSP\n5.Exit\n  Enter Your choice : ");
	      scanf("%d",&opt);
	      switch(opt)
	      {
	      		case 1:printf("\nEnter the number:=");
	      			scanf("%d",&nov);
	      			init(g,nov);
	      			accept(g,nov);
	      			break;
	      			
	      		case 2:display(g,nov);
	      			break;
	      			
	      		case 3:copy(g,rm,nov);
	      			val=reduce(rm,nov);
	      			parent_cost=val;
	      			printf("lower bound is %d",val);
	      			break;
	      			
	      		case 4:pcount=1;
	      			path[1]=1;
	      			pcount++;
	      			for(v=1;v<=nov;v++)
	      			visited[v]=0;
	      			visited[1]=1;
	      			calcrnode();
	      			finalcost=TSP(rm,nov);
	      			printf("minimum cost is %d",finalcost);
	      			break;
	      			
	      		case 5:break;
	      	}
	}while(opt!=5);
}
	
