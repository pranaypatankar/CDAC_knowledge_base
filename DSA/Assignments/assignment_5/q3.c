/*Created on OCT 18,2023
	by Pranay Patankar */

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct node {
    struct node *prev;
    int data;
    struct node* next;
};

// Function to insert a node at the beginning of the linked list
void insertBeg(struct node **, int);

// Function to insert a node at the end of the linked list
void insertEnd(struct node **,int);

// Function to insert a node at a specific position in the linked list
void insertPos(struct node **,int, int);

// Function to display the linked list
void display(struct node *);

// Function to delete the first node from the linked list
void deleteBeg(struct node **);

// Function to delete the last node from the linked list
void deleteEnd(struct node **);

// Function to delete a node from a specific position in the linked list
void deletePos(struct node **,int);



int main() {
    struct node* head;
    head = NULL; // Initialize the head pointer to NULL
    int choice, ele, pos;

    while (1) { // Infinite loop for menu-based interaction
        printf("\n1->Insert at begin\n2->Insert at end\n3->Insert at position\n4->Display\n5->Delete first node\n6->Delete from end\n7->Delete from position\n8->Exit\nEnter your choice:");
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
                exit(1); // Exit the program

            default:
                printf("Invalid choice\n"); // Handle an invalid menu choice
        }
    }
    return 0;
}

// Function to insert a node at the beginning of the linked list
void insertBeg(struct node **p,int ele) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    struct node *t1 = *p;
    temp->prev=NULL;
    if(*p==NULL){
        *p=temp;
        temp->next = *p;
    }
    else{
        temp->next = *p;
        temp->next->prev=temp;
        while(t1->next!=*p){
            t1=t1->next;
        }
        temp->prev=t1;
        t1->next=temp;
        //t1->prev=temp;
        *p = temp; // Make the newly added node the new head
    }
}

// Function to insert a node at the end of the linked list
void insertEnd(struct node **p,int ele) {
    struct node* temp, *t;
    temp = (struct node*)malloc(sizeof(struct node));
    t = *p;
    temp->data = ele;
    temp->next = *p;
    temp->prev=NULL;

    if (*p == NULL) {
        *p = temp; // If the list is empty, make the new node the head
        temp->next=*p;
    } else {
        while (t->next != *p) {
            t = t->next; // Traverse the list to find the last node
        }
        t->next = temp;
        temp->prev=t; // Add the new node at the end
        (*p)->prev=temp;
    }
}

// Function to insert a node at a specific position in the linked list
void insertPos(struct node **p,int ele, int pos) {
    if (pos == 1) {
        insertBeg(p,ele); // If the position is 1, add the node at the beginning
        return;
    }

    struct node* temp, *t;
    temp = (struct node*)malloc(sizeof(struct node));
    t = *p;
    temp->data = ele;
    temp->next = NULL;
    temp->prev=NULL;

    if (*p == NULL) {
        *p = temp;
        temp->next =*p; // If the list is empty, make the new node the head
    } else {
        for (int i = 1; i < pos - 1; i++) {
            t = t->next; // Traverse to the node just before the desired position
        }
        temp->next = t->next; // Connect the new node to the next node
        t->next = temp; 
        temp->prev=t;// Connect the previous node to the new node
    }
}

// Function to display the linked list
void display(struct node *p) {
    struct node* t;
    t = p;
    printf("||head|%p||",p);
    do{
        printf("--->||%p|%d|%p||",t->prev, t->data,t->next); // Print the data of each node in the list
        t = t->next;
    }
    while (t!=p); 
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
        t->prev=NULL;
        while(t->next!=temp){
            t=t->next;
        }
        t->next=*p;
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
        do{
            t = t->next;
        }
        while (t->next != *p);
        temp = t->next; // The last node to be deleted
        t->next = *p; // Remove the reference to the last node
        printf("Last element is deleted\n");
        free(temp); // Free the memory of the deleted node
    }
}

// Function to delete a node from a specific position in the linked list
void deletePos(struct node **p,int pos) {
    struct node* t, *temp;
    t = *p;

    for (int i = 1; i < pos - 1; i++) {
        t = t->next; // Traverse to the node just before the desired position
    }

    temp = t->next; // The node at the specified position
    t->next = t->next->next; 
    t->next->prev=t;// Remove the reference to the node to be deleted
    printf("Element at position %d is deleted\n",pos);
    free(temp); // Free the memory of the deleted node
}