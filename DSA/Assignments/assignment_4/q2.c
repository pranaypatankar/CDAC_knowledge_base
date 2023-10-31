#include <stdio.h>
#include <stdlib.h>

#define size 5 //maximum size of stack

//function declearations
void display(int *);
void push(int *,int *,int);
int pop(int *,int *);
int peep(int *,int *);
void isStackFull(int);
void isStackEmpty(int);

int main(){
	int arr[size];
	int choice,ele,ret;

	int top = -1;

	for(int i=0;i<size;i++)
		arr[i]=-99;

	while(1){

		printf("Select: \n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Is Stack Full\n6. Is Stack Empty \n7. exit \nEnter your choice :");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			printf("Enter ele :");
			scanf("%d",&ele);
			push(arr,&top,ele);
			break;

		case 2:
			ret=pop(arr,&top);
			if(ret!=-1){
				printf("Popped Element =%d\n",ret);
				break;
			}
			break;

		case 3:
			ret=peep(arr,&top);
			printf("Peeped Value : %d\n",ret);
			break;

		case 4:
			display(arr);
			printf("/n");
			break;
		case 5:
			isStackFull(top);
			break;
		case 6:
			isStackEmpty(top);
			break;
		case 7:
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

int peep(int *a,int *t){

	if(*t==-1){
		printf("End of Stack\n");
		return -1;
	}

	int ret=a[*t];
	
	return ret;
}

void isStackFull(int a){
	
	if(a==size-1)
		printf("Stack reached its limit\n");
	
	else
		printf("Stack can be filled further more\n");
}

void isStackEmpty(int a){
	if(a==-1)
		printf("Yes,stack is empty\n");
	
	else
		printf("No,stack is not empty\n");
}