#include<stdio.h>
int g[10][10],visited[10],n,cost;

void accept()
{
	int i,j;
	printf("\nEnter the vertices:=");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter the %d row:=",i+1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
		visited[i]=0;
	}
	
	printf("\nCost Matrix:==\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",g[i][j]);
		}
	}
}

void mincost(int city)
{
	int ncity,i;
	visited[city]=1;
	printf("%d--->",city+1)
	ncity=least(city);
	if(ncity==999)
	{
		ncity=0;
		printf("%d\t",ncity+1);
		cost=cost+g[city][ncity];
	}
	mincost(ncity);
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=0;i<n;i++)
	{
		if((g[c][i]!=0) && (visited[i]==0))
		{
			if(g[c][i]<min)
			{
				min=g[i][0]+g[c][i];
				kmin=g[c][i];
				nc=i;
			}
		}
	}
	if(min!=999)
	cost=cost+kmin;
	return nc;
}

}

void main()
{
	accept();
	printf("\nPath is:=");
	mincost(0);
	printf("\nMinimum cost is: %d",cost);
}