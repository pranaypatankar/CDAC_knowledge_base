#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void enqueue(struct node**,struct node **,int);
int dequeue(struct node **,struct node **);
int peek(struct node **);
void display(struct node **);
void freeAllNode(struct node **);

int main(){
	struct node *front;
	struct node *rear;

	front=rear=NULL;

	int choice,ret,ele;

	printf("Menu : 1.Enqueue\t2.Dequeue\t3.Peek\t4.Display\t5.Exit\n");
	scanf("%d",&choice);

	switch(choice){
	case 1:
		printf("Enter ele :");
		scanf("%d",&ele);
		enqueue(&front,&rear,ele);
		break;

	case 2:
		ret=dequeue(front,rear);
		printf("Dequeued Ele : %d",ret);
		break;

	case 3:
		ret=peek(front,rear);
		printf("Peek :%d");
		break;

	case 4:
		display(front,rear);
		break;

	case 5:
		exit(1);

	default:
		printf("Enter Valid Choice\n");
		break;
	}

	freeAllNode(front);
	return 0;
}