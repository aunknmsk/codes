#include<stdio.h>


void swap(int *no1,int *no2)
{	

	printf("\nbefore swap parent :%d and child %d", *no1,*no2);
	int temp;
	temp = *no1;
	*no1 = *no2;
	*no2 = temp;
	printf("\n\n\nafter swap parent :%d and child %d", *no1,*no2);
	
}




void bottom_up_heapify(int arr[10],int child_indx)                           // required for insertion
{
	int parent_indx;
	parent_indx = (child_indx - 1)/2 ; 
	
	while(arr[parent_indx] > arr[child_indx] && parent_indx >= 0)        // for creating min heaap
	{
		swap(&arr[parent_indx],&arr[child_indx]);
		child_indx = parent_indx;
		parent_indx = (child_indx - 1)/2;
		
	}
	
	
		
}



void accept(int arr[10],int no_of_programs)
{
	int i;
	
	for(i=0;i<no_of_programs;i++)
	{
		printf("\nEnter lenght of %d program :",i+1);
		scanf("%d",&arr[i]);
		bottom_up_heapify(arr,i);
	}
	
}


void top_bottom_heapify(int arr[10],int parent_indx,int last_indx)            // to be used while deletion
{
	int child_indx;
	child_indx = 2*parent_indx + 1;
	while(child_indx <= last_indx)
	{
		if(child_indx < last_indx && arr[child_indx+1]  < arr[child_indx])       // checks if right child is present or not and if present then which of the right or left child is smaller
		child_indx = child_indx + 1;
		
		if(arr[parent_indx] > arr[child_indx])
		{
			swap(&arr[parent_indx],&arr[child_indx]);
	
		}
		parent_indx = child_indx;
		child_indx = 2*parent_indx + 1;
	}
	
}


void optimal_storage(int arr[10],int no_of_programs,int tape[10])
{
	
	printf("\n\n\nin optimal storage function!!");
	int count=0;
	int last_index = no_of_programs-1;
	int delete_element;
	while(count <= no_of_programs-1)
	{
		delete_element = arr[0];
		tape[count] = delete_element;
		arr[0] = arr[last_index];
		last_index--;
		count++;
		top_bottom_heapify(arr,0,last_index);
		printf("\n\n\n\n in iteration %d of storage function:",count+1);
	}
}






int main()
{
	int arr[10],tape[10],no_of_programs;
	
	printf("\nEnter the number of  programs:");
	scanf("%d",&no_of_programs);
	accept(arr,no_of_programs);
	
	bottom_up_heapify(arr,no_of_programs-1);
	printf("\nHeap created after bottom up approach is:");
	for(int i=0;i<no_of_programs;i++)
		printf(" %d",arr[i]);
		
	optimal_storage(arr,no_of_programs,tape);
	printf("\nfinal ans:");
	for(int i=0;i<no_of_programs;i++)
	printf(" %d",tape[i]);
		
	
	return 0;
}
