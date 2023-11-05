#include <stdio.h>
#include <stdlib.h>

void factor(int,int *,int *);
int search(int *, int, int);
void sort(int *,int);
void display(int *,int);

int main(){
	int *arr;

	int count=0,ele,num,ret;

	arr=(int *)malloc(sizeof(int)*20);
	if(arr==NULL){
		printf("Memory Allocartion Failed\n");
		exit(1);
	}

	printf("Enter no.(1-100):- ");
	scanf("%d",&num);

	factor(num,arr,&count);
	display(arr,count);

	printf("Which index you want to check\n");
	scanf("%d",&ele);

	ret=search(arr,count,ele);
	if(ret!=0){
		printf("Factor at index %d is %d.\n",ele,ret);
	}
	else 
		printf("Index out of range\n");

	return 0;
}

void factor(int num,int *arr,int *count){
	int j=0;
	for(int i =1;i<=num;i++){
		if(num%i==0){
			arr[j]=i;
			j++;
		}
	}
	*count=j+1;
	//arr=(int *)realloc(arr,*count);

	sort(arr,*count);
}

int search(int *arr,int count,int index){

	if(index>count)
		return 0;

	return arr[index];
}

void sort(int *arr1,int size){
	int min_i,temp;

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

void display(int *arr,int size){
	printf("Factors of given number\n");

	for(int i=1;i<size;i++)
		printf("%d\t",arr[i]);

	printf("\n");
}