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
void insert(int *,int,int*,int);

//main function
int main(){
	int *arr=NULL;

	int size,num,ele,count=0;

	printf("Enter Size of elements :");
	scanf("%d",&size);

	arr=(int *)malloc(sizeof(int)*size); //allocating memory for array
	if(arr==NULL){
		printf("Memory for array can't be allocated\n");
		exit(1);
	}
	for(int i=0;i<size;i++){
		printf("Enter Integer Value: ");
		scanf("%d",&ele);

		for(int j=0;j<i;j++){
			if(arr[j]==ele){
				printf("Duplicate found\n");
				i--;
			}
		}
		arr[i]=ele;
	
	}

	sort(arr,size);
	printf("Entered Array : ");
	display(arr,size);

	printf("Enter Element to search:");
	scanf("%d",&num);

	int ret=binarySearch(arr,0,size-1,num);
	
	if(ret==-1)
		printf("No. not found\n");
	else
		printf("No. found at Index : %d\n",ret);

	free(arr);

	return 0;
}

void sort(int *arr1,int size){
 
	int count=0;
	int temp;

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
}

int binarySearch(int *p,int start,int end,int num){
		while(start<=end){
			int mid=(start+end);

			if(p[mid]==num)
				return mid;
			if(p[mid]<num)
				return binarySearch(p,start,mid-1,num);
			else 
				return binarySearch(p,mid+1,end,num);
			}
			return -1;
}

void display(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d\t",*(arr+i));
	}
	printf("\n");
}

