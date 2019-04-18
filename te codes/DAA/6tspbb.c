#include<stdio.h>
#include<stdlib.h>
#define inf 9999

int g[10][10],r[10][10],lb;
int nov,noe,val,final_cost=0;
int pcount,path[10],visited[10],rcount,rnodes[10],cost[10],temp[10][10];
//20 30 10 11 15 16 4 2 3 5 2 4 19 6 18 3 16 4 7 16
int parent_cost=0;
void accept(int g[10][10],int nov)
{
	int i,j;
	
	for(i=1;i<=nov;i++)
	{
	for(j=1;j<=nov;j++)
	
		if(i!=j)
		{
		printf("\nenter value %d %d",i,j);
		scanf("%d",&g[i][j]);
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
			printf("\t%d",g[i][j]);
		}
	}

}
void initialize(int g[10][10],int nov)
{
	int i,j;
	for(i=1;i<=nov;i++)
	{
		
		for(j=1;j<=nov;j++)
		{
			g[i][j]=9999;
		}
	}

}

void copy(int g[10][10],int temp[10][10],int nov)
{
	int i,j;
	for(i=1;i<=nov;i++)
	{
		for(j=1;j<=nov;j++)
		{
			temp[i][j]=g[i][j];
		}
	}
}

int reduce(int rm[10][10],int nov) //reduce row
{
	int i,j;
	int min;
	int totalrmin=0,totalcmin=0;
	int total=0;
	

	
	for(i=1;i<=nov;i++) //for each row
	{
		min=9999;
		for(j=1;j<=nov;j++)
		{
			
			if(min>rm[i][j])
			{
			min=rm[i][j];
			}
		}
		if(min!=0 && min!=9999 )//if not reduced
		{
			for(j=1;j<=nov;j++)
			{
			
				if(rm[i][j]!=9999)
				{
					rm[i][j]=rm[i][j]-min;
				}
			}
			
			totalrmin=totalrmin+min;
		
		}
	}
	
	//reduce column
	for(j=1;j<=nov;j++) 
	{
		min=9999;
		for(i=1;i<=nov;i++)
		{
			
			if(min>rm[i][j])
			{
			min=rm[i][j];
			}
		}
		if(min!=0 && min!=9999)//if not reduced
		{
			for(i=1;i<=nov;i++)
			{
			
				if(rm[i][j]!=9999)
				{
					rm[i][j]=rm[i][j]-min;
				}
			}
			
			totalcmin=totalcmin+min;
		
		}
	}
display(rm,nov);
printf("\nthe reduced matrix is: ");
	printf("\ntotal row min value %d",totalrmin);
	printf("\ntotal col  min value %d",totalcmin);
	
	
	total=totalrmin+totalcmin;
	return (total);
	
}		

void findmin(int cost[10],int rnodes[10],int rcount)
{
	int min,nextnode,i;
	min=inf;//a.find min. cost for vertex
	
	for(i=1;i<rcount;i++)
	{
		if(min>cost[i])
		{	min=cost[i];
			nextnode=rnodes[i];
		}
	}//for
		//b.add in tsp path and cal. new rnodes
	visited[nextnode]=1;
	printf("\nselected vertex in path:%d",nextnode);
	path[pcount]=nextnode;
	pcount++;

}//findmin

void cal_rnodes()
{ int v;
	rcount=1;
	for(v=1;v<=nov;v++)
	{
		if(visited[v]==0)
		{
			rnodes[rcount]=v;
			rcount++;
		}	
	}//for
}
 
