#include<stdio.h>
//using namespace std;

typedef struct tsp
{
	int level,source,destination,cost,intermediate[10];
}tsp;

int combinations[1000][10];
int fix[10];
tsp obj[1000];

int lastlevel(int array[10],int n,int c,int j)
{
	int temp[10];
	int i,x,k=0,z,l,a;
	while(k<n)
	{
		z=0;
		while(z<n-1)
		{			
			combinations[j][c]=array[k];
			for(l=0,a=0;l<n;l++)
				if(array[l]!=combinations[j][c])
					temp[a++]=array[l];	
				
			combinations[j][c+1]=temp[z++];
			if(c>0)
			{
				for(x=0;x<c;x++)
					combinations[j][x] = fix[x];
			}	
			j++;						
		}
		k++;
	}
	return j;
}

int combination(int array[10],int n,int c, int level,int j)
{
	int temp[10];
	int k=0,i,a,val;	
	while(k<n)
	{	
		fix[c] = array[k];
		for(i=0,a=0;i<n;i++)
			if(array[i]!= fix[c])  // copy remaining elements
				temp[a++]=array[i];
								
		if(level==3)
			j=lastlevel(temp,n-1,c+1,j);
		else 
			j=combination(temp,n-1,c+1,level-1,j);
		k++;	
	}
	return j;
}

int searchInObj(int level,int source,int destination,int itmd[10],int k)
{
	int i,flag;
	while(k>=1){
		flag=0;
		if(obj[k].level==level && obj[k].source==source && obj[k].destination==destination)
		{
			for(i=0;i<level;i++)
			{
				if(obj[k].intermediate[i]!=itmd[i])
				{
					flag=1;
					break;
				}
			}			
			if(flag==0)
				return obj[k].cost;
		}
		k--;
	}
	return -1;
}

int result(int prd[10],int k,int n,int array[10][10])
{
	int i,j,min=999,source,destination,cost=0,cost1,m=0,level,visible[10];
	for(j=1;j<=n;j++)
		visible[j]=0;
		
	level=obj[k-1].level;
	for(i=k-1;i>0,level>=1;i--)
	{	
		source=obj[i].source;
		destination=obj[i].destination;
		if(obj[i].level<level)
		{
			
			if(level==n-2)
			{	visible[prd[m-1]]=1;
				cost=cost1;
			}
			visible[prd[m]]=1;
			
			level=obj[i].level;
			m++;
		}

		if(level==(n-2))
		{
			cost1=obj[i].cost+array[destination][source];
			if(cost1<=min)
			{
				m=0;
				min=cost1;
				prd[m]=source;
				m=m+1;				
				prd[m]=obj[i].intermediate[0];
			}				
		}
		else
		{	
			if(source==prd[m-1])
			{
				cost1=obj[i].cost;
				if((cost1<=min) && (visible[obj[i].intermediate[0]]==0))
				{
					min=cost1;
					prd[m]=obj[i].intermediate[0];
				}	
			}
		}			
	}
	return cost;
}

