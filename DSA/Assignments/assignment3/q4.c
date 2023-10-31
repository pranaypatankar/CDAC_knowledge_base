// Write a C/C++ program to implement single linked list to store
// Student Information ( StudentName and StudentPRN).
// Implement below metioned functions. Apply all required condition
// check & validation like list empty or not, while inserting/deleting by
// position validate the position.
// a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
// e)listNodeCount f) deleteFromEnd g) deleteFromBeg
// h)deleteFromPos i) deleteByElement j) reverseDisplay
// k)freeAllNode


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

struct node
{
	struct stu{
		char name[50];
		long long int prn;
	}student;
	struct node *next;
};

void insertAtEnd(struct node **);
void insertAtBeg(struct node **);
void insertAtPos(struct node **,int);
void displayList(struct node *);
int listNodeCount(struct node *);
void deleteFromEnd(struct node **);
void deleteFromBeg(struct node **);
void deleteFromPos(struct node **,int);
void deleteByElement(struct node **,long long int);
void reverseDisplay(struct node *);
void freeAllNode(struct node **);

int main(){
	struct node *head;
	head=NULL;
	int choice,count,ele,pos;
	while(1){
		__fpurge(stdin);
		printf("\nMenu:\n1->Insert at begin\n2->Insert at end\n3->Insert at position\n4->Display\n5->Delete first node\n6->Delete from end\n7->Delete from position\n8->Delete By Element\n9->List Node Count\n10->Reverse Display\n11->Free Node\n12->Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertAtBeg(&head); // Call the insertBeg function to add a node at the beginning
                break;

            case 2:
                insertAtEnd(&head); // Call the insertEnd function to add a node at the end
                break;

            case 3:
                insertAtPos(&head, pos); // Call the insertPos function to add a node at a specific position
                break;

            case 4:
                displayList(head); // Call the display function to print the linked list
                break;

            case 5:
                deleteFromBeg(&head); // Call the deleteBeg function to remove the first node
                break;

            case 6:
                deleteFromEnd(&head); // Call the deleteEnd function to remove the last node
                break;

            case 7:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deleteFromPos(&head,pos); // Call the deletePos function to remove a node at a specific position
                break;

            case 8:
                printf("Enter Element to delete: ");
                scanf("%d",&ele);
                deleteByElement (&head,ele);
                break;

            case 9:
                count=listNodeCount(head);
                printf("No of Nodes :%d\n",count);
                break;

            case 10:
                reverseDisplay(head);
                break;

            case 11:
                freeAllNode(&head);
                head=NULL;
                break;

            case 12:
                exit(1);

            default:
                printf("Invalid choice\n"); // Handle an invalid menu choice
        }
    }
    return 0;
}

void insertAtBeg(struct node **p){
	struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Memory not allocated\n");
        return;
    }
    __fpurge(stdin);
    printf("Enter Name of Student : ");
    scanf("%[^\n]",temp->student.name);
    printf("Enter PRN of student: ");
    scanf("%lld",&temp->student.prn);
    temp->next = *p;
    *p = temp;
}

void insertAtEnd(struct node **p){
    struct node *temp,*t;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Memory not allocated\n");
        return;
    }
    __fpurge(stdin);
    printf("Enter Name of Student : ");
    scanf("%[^\n]",temp->student.name);
    printf("Enter PRN of student: ");
    scanf("%lld",&temp->student.prn);
    t = *p;
    if (*p == NULL) {
        *p = temp; // If the list is empty, make the new node the head
    } else {
        while (t->next != NULL) {
            t = t->next; // Traverse the list to find the last node
        }
        t->next = temp; // Add the new node at the end
    }

}

void insertAtPos(struct node **p,int pos){
    if (pos == 1) {
        insertAtBeg(p); // If the position is 1, add the node at the beginning
        return;
    }
    int count= listNodeCount(*p);
    if(pos>=count){
        printf("POS is out of scope\n");
        return;
    }
    struct node* temp,*t;
    t=*p;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Memory not allocated\n");
        return;
    }
    temp->next=NULL;
    __fpurge(stdin);
    printf("Enter Name of Student : ");
    scanf("%[^\n]",temp->student.name);
    printf("Enter PRN of student: ");
    scanf("%lld",&temp->student.prn);
     if (*p == NULL) {
        *p = temp; // If the list is empty, make the new node the head
    } else {
        for (int i = 1; i < pos - 1; i++) {
            t = t->next; // Traverse to the node just before the desired position
        }
        temp->next = t->next; // Connect the new node to the next node
        t->next = temp; // Connect the previous node to the new node
    }
}

void displayList(struct node *p){
	struct node* t;
    
    if(p==NULL){
        printf("No list present\n");
        return;
    }
    t = p;
    while (t != NULL) {
        printf("--->||name=%s|prn=%lld||", t->student.name,t->student.prn); // Print the data of each node in the list
        t = t->next;
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

void deleteByElement(struct node **p,long long int ele){
    struct node *t, *temp;
    t = *p;

    for (int i = 1; t->next->student.prn != ele; i++) {
        t = t->next; // Traverse to the node just before the desired position
    }

    temp = t->next; // The node at the specified position
    t->next = t->next->next; // Remove the reference to the node to be deleted
    printf("Element %lld is deleted\n",ele);
    free(temp); 
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
    
    printf("elements in reversed sequence \n");

    for(int i=size-1;i>=0;i--){
        printf("-->||name :%s|Prn =%lld||",h[i]->student.name,h[i]->student.prn);
    }
    printf("\n");

    free(h);
}

void freeAllNode(struct node **p){
	struct node *t1,*t2;
    int i =listNodeCount(*p);
    t1= *p;
    while(t1!=NULL){
        t2=t1;
        t1=t1->next;
        free(t2);        
    }
    *p=NULL;
}