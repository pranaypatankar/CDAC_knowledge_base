/*
	Q1. Write a C/C++ program that declares an array of length N
	containing integers between 1 and N. Implement menu driven
	program using switch case for below mentioned functionalities.
	(a) insert element at index
	(b) delete element at index
	(c) find min val
	(d) find max val
	(e) display array element
	(f) reverse display array element
	(g) search element in array
	(h) array element count
	(i) avg of all array element
	(j) determine if array contains any duplicates.
	(k) reverse array element.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int size;

void insert(int *,int,int);
void delete(int *,int);
void maxVal(int *);
void minval(int *);
void displayArr(int *);
void displayRev(int *);
void search(int *,int);
void count(int *);
void average(int *);
void duplicate(int *);
void reverse(int *);

int main(){
		int ele,choice,index;
		int *arr;

		printf("Enter Size of array :");
		scanf("%d",&size);

		arr=(int *)malloc((sizeof(int))*size);
		if (arr==NULL){
			printf("Unable to allocate memory\n");
			return -1;
		}
		else
			printf("memory allocated\n");
		for(int i=0;i<size;i++){
			arr[i]=-99;
		}

		while(1){
			printf("\nEnter choice:\n1. insert element at index\n2. delete element at index\n3. find min val\n4. find max val\n5. display array element\n6. reverse display array element\n7. search element in array\n8. array element count\n9. avg of all array element\n10. check for duplicates.\n11. reverse array element.\n12. Exit.\n");
			scanf("%d",&choice);

			switch(choice){
			case 1:
				printf("Enter Index(0-%d) : ",size-1);
				scanf("%d",&index);
				printf("Enter Element : ");
				scanf("%d",&ele);
				insert(arr,index,ele);
				break;
			case 2:
				printf("Enter Index(0-%d) : ",size);
				scanf("%d",&index);
				delete(arr,index);
				break;
			case 3:
				maxVal(arr);
				break;
			case 4:
				minval(arr);
				break;
			case 5:
				displayArr(arr);
				break;
			case 6:
				displayRev(arr);
				break;
			case 7:
				printf("Enter Element to search : ");
				scanf("%d",&ele);
				search(arr,ele);
				break;
			case 8:
				count(arr);
				break;
			case 9:
				average(arr);
				break;
			case 10:
				duplicate(arr);
				break;
			case 11:
				reverse(arr);
				displayArr(arr);
				break;
			case 12:
				exit(1);
				break;
			default:
				printf("Enter Valid choice\n");
				break;	
			}
		}
}

void insert(int *arr,int index,int ele){
	int count=0;
	if(index > size){
		printf("Index out of Limit\n");
		return ;
	}

	if(arr[index]== -99){
		arr[index]=ele;
	}

	else{	
		for(int i=index;i<size;i++){
				if(arr[i]== -99){
					count=i;
					break;
				}
			}
			if(count == 0){
				printf("No index is empty\n");
			}
			for (int i=count;i>index;i--){
				arr[i]=arr[i-1];
			}
		arr[index]=ele;
	}
}

void delete(int *arr,int index){
	if(index > size){
		printf("Index out of Limit\n");
		return ;
	}
	arr[index]= -99;
}

void maxVal(int *arr){
	int max;
	max=arr[0];
	for(int i=1; i<size;i++){
		if(arr[i]>max && arr[i]!= -99){
			max=arr[i];
		}
	}
	printf("Maximum Value is : %d\n",max);
}

void minval(int *arr){
	int min;
	min=arr[0];
	for(int i=1; i<size;i++){
		if(arr[i]<min && arr[i]!= -99){
			min=arr[i];
		}
	}
	printf("Maximum Value is : %d\n",min);
}

void displayArr(int *arr){
	for(int i=0;i<size;i++){
		if(arr[i]!= -99)
			printf("%d\t",arr[i]);
	}

}

void displayRev(int *arr){
	for(int i=size-1;i>=0;i--){
		if(arr[i]!= -99)
			printf("%d\t",arr[i]);
	}

}

void search(int *arr,int ele){
	int count =0;
	int arr1[size];
	for(int i=0;i<size;i++){
			arr1[i]=-99;
		}
	for(int i=0;i<size;i++){
		if(arr[i]==ele && arr[i]!= ele){
			count++;
			arr1[i]=i+1;
		}
	}
	if(count==0){
		printf("Searched element not found\n");
	}
	else{ 
		printf("Searched element found at indexes: ");
		for(int i=0;i<size;i++){
			if(arr1[i]!=0){
				printf("%d",arr[i]-1);
			}
			printf("\n");
		}
	}
}

void count(int *arr){
	int count=0;
	for(int i=0;i<size;i++){
	if(arr[i]!= -99)
			count++;
	}
	printf("Count of elements in array");
}

void average(int *arr){
	int count=0,sum=0;
	float avrg;
	for(int i=0;i<size;i++){
	if(arr[i]!= -99)
			count++;
			sum=sum+arr[i];
	}
	avrg=sum/count;
	printf("Average of Entered elements are : %f\n",avrg);
}

void duplicate(int *arr){
	int temp,count=0,flag=0;
	for(int i=0;i<size;i++){
		if(arr[i]!= -99){
			temp=arr[i];
			for(int j=0;j<size;j++){
				if(arr[j]==temp){
					count++;
					;
				}
			}
			if(count!=1){
				flag++;
				printf("%d present %d times\n",temp,count);
			}
			count=0;
		}
	}
	if(flag==0)
		printf("No elements are duplicated\n");
}

void reverse(int *arr){
	int revarr[size];

	for(int i=0;i<size;i++){
		for(int j=size-1;j>=0;j--)
			revarr[i]=arr[j];
	}
	arr=revarr;
	printf("Array is reversed\n");
}