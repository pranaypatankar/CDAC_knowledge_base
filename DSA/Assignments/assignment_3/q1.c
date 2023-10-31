#include <stdio.h>
#include <stdlib.h>

void insertEle(int *, int);
void bubbleSort();
void selectionSort();
void insertionSort();
void display(int *,int);

int main(){
	int choice;
	while(1){
		printf("Which Sorting you want:\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Exit\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				bubbleSort();
				break;
			case 2:
				selectionSort();
				break;
			case 3:
				insertionSort();
				break;
			case 4:
				exit(1);
			default :
				printf("Enter valid choice\n");
				break;
		}
	}
	return 0;
}

void insertEle(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("Enter element no. %d: ",i+1);
		scanf("%d",arr+i);
	}
	printf("array has been created successfully!\n");
}

void display(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("Element no. %d: ",i+1);
		printf("%d\n",*(arr+i));
	}
}

void bubbleSort(){
	int *arr1;
	int size,count,temp;

	printf("Enter size of Array :");
	scanf("%d",&size);

	arr1=(int *)malloc(sizeof(int)*size);

	if(arr1==NULL){
		printf("memory not allocated\n");
		return;
	}
	
	insertEle(arr1,size);
	printf("Array before sorting:\n");
	display(arr1,size);


	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr1[j]>arr1[j+1]){
				count++; 
				temp=arr1[j];
				arr1[j]=arr1[j+1];
				arr1[j+1]=temp;
			}
		}
		if(count==0){
			break;
		}
	}
	printf("Array after sorting:\n");
	display(arr1,size);

	free(arr1);
}

void selectionSort(){
	int *arr1;
	int size,min_i,temp;

	printf("Enter size of Array :");
	scanf("%d",&size);

	arr1=(int *)malloc(sizeof(int)*size);

	if(arr1==NULL){
		printf("memory not allocated\n");
		return;
	}
	
	insertEle(arr1,size);
	printf("Array before sorting:\n");
	display(arr1,size);


	for(int i=0;i<size-1;i++){
		min_i=i;
		for(int j=i+1;j<size;j++){
			if(arr1[j] < arr1[min_i]){
				min_i=j;
			}
			if(min_i!=i){
				temp=arr1[i];
				arr1[i]=arr1[min_i];
				arr1[min_i]=temp;
			}
		}
	}
	printf("Array after sorting:\n");
	display(arr1,size);

	free(arr1);

}

void insertionSort(){
	int *arr1;
	int size,temp;

	printf("Enter size of Array :");
	scanf("%d",&size);

	arr1=(int *)malloc(sizeof(int)*size);

	if(arr1==NULL){
		printf("memory not allocated\n");
		return;
	}
	
	insertEle(arr1,size);
	printf("Array before sorting:\n");
	display(arr1,size);


	for(int i=0;i<size;i++){
		for(int j=0;j<i;j++){
			if(arr1[i] < arr1[j]){
				temp=arr1[i];
				arr1[i]=arr1[j];
				arr1[j]=temp;
			}
		}
	}
	printf("Array after sorting:\n");
	display(arr1,size);

}