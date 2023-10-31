#include <stdio.h>
#include <stdlib.h>

int nonUnique(int *,int);
void display(int *,int);

int main(){
	int size;
	int *arr;

	printf("Size of Array : ");
	scanf("%d",&size);

	arr=(int *)malloc(sizeof(int)*size);
	
	if(arr==NULL){
		printf("Memory cannot be allocated\n");
		exit(1);
	}


	printf("Enter Array : ");
	
	for(int i=0;i<size;i++)
		scanf("%d",arr+i);

	printf("Entered Array is : ");
	display(arr,size);

	int count =	nonUnique(arr,size);
	printf("No. of Non-Unique elements : %d\n",count);

	return 0;
}

int nonUnique(int *arr,int size){

	int temp,count=0,flag=0;
	for(int i=0;i<size;i++){
		if(arr[i]!= -99){
			temp=arr[i];
			for(int j=i;j<size;j++){
				if(arr[j]==temp){
					count++;
					
				}
			}
			if(count!=1){
				flag++;
				//printf("%d present %d times\n",temp,count);
			}
			count=0;
		}
	}
	return flag;
}

void display(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}