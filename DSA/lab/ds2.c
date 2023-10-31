/*Created on OCT 18,2023
	by Pranay Patankar */

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct node {
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
        printf("1->Insert at begin\n2->Insert at end\n3->Insert at position\n4->Display\n5->Delete first node\n6->Delete from end\n7->Delete from position\n8->Exit\n");
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
    temp->next = *p;
    *p = temp; // Make the newly added node the new head
}

// Function to insert a node at the end of the linked list
void insertEnd(struct node **p,int ele) {
    struct node* temp, *t;
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

    struct node* temp, *t;
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
}

// Function to display the linked list
void display(struct node *p) {
    struct node* t;
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
    struct node* t, *temp;
    t = *p;

    for (int i = 1; i < pos - 1; i++) {
        t = t->next; // Traverse to the node just before the desired position
    }

    temp = t->next; // The node at the specified position
    t->next = t->next->next; // Remove the reference to the node to be deleted
    printf("Element at position %d is deleted\n",pos);
    free(temp); // Free the memory of the deleted node
}