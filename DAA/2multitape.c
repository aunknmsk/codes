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
	for(cur=1;cur * 2 <= *size;cur=child)///////////////////////////////////////////////////////////////////////
	{
		child=cur * 2;////////////////////////////////////////////////////////////////////////////////////
		if(child!=(*size) && heap[child]>heap[child+1])////////////////////////////////////////////////////////////////////////
			child++;//////////////////////////////////////////////////
		if(heap[child]<lastele)//////////////////////////////////////////////////////////////////////////////
			heap[cur]=heap[child];////////////////////////////////////////////////////////////////////////////////////////////////////
		else
			break;
	}
	heap[cur]=lastele;
	return minele;	
}

int sum[10],backadd[10],count[10];

int main()
{
	int ntapes;
	printf("Enter no of tapes\n");
	scanf("%d",&ntapes);
	int heap[MAX],size,ele,nprog,array[ntapes][MAX],i,j;
	init(&size);
	printf("Enter no of programs\n");
	scanf("%d",&nprog);
	printf("Enter each program time :\n");
	for(i=0;i<nprog;i++)
	{
		scanf("%d",&ele);
		insert(heap,ele,&size);
	}
	j=0;

	for(i=0;i<nprog;i++)
	{
		ele=deletemin(heap,&size);
		array[j][count[j]]=ele;
		backadd[j]+=ele;
		sum[j]+=backadd[j];
		count[j]++;
		j=(j+1)%ntapes;//////////////////////////           j can increase up to tap number only
	}

	for(i=0;i<ntapes;i++)
	{
		printf("\ntape %d :",i+1);
				for(j=0;j<count[i];j++)
			printf("%d ",array[i][j]);
		printf("\n");
	}
	int sum2=0;
	for(i=0;i<ntapes;i++)
	{
		sum2+=sum[i];
	}
	printf("total retrievel time =%d\n",sum2);
	return 0;
}

/*
OUTPUT:
[Student@localhost ~]$ gcc multitape.c
[Student@localhost ~]$ ./a.out
Enter no of tapes
3
Enter no of programs
9
Enter each program time :
11
4
5
9
1
16
23
3
8

tape 1 :1 5 11 

tape 2 :3 8 16 

tape 3 :4 9 23 
total retrievel time =118
[Student@localhost ~]$ 


*/
