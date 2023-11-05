//Q2. Write a C/C++ program to implement doubly linked list.
//Implement below metioned functions. Apply all required condition
//check & validation like list empty or not, while inserting/deleting by
//position validate the position.
//a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
//e)listNodeCount f) deleteFromEnd g) deleteFromBeg
//h)deleteFromPos i) deleteByElement j) reverseDisplay
//k)freeAllNode l) reverseList m)sortedList


#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct node {
	struct node *prev;
    int data;
    struct node* next;
};

void insertBeg(struct node **, int);
void insertEnd(struct node **,int);
void insertPos(struct node **,int, int);
void display(struct node *);
void deleteBeg(struct node **);
void deleteEnd(struct node **);
void deletePos(struct node **,int);
void deleteEle(struct node **,int);
void reverseDisplay(struct node *);
void freeNode(struct node **);
void reverseList(struct node **);
void sortedList(struct node **);
int listNodeCount(struct node *);

int main() {
    struct node *head;
    head = NULL; // Initialize the head pointer to NULL
    int choice, ele, pos ,count;

    while (1) { // Infinite loop for menu-based interaction
        printf("\nMenu:\n1->Insert at begin\n2->Insert at end\n3->Insert at position\n4->Display\n5->Delete first node\n6->Delete from end\n7->Delete from position\n8->Delete By Element\n9->List Node Count\n10->Reverse Display\n11->Free Node\n12->Reverse Nodes\n13->Sort Nodes\n14->Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Value: ");
                scanf("%d", &ele);
                insertBeg(&head,ele); // Call the insertBeg function to add a node at the beginning
                break;

            case 2:
                printf("Enter Value: ");
                scanf("%d", &ele);
                insertEnd(&head,ele); // Call the insertEnd function to add a node at the end
                break;

            case 3:
                printf("Enter Value: ");
                scanf("%d", &ele);
                printf("Enter Position: ");
                scanf("%d", &pos);
                insertPos(&head,ele, pos); // Call the insertPos function to add a node at a specific position
                break;

            case 4:
                display(head); // Call the display function to print the linked list
                break;

            case 5:
                deleteBeg(&head); // Call the deleteBeg function to remove the first node
                break;

            case 6:
                deleteEnd(&head); // Call the deleteEnd function to remove the last node
                break;

            case 7:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deletePos(&head,pos); // Call the deletePos function to remove a node at a specific position
                break;

            case 8:
                printf("Enter Element to delete: ");
                scanf("%d",&ele);
                deleteEle(&head,ele);// Call the deleteEle function to remove a node at end
                break;

            case 9:
                count=listNodeCount(head); //Call the function to count list
                printf("No of Nodes :%d\n",count);
                break;

            case 10:
                reverseDisplay(head); //Call the function to display LL in reverse order
                break;

            case 11:
                freeNode(&head);  //freeing all nodes in LL
                head=NULL;
                break;

            case 12:
                reverseList(&head);
                break;

            case 13:
                sortedList(&head);
                break;

            case 14:
                exit(1);

            default:
                printf("Invalid choice\n"); // Handle an invalid menu choice
        }
    }
    return 0;
}

// Function to insert a node at the beginning of the linked list
void insertBeg(struct node **p,int ele) {
    struct node *temp,*t1;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory not Allocated\n");
        return;
    }

    temp->prev = NULL;
    temp->data = ele;
    temp->next=NULL;
    if(*p==NULL){
    	*p=temp;	
    }
    else{
	    temp->next = *p;
	    *p = temp;
	    temp->next->prev=*p; // Make the newly added node the new head
	}
}

// Function to insert a node at the end of the linked list
void insertEnd(struct node **p,int ele) {
    struct node *temp, *t;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory not Allocated\n");
        return;
    }
    temp->prev = NULL;
    temp->data = ele;
    temp->next = NULL;
    t=*p;

    if (*p == NULL) {
        *p = temp; // If the list is empty, make the new node the head
    } else {
        while (t->next != NULL) {
            t = t->next; // Traverse the list to find the last node
        }
        t->next = temp;
        temp->prev=t;// Add the new node at the end
    }
}

