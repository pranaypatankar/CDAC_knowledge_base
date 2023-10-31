#include <stdio.h>
#include <stdlib.h>

#define size 5

void display(int *);
void push(int *,int *,int);
int pop(int *,int *);

int main(){
	int arr[size];
	int choice,ele,ret;

	int tail = -1;

	for(int i=0;i<size;i++)
		arr[i]=-99;

	while(1){

		printf("Select: \n1. Push\n2. Pop\n3. Display\n4. exit \n");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			printf("Enter ele :");
			scanf("%d",&ele);
			push(arr,&tail,ele);
			break;

		case 2:
			ret=pop(arr,&tail);
			if(ret!=-1){
				printf("Popped Element =%d\n",ret);
				break;
			}
			break;

		case 3:
			display(arr);
			printf("/n");
			break;

		case 4:
			exit(1);

		default:
			printf("Invalid Choice\n");
			break;
		}
	}
	return 0;
}

void display(int *a){
	for(int i=0;i<size;i++){
		printf("%d\n",a[i]);
	}
}

void push(int *a,int *t,int e){

	if(*t==size-1){
		printf("Stack Full\n");
		return ;
	}

	(*t)++;
	a[*t]=e;
}

int pop(int *a,int *t){

	if(*t==-1){
		printf("End of Stack\n");
		return -1;
	}

	int ret=a[*t];
	(*t)--;
	a[*t]=-99;

	return ret;
}

