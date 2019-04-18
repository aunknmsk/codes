#include<stdio.h>
#include<stdlib.h>

struct edge
{
	int u,v,w;
};

struct output
{
	int vertex,weight,pi;
};

struct edge edge[20];
struct output output[20];
int vertex,ed;
int i;

void accept()
{
	printf("\nEnter the number of vertices:=");
	scanf("%d",&vertex);
	printf("\nEnter the number of edges:=");
	scanf("%d",&ed);
	for(i=1;i<=ed;i++)
	{
		printf("\nEnter source , destination and weight:=");
		scanf("%d",&edge[i].u);
		scanf("%d",&edge[i].v);
		scanf("%d",&edge[i].w);
	}
}

void display()
{
	printf("\nMatrix:\n");
	for(i=1;i<=ed;i++)
	{
		printf("\n%d\t%d\t%d",edge[i].u,edge[i].v,edge[i].w);
	}
}

void bellman_ford()
{
	int j,U,V,W;
	int iteration=ed-1;
	for(i=1;i<=iteration;i++)
	{
		output[i].vertex=i;
		output[i].weight=1000;
		output[i].pi=1;
	}
	output[1].weight=0;
	output[1].pi=1;
	
	for(i=1;i<=iteration;i++)
	{
		for(j=1;j<=ed;j++)
		{
			U=edge[j].u;
			V=edge[j].v;
			W=edge[j].w;
				
		if((output[U].weight+edge[j].w)<output[V].weight)
		{
			output[V].weight=output[U].weight+edge[j].w;
			output[V].pi=U;
		}
		}
	}
	
	for(i=1;i<=vertex;i++)
	{
		printf("\n%d\t%d\t%d",output[i].vertex,output[i].weight,output[i].pi);
	}
}

void main()
{
	int opt;
	do
	{
		printf("\n1.Accept\n2.Display\n3.bellman\n4.exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:accept();
				break;
				
			case 2:display();
				break;
				
			case 3:bellman_ford();
				break;
				
			case 4:break;
		}
	}while(opt!=4);
}	 