int tsp(int rm[10][10],int nov)
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
			cal_rnodes();
			if(rcount!=1)
			{
				tsp(rm,nov);
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
		
int main()
{
	int ch,lb,v;
	int rm[10][10];
	do
{
      printf("\n 1.Accept  \t 2.Display \t  3.Reduce matrix \t 4.TSP\n  Enter Your choice : ");
      scanf("%d",&ch);
      switch(ch){
        case 1 : printf("\nenter the number of vertices: ");
	scanf("%d",&nov);
                  initialize(g,nov);
  		  accept(g,nov);
                  break;
        case 2 :
                 display(g,nov);
                 break;
      
       case 3 : copy(g,rm,nov);
    		
    		lb=reduce(rm,nov);
    		parent_cost=lb;
    		printf("\nthe lower bound is %d",lb);
             	break;
	
	case 4:
		pcount=1;
		path[1]=1;
		pcount++;
		for(v=1;v<=nov;v++)
		     visited[v]=0;
		visited[1]=1;
		cal_rnodes();
	
		final_cost=tsp(rm,nov);
		printf("\n Minimum cost of TSP using BB %d",final_cost);
		break;
                 
     }
    }while(ch!=5);
 
 return 0;
 }
/*Output:

bash-4.2$ gcc tspbb.c
bash-4.2$ ./a.out

 1.Accept  	 2.Display 	  3.Reduce matrix 	 4.TSP
  Enter Your choice : 1

enter the number of vertices: 5

enter value 1 2 20

enter value 1 3 30       

enter value 1 4 10

enter value 1 5 11

enter value 2 1 15

enter value 2 3 16

enter value 2 4 4

enter value 2 5 2

enter value 3 1 3 

enter value 3 2 5

enter value 3 4 2

enter value 3 5 4

enter value 4 1 19

enter value 4 2 6

enter value 4 3 18

enter value 4 5 3

enter value 5 1 16

enter value 5 2 4

enter value 5 3 7

enter value 5 4 16

 1.Accept  	 2.Display 	  3.Reduce matrix 	 4.TSP
  Enter Your choice : 2

	9999	20	30	10	11
	15	9999	16	4	2
	3	5	9999	2	4
	19	6	18	9999	3
	16	4	7	16	9999
 1.Accept  	 2.Display 	  3.Reduce matrix 	 4.TSP
  Enter Your choice : 3

	9999	10	17	0	1
	12	9999	11	2	0
	0	3	9999	0	2
	15	3	12	9999	0
	11	0	0	12	9999
the reduced matrix is: 
total row min value 21
total col  min value 4
the lower bound is 25
 1.Accept  	 2.Display 	  3.Reduce matrix 	 4.TSP
  Enter Your choice : 4

	9999	9999	9999	9999	9999
	9999	9999	11	2	0
	0	9999	9999	0	2
	15	9999	12	9999	0
	11	9999	0	12	9999
the reduced matrix is: 
total row min value 0
total col  min value 0
 Lower bound=25 val=0
 Cost of 2 remaing node is 35
	9999	9999	9999	9999	9999
	1	9999	9999	2	0
	9999	3	9999	0	2
	4	3	9999	9999	0
	0	0	9999	12	9999
the reduced matrix is: 
total row min value 0
total col  min value 11
 Lower bound=25 val=11
 Cost of 3 remaing node is 53
	9999	9999	9999	9999	9999
	12	9999	11	9999	0
	0	3	9999	9999	2
	9999	3	12	9999	0
	11	0	0	9999	9999
the reduced matrix is: 
total row min value 0
total col  min value 0
 Lower bound=25 val=0
 Cost of 4 remaing node is 25
	9999	9999	9999	9999	9999
	10	9999	9	0	9999
	0	3	9999	0	9999
	12	0	9	9999	9999
	9999	0	0	12	9999
the reduced matrix is: 
total row min value 5
total col  min value 0
 Lower bound=25 val=5
 Cost of 5 remaing node is 31
selected vertex in path:4
	9999	9999	9999	9999	9999
	9999	9999	11	9999	0
	0	9999	9999	9999	2
	9999	9999	9999	9999	9999
	11	9999	0	9999	9999
the reduced matrix is: 
total row min value 0
total col  min value 0
 Lower bound=25 val=0
 Cost of 2 remaing node is 28
	9999	9999	9999	9999	9999
	1	9999	9999	9999	0
	9999	1	9999	9999	0
	9999	9999	9999	9999	9999
	0	0	9999	9999	9999
the reduced matrix is: 
total row min value 2
total col  min value 11
 Lower bound=25 val=13
 Cost of 3 remaing node is 50
	9999	9999	9999	9999	9999
	1	9999	0	9999	9999
	0	3	9999	9999	9999
	9999	9999	9999	9999	9999
	9999	0	0	9999	9999
the reduced matrix is: 
total row min value 11
total col  min value 0
 Lower bound=25 val=11
 Cost of 5 remaing node is 36
selected vertex in path:2
	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999
	9999	9999	9999	9999	0
	9999	9999	9999	9999	9999
	0	9999	9999	9999	9999
the reduced matrix is: 
total row min value 13
total col  min value 0
 Lower bound=25 val=13
 Cost of 3 remaing node is 52
	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999
	0	9999	9999	9999	9999
	9999	9999	9999	9999	9999
	9999	9999	0	9999	9999
the reduced matrix is: 
total row min value 0
total col  min value 0
 Lower bound=25 val=0
 Cost of 5 remaing node is 28
selected vertex in path:5
	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999
the reduced matrix is: 
total row min value 0
total col  min value 0
 Lower bound=25 val=0
 Cost of 3 remaing node is 28
selected vertex in path:3	1-	4-	2-	5-	3-
 Minimum cost of TSP using BB 28
 1.Accept  	 2.Display 	  3.Reduce matrix 	 4.TSP
  Enter Your choice : 
*/		
		


