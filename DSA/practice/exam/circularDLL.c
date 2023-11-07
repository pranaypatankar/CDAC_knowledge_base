#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct node {
	struct node *prev;
	int data;
	struct node *next;
};

void insert(struct node **);
void deleteNode(struct node **);
void display(struct node *);
void findFirst(struct node *);
void deleteAll(struct node **);

int main(){
	struct node *head=NULL;
	char ch;
	int choice;

	do{
		printf("MENU :\n1.Insert\n2.Delete\n3.Display\n4.findFirst\n5.Exit\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			insert(&head);
			break;

		case 2:
			deleteNode(&head);
			break;

		case 3:
			display(head);
			break;

		case 4:
			findFirst(head);
			break;

		default:
			printf("Invalid Choice\n");
			break;		
		}
		__fpurge(stdin);
		printf("Want to exit (Y / N): ");
		scanf("%c",&ch);
	}while(ch=='n'|| ch=='N');

deleteAll(&head);
return 0;
}

void insert(struct node **p){
	struct node *t,*temp;

	temp=(struct node *)malloc(sizeof(struct node));

	if(temp==NULL){
		printf("Memory failed to be allocated\n");
		return;
	}

	temp->next=*p;
	temp->prev=NULL;

	printf("Enter Element : ");
	scanf("%d",&temp->data);

	t=*p;

	if(*p==NULL){
		*p=temp;
		temp->next=*p;
		(*p)->prev=temp;
		printf("Linked List created\n");
	}
	else{

		while(t->next!=*p){
			t=t->next;
		}
		temp->prev=t;
		t->next=temp;
		(*p)->prev=temp;

		printf("Node added at END\n");
	}

}
void deleteNode(struct node **p){
	struct node *t=*p;

	if(*p==NULL){
		printf("No Linked List Exist\n");
		return;
	}

	else if(t->next==*p){
		printf("Deleting Only node\n");
		free(t);
	}
	else{
		while(t->next->next!=*p){
			t=t->next;
		}
		free(t->next);
		t->next=*p;
		(*p)->prev=t;
		printf("Deleted Last node\n");
	}
}
void display(struct node *p){
	struct node *t=p;
	if(p=NULL){
		printf("No Linked List Exist\n");
		return;
	}
	do{
		printf("--->||%p|%d|%p||",t->prev,t->data,t->next);
		t=t->next;
	}
	while(t!=p);
	printf("\n");

}
void findFirst(struct node *p){
		if(p=NULL){
		printf("No Linked List Exist\n");
		return;
	}
	printf("First node contains %d at %p address\n",p->data,p);
}
void deleteAll(struct node **p){
	struct node *temp,*t=*p;

	while(t->next!=*p)
		t=t->next;
	while(t->prev!=*p){
		temp=t;
		t=t->prev;
		free(temp);
	}
	free(*p);
	printf("All nodes Deleted\n");
}

