//Q2. Write a C/C++ program to implement single linked list.
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
                deleteEle(&head,ele);
                break;

            case 9:
                count=listNodeCount(head);
                printf("No of Nodes :%d\n",count);
                break;

            case 10:
                reverseDisplay(head);
                break;

            case 11:
                freeNode(&head);
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
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = *p;
    *p = temp; // Make the newly added node the new head
}

// Function to insert a node at the end of the linked list
void insertEnd(struct node **p,int ele) {
    struct node *temp, *t;
    temp = (struct node*)malloc(sizeof(struct node));
    t = *p;
    temp->data = ele;
    temp->next = NULL;

    if (*p == NULL) {
        *p = temp; // If the list is empty, make the new node the head
    } else {
        while (t->next != NULL) {
            t = t->next; // Traverse the list to find the last node
        }
        t->next = temp; // Add the new node at the end
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
    t = *p;
    temp->data = ele;
    temp->next = NULL;

    if (*p == NULL) {
        *p = temp; // If the list is empty, make the new node the head
    } else {
        for (int i = 1; i < pos - 1; i++) {
            t = t->next; // Traverse to the node just before the desired position
        }
        temp->next = t->next; // Connect the new node to the next node
        t->next = temp; // Connect the previous node to the new node
    }
    free(temp);
}

// Function to display the linked list
void display(struct node *p) {
    struct node* t;
    
    if(p==NULL){
        printf("No list present\n");
        return;
    }
    t = p;
    while (t != NULL) {
        printf("--->%d", t->data); // Print the data of each node in the list
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
        *p = t->next; // Move the head to the next node
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
    t->next = t->next->next; // Remove the reference to the node to be deleted
    printf("Element %d is deleted\n",ele);
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
        printf("%d\t",h[i]->data);
    }
    printf("\n");

    free(h);
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
    struct node *t;

    struct node **h;

    int size = listNodeCount(*p);

    h=(struct node  **)malloc(sizeof(struct node *)*size);

    t = *p;

    h[0]=t;

    for(int i =1;t->next!=NULL;i++){
        h[i]=t->next;
        t=t->next;
    }

    t=h[size-1];
    *p=t;
    for(int i=size-2;i>=0;i--){
        t->next=h[i];
        t=t->next;
    }
    t->next=NULL;

    free(h);
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
                if(t2->data>t2->next->data){
                    temp=t2->data;
                    t2->data=t2->next->data;
                    t2->next->data=temp;
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