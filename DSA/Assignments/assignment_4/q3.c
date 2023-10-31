#include <stdio.h>
#include <stdlib.h>

#define size 5

void display(int *);
void enqueue(int *,int *,int *,int);
int dequeue(int *,int *,int *);
int peep(int *,int );
void isQueueFull(int);
void isQueueEmpty(int);

int main(){
	int arr[size];
	int choice,ele,ret;

	int front = -1;
	int rear=-1;

	for(int i=0;i<size;i++)
		arr[i]=-99;

	while(1){

		printf("Select: \n1. Enqueue\n2. Dequeue\n3. Peep\n4. Display\n5. Is Queue Full\n6. Is Queue Empty \n7. exit \nEnter your choice :");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			printf("Enter ele :");
			scanf("%d",&ele);
			enqueue(arr,&front,&rear,ele);
			break;

		case 2:
			ret=dequeue(arr,&front,&rear);
			if(ret!=-1){
				printf("Popped Element =%d\n",ret);
				break;
			}
			break;

		case 3:
			ret=peep(arr,rear);
			printf("Peeped Value : %d\n",ret);
			break;

		case 4:
			display(arr);
			printf("\n");
			break;
		case 5:
			isQueueFull(rear);
			break;
		case 6:
			isQueueEmpty(front);
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
		printf("%d\t",a[i]);
	}
}

void enqueue(int *a,int *f,int *r,int e){
	
	if(*r==size-1){
		printf("Queue is Full\n");
		return ;
	}

	(*r)++;
	a[*r]=e;

	if(*f==-1)
		*f=0;
}

int dequeue(int *a,int *f,int *r){

	if(*f==-1){
		printf("End of Queue\n");
		return -1;
	}

	int ret=a[*f];
	a[*f]=-99;

	if(*f!=*r)
		(*f)++;
	else {
		*f=-1;
		*r=-1;
	}

	return ret;
}

int peep(int *a,int t){

	if(t==-1){
		printf("End of Stack\n");
		return -1;
	}

	int ret=a[t];
	
	return ret;
}

void isQueueFull(int a){
	
	if(a==size-1)
		printf("Queue reached its limit\n");
	
	else
		printf("Queue can be filled further more\n");
}

void isQueueEmpty(int a){
	if(a==-1)
		printf("Yes,Queue is empty\n");
	
	else
		printf("No,Queue is not empty\n");
}