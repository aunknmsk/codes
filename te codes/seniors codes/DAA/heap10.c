#include<stdio.h>
#include<string.h>

struct node
{
	char programs[20];
	int length;
};

struct node tape[20];
int count,i;

void accept()
{
	int i;
	printf("Enter number of programs:");
	scanf("%d",&count);
	for(i=0;i<count;i++)
	{
		printf("Enter programe name:");
		scanf("%s",tape[i].programs);
		printf("Enter length of program:");
		scanf("%d",&tape[i].length);
	}
}


void display()
{
	int i;
	printf("\nPrograms\tLength\n");
	for(i=0;i<count;i++)
	{
		printf("%s\t\t",tape[i].programs);
		printf("%d\n",tape[i].length);
	}
}

void build_minheap(int index)
{
		char temp_programs[20];
		int temp_length;
		int l,r;
		l=(2*index)+1;
		r=(2*index)+2;
		for(i=0;i<count;i++){
		if(tape[index].length>tape[l].length)
		{
			strcpy(temp_programs,tape[index].programs);
			temp_length=tape[index].length;
			
			strcpy(tape[index].programs,tape[l].programs);
			tape[index].length=tape[l].length;
			
			strcpy(tape[l].programs,temp_programs);
			tape[l].length=temp_length;
		}
		
		if(tape[index].length>tape[r].length)
		{
			strcpy(temp_programs,tape[index].programs);
			temp_length=tape[index].length;
			
			strcpy(tape[index].programs,tape[r].programs);
			tape[index].length=tape[r].length;
			
			strcpy(tape[r].programs,temp_programs);
			tape[r].length=temp_length;
		}
	}
		display();
}


void main()
{

int i;
int opt;
int j;
j=0;

do
	{
		printf("\nMenu\n1.Accept input.\n2.Display input.\n3.Build minheap of programs.\n4.Optimal storage algorithm.\n5.Exit.\n");
		printf("Enter yout choice:");
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
					build_minheap(j);
					break;		
			
		}
	}while(opt!=5);

}

/*
[student@localhost ~]$ gcc heap10.c
[student@localhost ~]$ ./a.out

enter no. of programs : 3

1)accept
2)display order
3.optimal

enter your choice : 1

Enter length of program 1 = 9

Enter length of program 2 = 6

Enter length of program 3 = 15

1)accept
2)display order
3.optimal

enter your choice : 2

  program::	1	2	3
   length::	6	9	15
1)accept
2)display order
3.optimal

enter your choice : 3

total retrieval time is 51 
mean retrieval time is 17 

*/
