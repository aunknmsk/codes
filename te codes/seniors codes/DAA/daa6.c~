#include<stdio.h>
#include<string.h>
#define INFINITY 9999
int temp[20][20],rm[20][20],g[20][20],cost[20],pcount,rcount,nov,rnodes[20],path[20];
int lb,parent_cost=0,visited[20];

void init(int g[20][20],int nov)
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

void init_visited(int visited[20],int nov)	
{
	int v;
	for(v=1;v<=nov;v++)
	{
		visited[v]=0;
	}
}

void accept(int g[20][20],int nov)
{
	int i,j;
	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			if(i!=j)
			{
				printf("\nEnter the %d and %d elements:=",i,j);
				scanf("%d",&g[i][j]);
			}
		}
	}
}

void display(int g[20][20],int nov)
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

void copy(int g[20][20],int rm[20][20],int nov)
{
	int i,j;
	for(i=0;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			rm[i][j]=g[i][j];
		}
	}
}

int reduce(int rm[20][20],int nov)
{
	int i,j,min,totalrow=0,totalcol=0,total=0;
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
	printf("\nTotal minimum row cost is: %d",totalrow);
	printf("\nTotal minimum col cost is: %d",totalcol);
	total=totalrow+totalcol;
	printf("\nTotal reduced cost is %d",total);
	return (total);
}

void findmin(int cost[],int rnodes[20],int rcount)
{
	int i,min=INFINITY,nextnode;
	for(i=1;i<rcount;i++)
	{
		if(min>cost[i])
		{
			min=cost[i];
			nextnode=rnodes[i];
		}
	}
	visited[nextnode]=1;
	printf("\nSelected nextnode is %d ",nextnode);
	path[pcount]=nextnode;
	pcount++;
}

void calcrnodes()
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

void tsp(int rm[20][20],int nov)
{
	int p,i,j,final_cost,val;
	int k;
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
			temp[k][rnodes[i]]=INFINITY;
		}
		temp[rnodes[i]][1]=INFINITY;
		
		val=reduce(temp,nov);
		
		cost[i]=parent_cost+val;
		printf("\n lower bound %d is %d",parent_cost,val);
		for(j=1;j<pcount-1;j++)
		{
			cost[i]=cost[i]+rm[path[j]][path[j+1]];
		}
		cost[i]=cost[i]+rm[path[j]][rnodes[i]];
		printf("\ncost of %d is remaining %d is ",rnodes[i],cost[i]);
	}
	
	findmin(cost,rnodes,rcount);
	calcrnodes();
	if(rcount!=1)
	{
		tsp(rm,nov);
	}
	else
	{
		for(j=1;j<pcount;j++)
		{
			printf("%d->",path[j]);
		}
		final_cost=parent_cost;
		for(j=1;j<pcount-1;j++)
		{
			final_cost=final_cost+rm[path[j]][path[j+1]];
		}
	printf("\nTotal cost is: %d\n",final_cost);
	}
}
		
void main()
{
	int opt,lb,val;
	do
	{
		printf("\n1.Accept\n2.Display\n3.Reduce\n4.TSP\n5.exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:printf("\nEnter the no of vertices:=");
				scanf("%d",&nov);
				init(g,nov);
				accept(g,nov);
				break;
				
			case 2:display(g,nov);
				break;
				
			case 3:copy(g,rm,nov);
				lb=reduce(rm,nov);
				parent_cost=lb;
				break;
				
			case 4:
				pcount=1;
				path[1]=1;
				pcount++;
				init_visited(visited,nov);
				visited[1]=1;
				calcrnodes();
				tsp(rm,nov);
				break;
				
			case 5:break;
		}
	}while(opt!=5);
}
