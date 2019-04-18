/* ASSIGNMENT NO-03

PROBLEM STATEMENT-Write a program to implement Bellman-Ford Algorithm using Dynamic Programming and verify the time complexity.

NAME-Gauri Godase.
ROLL NO-3322
CLASS-TE IT
*/


#include<stdio.h>
#include<stdlib.h>
int bellman_ford(int G[20][20],int V,int E,int edge[20][2])
{
	int i,u,v,k,distance[20],parent[20],s,flag=1;
	for(i=0;i<V;i++)
		distance[i]=1000,parent[i]=-1;
		printf("Enter source: ");
		scanf("%d",&s);
		distance[s-1]=0;
	for(i=0;i<V-1;i++)
	{
		for(k=0;k<E;k++)
		{
			u=edge[k][0],v=edge[k][1];
			if(distance[u]+G[u][v]<distance[v])
			   distance[v]=distance[u]+G[u][v],parent[v]=u;
		}
	}
	for(k=0;k<E;k++)
		{
			u=edge[k][0],v=edge[k][1];
			if(distance[u]+G[u][v]<distance[v])
				flag=0;
		}
		if(flag)
			for(i=0;i<V;i++)
				printf("vertex  %d ->cost=%d parent=%d\n",i+1,distance[i],parent[i]+1);
				return flag;
}

int main()
{
	int V,edge[20][2],G[20][20],i,j,k=0;
	printf("BELLMAN FORD\n");
	printf("Enter number of vertices:\n");
	scanf("%d",&V);
	printf("Enter graph in matrix form:\n");
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
		{
			scanf("%d",&G[i][j]);
			if(G[i][j]!=0)
			edge[k][0]=i,edge[k++][1]=j;
		}
		if(bellman_ford(G,V,k,edge))
			printf("\nNO negative weight cycle\n");
		else 
			printf("\n negative cycle exits\n");
		return 0;	
}					
			


/****************************OUTPUT********************************

nayan@ubuntu:~$ cd Desktop
nayan@ubuntu:~/Desktop$ gcc bellman.c
nayan@ubuntu:~/Desktop$ ./a.out
BELLMAN FORD
Enter number of vertices:
5
Enter graph in matrix form:
0 3 -1 -4 0
0 0 -1  0 2
0 0  0 -3 0
0 0  0  0 0 
0 0  0  3 0
Enter source: 1
vertex  1 ->cost=0 parent=0
vertex  2 ->cost=3 parent=1
vertex  3 ->cost=-1 parent=1
vertex  4 ->cost=-4 parent=1
vertex  5 ->cost=5 parent=2

NO negative weight cycle
nayan@ubuntu:~/Desktop$ 
*/
