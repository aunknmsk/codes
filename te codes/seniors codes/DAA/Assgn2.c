#include<stdio.h>
#include<string.h>
#define MAX 20

void init(int *size)
{
	*size=0;
}

void insert(int heap[10],int ele,int *size)
{
	(*size)++;
	heap[(*size)]=ele;
	int cur=*(size);
	while(heap[cur/2] > ele && cur!=0)
	{
		heap[cur]=heap[cur/2];
		cur=cur/2;
	}
	heap[cur]=ele;
}

int deletemin(int heap[10],int *size)
{
	int lastele,minele,cur,child;
	lastele=heap[(*size)--];
	minele=heap[1];
	for(cur=1; cur*2 <= *size;cur=child)
	{
		child=cur * 2;
		if(child!=(*size) && heap[child]>heap[child+1])
			child++;
		if(heap[child]<lastele)
			heap[cur]=heap[child];
		else
			break;
	}
	heap[cur]=lastele;
	return minele;	
}

int sum[3],backadd[3];

int main()
{
	int ntapes;
	printf("\nEnter no of tapes : ");
	scanf("%d",&ntapes);
	int heap[MAX],size,ele,nprog,array[ntapes][MAX],i,j;
	init(&size);
	printf("\nEnter no of programs : \n");
	scanf("%d",&nprog);
	printf("\nEnter each program time : ");
	for(i=0;i<nprog;i++)
	{
		scanf("%d",&ele);
		insert(heap,ele,&size);
	}
	j=0;

	for(i=0;i<nprog;i++)
	{
		ele=deletemin(heap,&size);
		array[j][i]=ele;
		backadd[j]+=ele;
		sum[j]+=backadd[j];
		j=(j+1)%ntapes;
	}

	int sum2=0;
	for(i=0;i<ntapes;i++)
	{
		sum2+=sum[i];
	}
	printf("\nTotal retrievel time = %d\n",sum2);
	return 0;
}

/*Output :
[Student@localhost ~]$ cd 331033
[Student@localhost 331033]$ gcc Assgn2.c
[Student@localhost 331033]$ ./a.out

Enter no of tapes : 3

Enter no of programs : 
6

Enter each program time : 7 
3
1
2
4
1

Total retrievel time = 22
[Student@localhost 331033]$ 
*/
