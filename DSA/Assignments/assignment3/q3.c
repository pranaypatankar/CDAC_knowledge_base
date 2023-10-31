// Write a C/C++ program to implement single linked list in sorted
// order. Implement below metioned functions. Apply all required
// condition check & validation like list empty or not, while
// inserting/deleting by position validate the position. Implement a policy
// for duplicate value input.
// a)insert b) displayList c)listNodeCount d) deleteFromEnd
// e) deleteFromBeg f)deleteFromPos g) reverseDisplay


#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insertNode(struct node **);
void display(struct node *);
int listNodeCount(struct node *);
void deleteFromEnd(struct node **);
void deleteFromBeg(struct node **);
void deleteFromPos(struct node **,int);
void reverseDisplay(struct node *);

int main(){
	struct node *head=NULL;

	int choice,count,pos;
	while(1){
		printf("\nMenu :-\n1.Insert Node\n2.Display\n3.Count List Nodes\n4.Delete From End\n5.Delete From Begin\n6.Delete from Position\n7.Reverse Display\n8.Exit\nEnter your Choice:-");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				insertNode(&head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				count =listNodeCount(head);
				printf("No of Nodes :%d\n",count);
				break;
			case 4:
				deleteFromEnd(&head);
			  break;
			case 5:
				deleteFromBeg(&head);
				break;
			case 6:
				printf("Enter Position: ");
                scanf("%d", &pos);
				deleteFromPos(&head,pos);
				break;
			case 7:
				reverseDisplay(head);
				break;
			case 8:
				exit(1);
			default:
				printf("Invalid Choice!!!!!\n");
				break;
		}
	}
}

void insertNode(struct node **p){
	struct node *temp, *t1, *prev;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    temp->next = NULL;
    printf("Enter element: ");
    scanf("%d", &temp->data);

    t1 = *p;
    prev = NULL;

    if (*p == NULL) {
        *p = temp;
    } else {
        while (t1 != NULL && t1->data < temp->data) {
            prev = t1;
            t1 = t1->next;
        }
        if (prev == NULL) {
            temp->next = *p;
            *p = temp;
        } else {
            prev->next = temp;
            temp->next = t1;
        }
    }
}

void display(struct node *p){
	struct node *t1;

	if(p==NULL){
		printf("No list exist\n");
		return;
	}
	t1=p;
	
	while(t1!=NULL){
		printf("---->|%d|",t1->data);
		t1=t1->next;
	}
	printf("\n");
}
int listNodeCount(struct node *p){
	struct  node *t;
    int count =1 ;
    t = p;

    for(int i=0;t->next!=NULL;i++){
        count++;
        t=t->next;
    }

    return count;
}
void deleteFromEnd(struct node **p){
	struct node* t, *temp;
    t = *p;
    if (*p == NULL) {
        return; // If the list is empty, do nothing
    } else {
        while (t->next->next != NULL) {
            t = t->next; // Traverse to the second-to-last node
        }
        temp = t->next; // The last node to be deleted
        t->next = NULL; // Remove the reference to the last node
        printf("Last element is deleted\n");
        free(temp); // Free the memory of the deleted node
    }
}
void deleteFromBeg(struct node **p){
	struct node* t, *temp;
    if (*p == NULL) {
        return; // If the list is empty, do nothing
    } else {
        t = *p;
        temp = *p;
        *p = t->next; // Move the head to the next node
        printf("First element is deleted\n");
        free(temp); // Free the memory of the deleted node
    }
}
void deleteFromPos(struct node **p,int pos){
	struct node *t, *temp;
    t = *p;

    for (int i = 1; i < pos - 1; i++) {
        t = t->next; // Traverse to the node just before the desired position
    }

    temp = t->next; // The node at the specified position
    t->next = t->next->next; // Remove the reference to the node to be deleted
    printf("Element at position %d is deleted\n",pos);
    free(temp); // Free the memory of the deleted node
}
void reverseDisplay(struct node *p){
	struct node *t;

    struct node **h;

    int size = listNodeCount(p);

    h=(struct node  **)malloc(sizeof(struct node *)*size);

    t = p;

    h[0]=t;

    for(int i =1;t->next!=NULL;i++){
        h[i]=t->next;
        t=t->next;
    }
    
    printf("elements in reversed sequence\n|tail|");

    for(int i=size-1;i>=0;i--){
        printf("---->|%d|",h[i]->data);
    }
    printf("\n");

    free(h);
}