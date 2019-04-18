#include<stdio.h>

struct edge
{
	int u;
	int v;
	int w;
};

struct output
{
	int vertex;
	int weight;
	int pi;
};

struct edge edge[10];
struct output output[10];
int ed,vertex;

void accept()
{
	int i;
	printf("Enter number of vertex:");
	scanf("%d",&vertex);
	printf("Enter number of edges:");
	scanf("%d",&ed);
	for(i=1;i<=ed;i++)
	{
		printf("Enter source:");
		scanf("%d",&edge[i].u);
		
		printf("Enter destination:");
		scanf("%d",&edge[i].v);
		
		printf("Enter weight:");
		scanf("%d",&edge[i].w);
	}
}

void display()
{
	int i;
	printf("Source\tDestination\tWeight\n");
	for(i=1;i<=ed;i++)
	{
		printf("%d\t\t%d\t\t\t%d",edge[i].u,edge[i].v,edge[i].w);
		printf("\n");
	}
}

void bellman_ford()
{
	int i,j,V,U,WT;
	int flag=0;
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
			WT=edge[j].w;
			
			if((output[U].weight+edge[j].w)<output[V].weight)
			{
				output[V].weight=output[U].weight+edge[j].w;
				output[V].pi=U;
			}
		}
	}
	
	
	for(i=1;i<=1;i++)
	{
		for(j=1;j<=ed;j++)
		{
			if(flag!=1)
			{
				U=edge[j].u;
				V=edge[j].v;
				WT=edge[j].w;
			
				if((output[U].weight+edge[j].w)<output[V].weight)
				{
					printf("Negative cycle is present.\n");
					flag=1;
				}
			}
		}	
	}
	if(flag==0)
	{
		printf("Vertex\tDistance\tPi\n");
		for(i=1;i<=vertex;i++)
		{
			printf("%d\t%d\t\t%d",output[i].vertex,output[i].weight,output[i].pi);
			printf("\n");
		}
	}	
}

void main()
{

	int i,opt;
	do
	{
		printf("\nMenu\n1.Accept graph.\n2.Display graph.\n3.Shotest path.\n4.Exit.\n");
		printf("Enter your choice:\n");
		scanf("%d",&opt);
		
		switch(opt)
		{
			case 1:
					accept();
					break;
			case 2:
					display();
					break;
			case 3:
					bellman_ford();
					break;
		}
		
	}while(opt!=4);

}


/****OUPUT****
aditya@aditya-SVF15218SNW:~/DAA$ gcc bellman_fort1.c
aditya@aditya-SVF15218SNW:~/DAA$ ./a.out

Menu
1.Accept graph.
2.Display graph.
3.Shotest path.
4.Exit.
Enter your choice:
1
Enter number of vertex:7
Enter number of edges:10
Enter source:1
Enter destination:2
Enter weight:6
Enter source:1
Enter destination:3
Enter weight:5
Enter source:1
Enter destination:4
Enter weight:5
Enter source:4
Enter destination:3
Enter weight:-2
Enter source:4
Enter destination:6
Enter weight:-1
Enter source:3
Enter destination:2
Enter weight:-2
Enter source:3
Enter destination:5
Enter weight:1
Enter source:2
Enter destination:5
Enter weight:-1
Enter source:5
Enter destination:7
Enter weight:3
Enter source:6
Enter destination:7
Enter weight:3

Menu
1.Accept graph.
2.Display graph.
3.Shotest path.
4.Exit.
Enter your choice
Source	Destination	Weight
1		2			6
1		3			5
1		4			5
4		3			-2
4		6			-1
3		2			-2
3		5			1
2		5			-1
5		7			3
6		7			3

Menu
1.Accept graph.
2.Display graph.
3.Shotest path.
4.Exit.
Enter your choice:
3
Vertex	Distance	Pi
1	0		1
2	1		3
3	3		4
4	5		1
5	0		2
6	4		4
7	3		5

Menu
1.Accept graph.
2.Display graph.S
3.Shotest path.
4.Exit.
Enter your choice:
4
*/
