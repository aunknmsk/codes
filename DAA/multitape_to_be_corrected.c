#include<stdio.h>
int incr_order[10];
int no_of_progs,no_of_tapes;
	

void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}





void bottom_up_heapify(int arr[10],int child_indx)                                  // for creation of min heap
{
	int parent_indx = (child_indx-1)/2;
	
	
	while(arr[parent_indx] > arr[child_indx] && parent_indx >=0)
	{
		swap(&arr[parent_indx],&arr[child_indx]);
		child_indx = parent_indx;
		parent_indx = (child_indx-1)/2;
	}
}


void accept(int arr[10],int no_of_progs)
{
	for(int i=0;i<no_of_progs;i++)
	{
		printf("\nEnter length of program %d :",i+1);
		scanf("%d",&arr[i]);
		
		bottom_up_heapify(arr,i);
	}
}


void display(int arr[10],int no_of_progs)
{
	for(int i=0;i<no_of_progs;i++)
	{
		printf(" %d ",arr[i]);
	}
}

void top_down_heapify(int arr[10],int parent_indx,int last_indx)
{
	int child_indx = parent_indx*2 + 1;
	while(child_indx <= last_indx )
	
	{
		if(child_indx < last_indx && arr[child_indx+1] < arr[child_indx])
		child_indx = child_indx+1;
		
		if(arr[parent_indx] > arr[child_indx])
		{
			swap(&arr[parent_indx],&arr[child_indx]);
		}
		
		parent_indx = child_indx;
		child_indx = child_indx*2+1;
		
	}
}



void optimal_pattern(int arr[10],int no_of_progs)
{
	int count=0;
	int deleted_element;
	int last_indx = no_of_progs-1;
	while(count<=no_of_progs-1)
	{
		deleted_element = arr[0];
		incr_order[count] = deleted_element;
		count++;
		arr[0] = arr[last_indx];
		last_indx--;
		top_down_heapify(arr,0,last_indx);
	}
}



void mrt(int arr[10][10],int size,int no_of_tapes)
{
	
	
	for(int k=0;k<no_of_tapes;k++){
	
	int sum=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<i;j++)
		{
			sum = sum+arr[k][i];
		}
	}
	
	printf("\n\nmrt for this tape is:%d",sum);}
}

void store_on_tape(int incr_order[10],int tape[10][10])
{
	int i=0;int j;
	int k1=0;
	int k2=0;
	int k3=0;
	
	while(i<no_of_progs){                        // for assigning programs on tapes
		for(j=0;j<no_of_tapes;j++)
		{
			tape[j][k1] = incr_order[i];
			i++;

		}
		k1++;
	}
	
	
	for(i=0;i<no_of_tapes;i++){           // for displaying programs on tapes
	
	printf("\ntape[%d]",i+1);
	for(j=0;j<k1;j++){
		printf(" %d ",tape[i][j]);
	  		}
	 }
	 
	mrt(tape,k1,no_of_tapes);
	 
	 
	 
	 
}


int main()
{
	
	printf("\nEnter the number of programs:");
	scanf("%d",&no_of_progs);
	
	int arr[no_of_progs];
	accept(arr,no_of_progs);
	
	bottom_up_heapify(arr,no_of_progs-1);	
	
		
	printf("\n\nArray after heap creation is:");
	display(arr,no_of_progs);

	optimal_pattern(arr,no_of_progs);

	printf("\n\nArray after being sorted is:");
	display(incr_order,no_of_progs);
	
	printf("\nEnter number of tapes:");
	scanf("%d",&no_of_tapes);
	
	int tape[10][10];
	
	store_on_tape(incr_order,tape);
	
		
	
	
	
	return 0;
}
