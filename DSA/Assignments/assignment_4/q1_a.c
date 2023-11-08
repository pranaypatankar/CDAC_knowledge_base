#include <stdio.h>
#include <stdlib.h>

void partition(int *, int, int); //passing array,start,end of array
void merge_sort(int *,int, int, int, int);	//passing array,starting index of first array, ending index of first array, first index of second array,last index of second array
void display(int *, int, int);//passing array and size of array

int main(){
	int size,choice;

	int *arr;

	printf("Enter Size of Array :");
	scanf("%d",&size);

	arr= (int *)malloc(sizeof(int)*size); //allocating memory for array

	if(arr==NULL){						//checking weather memory allocated or not
		printf("Memory can't be allocated\n");
		exit(0);
	}

	printf("Enter array :\n");			//taking array input
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}

	printf("Entered Array :");
	display(arr,0,size-1);

	partition(arr,0,size-1);

	printf("Final Sorted Array:");
	display(arr,0,size -1);

	free(arr);
	
	return 0;
}

void display(int *arr,int first,int last){
	for(int i=first;i<=last;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void partition(int *arr,int first,int last){
	printf("Splitting Arrays from index %d to %d: \n",first,last);

	if(first>=last)
		return;
	
	int mid = (first+last)/2; //calculating mid of array
	partition(arr,first,mid);	//dividing array in 2 parts
	partition(arr,(mid+1),last);
	display(arr,first,mid);		                       
	display(arr,mid+1,last);
	merge_sort(arr,first,mid,mid+1,last);

	display(arr,first,last);
}

void merge_sort(int *arr, int first,int last, int first1, int last1){

	int *result;

	int size= (last-first+1)+(last1-first1 +1);

	result = (int *)malloc(sizeof(int)*size);

	if(result==NULL){
		printf("Memory for merged array can't be allocated\n");
		exit(1);
	}

	int k=0,i=first;
	int j=first1;

	while(i<=last && j<=last1){
		if(arr[i] < arr[j]){
			result[k]=arr[i];
			i++;
			k++;
		}
		else{
			result[k]=arr[j];
			j++;
			k++;
		}
	}
	
	while(i<=last){
		result[k]=arr[i];
		i++;
		k++;
	}

	while(j<=last1){
		result[k]=arr[j];
		j++;
		k++;
	}
	k=0;
	for(int a=first;a<=last1;a++){
		arr[a]=result[k];
		k++;
	}

	display(arr,first,last1);

	free(result);
}