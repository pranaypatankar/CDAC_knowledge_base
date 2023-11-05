// 
//Write a C/C++ program to implement Binary Search. We need to check for duplicate element
// inputs, if found any should not insert into the input array. The array should manage in sorted order.
// Apply a duplicacy check on the element while inserting the element, if found duplicate then discards
// the input. The input element should insert in the array at the right position( index). Appropriate
// shifting can be applied in the array in order to insert the input element at the right position. An
// appropriate condition check needs to apply for element not found scenario.
// (a) Binary Search ( iterative approach)
// (b) Binary Search ( recursion approach )
//

#include <stdio.h>
#include <stdlib.h>

//prototyping functions
int binarySearch(int *,int,int,int);       //parameters : array,size,number
void sort(int *,int);						//parameters : array,size
void display(int *,int);

//main function
int main(){
	int *arr=NULL;

	int size,num;

	printf("Enter Size of elements :");
	scanf("%d",&size);

	arr=(int *)malloc(sizeof(int)*size); //allocating memory for array
	if(arr==NULL){
		printf("Memory for array can't be allocated\n");
		exit(1);
	}

	printf("Enter Integer Value: ");
	for(int i=0;i<size;i++)
		scanf("%d",arr+i);

	sort(arr,size);
	printf("Entered Array : ");
	display(arr,size);

	printf("Enter Element to search:");
	scanf("%d",&num);

	int ret=binarySearch(arr,0,size,num);
	
	if(ret==-1)
		printf("No. not found\n");
	else
		printf("No. found at Index : %d\n",ret);

	free(arr);

	return 0;
}

void sort(int *arr1,int size){

	int min_i=0;
	int temp;

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
}

int binarySearch(int *p,int start,int end,int num){
		while(start<=end){
			int mid=start+(end-start)/2;

			if(p[mid]==num)
				return mid;
			if(p[mid]<num)
				start=mid+1;
			else 
				end=mid-1;
			}
			return -1;
}

void display(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d\t",*(arr+i));
	}
	printf("\n");
}