// Function to insert a node at a specific position in the linked list
void insertPos(struct node **p,int ele, int pos) {
    if (pos == 1) {
        insertBeg(p,ele); // If the position is 1, add the node at the beginning
        return;
    }
    int count= listNodeCount(*p);
    if(pos>=count){
        printf("POS is out of scope\n");
        return;
    }
    struct node *temp, *t;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory not Allocated\n");
        return;
    }
    t = *p;
    temp->prev = NULL;
    temp->data = ele;
    temp->next = NULL;

    if (*p == NULL) {
        *p = temp; // If the list is empty, make the new node the head
    } else {
        for (int i = 1; i < pos - 1; i++) {
            t = t->next; // Traverse to the node just before the desired position
        }
        temp->next = t->next; // Connect the new node to the next node
        t->next = temp; 
        temp->prev=t;
        // Connect the previous node to the new node
    }
    
}

// Function to display the linked list
void display(struct node *p) {
    struct node *t;
    
    if(p==NULL){
        printf("No list present\n");
        return;
    }
    t = p;
    while (t != NULL) {
        printf("--->||%p|%d|%p||",t->prev,t->data,t->next); // Print the data of each node in the list
        t = t->next;
    }
    printf("\n");
}

// Function to delete the first node from the linked list
void deleteBeg(struct node **p) {
    struct node* t, *temp;
    if (*p == NULL) {
        return; // If the list is empty, do nothing
    } else {
        t = *p;
        temp = *p;
        *p = t->next;
        t=*p;
        t->prev=NULL; 
        // Move the head to the next node
        printf("First element is deleted\n");
        free(temp); // Free the memory of the deleted node
    }
}

// Function to delete the last node from the linked list
void deleteEnd(struct node **p) {
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

// Function to delete a node from a specific position in the linked list
void deletePos(struct node **p,int pos) {
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

void deleteEle(struct node **p,int ele){
    struct node *t, *temp;
    t = *p;

    for (int i = 1; t->next->data != ele; i++) {
        t = t->next; // Traverse to the node just before the desired position
    }

    temp = t->next; // The node at the specified position
    t->next = t->next->next;
    t->next->prev=t; // Remove the reference to the node to be deleted
    printf("Element %d is deleted\n",ele);
    free(temp); 
}

void reverseDisplay(struct node *p){
    
    struct node *t;
    t=p;
//traversing until end of LL
    while(t->next!=NULL){
    	t=t->next;
    }
//printing LL in reverse order
    while(t!=p){
    	printf("---->||%p|%d|%p||",t->prev,t->data,t->next);
  		t=t->prev;
    }
    printf("---->||%p|%d|%p||",t->prev,t->data,t->next);
    printf("\n");
}

void freeNode(struct node **p){

    struct node *t1,*t2;
    int i =listNodeCount(*p);
    t1= *p;
    t2=t1->next;
    while(i){
        t2=t1->next;
        deleteBeg(&t1);
        t1=t2;
        i--;
        
    }
    
}

void reverseList(struct node **p){ 
    struct node *t1,*t2;
    int temp;

    t1=*p;
    t2=*p;

    while(t1->next!=NULL){
    	t1=t1->next;
    }
    while(t2!=t1){
    	temp=t1->data;
        t1->data=t2->data;
        t2->data=temp;
        t1=t1->prev;
        t2=t2->next;
    }

}

void sortedList(struct node **p){
    struct node *t1,*t2;

    int temp;
    int i =listNodeCount(*p);
    t1=*p;
    t2=t1;

    if(t1==NULL){
        return;
    }
    else{
        while(i>0){
            t1=*p;
            while(t1->next!=NULL){
                t2=t1;
                if(t2->data > t2->next->data){
                    temp= t2->data;
                    t2->data = t2->next->data;
                    t2->next->data = temp;
                }
                t1=t1->next;
            }
            i--;
        }
    }
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