int main()
{
	int n,prd[10],m,k,array[10][10],i,j,source,level,intermediate[10],a,min,itmd[10],cost,x,y,column,z;
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
		
	for(i=0;i<10;i++)
	for(j=0;j<10;j++)
	array[i][j]=0;

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j)
				array[i][j]=0;
			else
			{
				printf("\nEnter distance between %d  to %d: ",i,j);
				scanf("%d",&array[i][j]);
			}
		}
	
	for(j=1;j<=n;j++)
		printf("\t %d",j);
	for(i=1;i<=n;i++)
	{
		printf("\n %d:",i);
		for(j=1;j<=n;j++)
			printf("\t %d",array[i][j]);
	}
	printf("\nEnter source vertex : ");
	scanf("%d",&source);	
	k=1;
	level=0;	
	while(level<=(n-2))
	{
		for(i=1;i<=n;i++)
		if(i!=source)
		{
			a=0;
			for(j=1;j<=n;j++)
				if(j!=i && j!=source)
					intermediate[a++]=j;
			intermediate[a]=0;			
			if(level==0)
			{
				obj[k].level=level;
				obj[k].source=i;
				obj[k].destination=source;	
				obj[k].cost=array[i][source];
				obj[k++].intermediate[0]=0;
			}	
			else if(level==1)
			{
				for(j=0;j<a;j++)
				{					
					obj[k].level=level;
					obj[k].source=i;
					obj[k].destination=source;
					obj[k].intermediate[0]=intermediate[j];
					obj[k].intermediate[1]=0;
					obj[k++].cost=array[i][intermediate[j]]+array[intermediate[j]][source];	
				}
			}
			else 
			{
				if(level==2)
					column=lastlevel(intermediate,a,0,0);
				else
					column=combination(intermediate,a,0,level,0);
				
				if(level==(n-2))
				{
					min=999;
					for(j=0;j<column;j++)
					{	z=0;
						while(z<(level-1))
							itmd[z++]=combinations[j][z+1];
						itmd[z]=0;	
					cost=array[i][combinations[j][0]]+(searchInObj(level-1,combinations[j][0],source,itmd,k-1));
						if(cost<=min)
						{
							min=cost;
							obj[k].level=level;
							obj[k].source=i;
							obj[k].destination=source;
							obj[k].cost=cost;
							for(m=0;m<level;m++)
								obj[k].intermediate[m]=combinations[j][m];
							obj[k].intermediate[m]=0;	 		
						}															
					}
					k++;
				}
				else
				{
					for(j=0;j<column;j++)
					{	z=0;
						while(z<(level-1))
							itmd[z++]=combinations[j][z+1];
						itmd[z]=0;	
					cost=array[i][combinations[j][0]]+(searchInObj(1,combinations[j][0],source,itmd,k-1));
						obj[k].level=level;
						obj[k].source=i;
						obj[k].destination=source;
						obj[k].cost=cost;
						for(m=0;m<level;m++)
							obj[k].intermediate[m]=combinations[j][m];
						obj[k++].intermediate[m]=0;	 		
					}
				}	
			}
		}
		level++;
	}	
	printf("\nlevel\tsource\tdestination\tcost\titm");
	for(j=1;j<k;j++)
	{
		m=0;
		printf("\n%d\t%d\t%d\t%d\t",obj[j].level,obj[j].source,obj[j].destination,obj[j].cost);
		while(obj[j].intermediate[m]!=0)
			printf("\t%d",obj[j].intermediate[m++]);
	}
	cost=result(prd,k,n,array);
	printf("\nShortest path is : %d",source);
	for(j=0;j<n-1;j++)
		printf("-->%d",prd[j]);
	printf("-->%d",source);
	printf("\nCost :: %d",cost);

return 0;
}



/*nayan@ubuntu:~/TSP$ g++ tsp2.cpp
nayan@ubuntu:~/TSP$ ./a.out

Enter number of vertices : 4

Enter distance between 1to 2 : 2

Enter distance between 1to 3 : 4

Enter distance between 1to 4 : 1

Enter distance between 2to 1 : 4

Enter distance between 2to 3 : 7

Enter distance between 2to 4 : 3

Enter distance between 3to 1 : 6

Enter distance between 3to 2 : 5

Enter distance between 3to 4 : 2

Enter distance between 4to 1 : 1

Enter distance between 4to 2 : 5

Enter distance between 4to 3 : 4
	1	2	3	4
1:	0	2	4	1
2:	4	0	7	3
3:	6	5	0	2
4:	1	5	4	0
Enter source vertex : 3

level	source	destination	cost	itm
0	1	3		4
0	2	3		7
0	4	3		4
1	1	3		9	2
1	1	3		5	4
1	2	3		8	1
1	2	3		7	4
1	4	3		5	1
1	4	3		12	2
2	1	3		9	2	4
2	2	3		8	4	1
2	4	3		10	1	2
Shortest path is : 3-->4-->1-->2-->3
Cost :: 15*/
