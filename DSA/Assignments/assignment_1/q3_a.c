//(a) Allocating 1D array dynamically and access the elements;

#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size;

	printf("Enter Size of array :");
	scanf("%d",&size);

	arr=(int *)malloc(sizeof(int)*size);

	if(arr==NULL){
		printf("Memory not Allocated\n");
		exit(1);
	}
	else 
		printf("\nMemory allocted successfully \n\n");

	for(int i=0;i<size;i++){
		printf("Enter element no. %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("\n");

	for(int i=0;i<size;i++){
		printf("Enter element no. %d: ",i+1);
		printf("%d\n",arr[i]);
	}
	return 0;
}


