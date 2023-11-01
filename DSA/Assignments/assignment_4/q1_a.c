#include <stdio.h>
#include <stdlib.h>

void partition(int *, int, int); //passing array,start,end of array
void merge_sort(int *,int, int, int, int);	//passing array,starting index of first array, ending index of first array, first index of second array,last index of second array
void display(int *, int);//passing array and size of array

int main(){
	int size,choice;

	int *arr;

	printf("Enter Size of Array :");
	scanf("%d",&size);

	arr= (int *)malloc(sizeof(int)*size); //allocating memory for array

	if(arr==NULL){
		printf("Memory can't be allocated\n");
		exit(0);
	}

	printf("Enter array :\n");
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}

	display(arr,size);

	partition(arr,0,size);

	display(arr size);
	
	return 0;
}

void display(int *arr,int first,int last){
	
}