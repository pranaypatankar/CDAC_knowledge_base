#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

void enqueue(struct Node**, int , int );
int dequeue(struct Node**);
int peek(struct Node*);
int isEmpty(struct Node*);

int main() {
    // Initialize an empty priority queue
    struct Node* head = NULL;

    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(&head, data, priority);
                break;
            case 2:
                if (!isEmpty(head)) {
                    printf("Popped element: %d\n", dequeue(&head));
                }
                break;
            case 3:
                if (!isEmpty(head)) {
                    printf("Peek: %d\n", peek(head));
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}


// Function to insert a node with a given data and priority into the priority queue
void enqueue(struct Node** head, int data, int priority) {
    struct Node* start = (*head);

    // Create a new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    if(temp==NULL){
    	printf("Memory cant be akkocated\n");
    	return;
    }

    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    // If the queue is empty or the new node has a higher priority, insert it at the beginning
    if (*head == NULL ||(*head)->priority > priority) {
        temp->next = *head;
        (*head) = temp;
    } else {
        // Traverse the list to find the correct position to insert the new node
        while (start->next != NULL && start->next->priority < priority) {
            start = start->next;
        }

        // Insert the new node at the correct position
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to remove and return the node with the highest priority
int dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    int data = (*head)->data;
    struct Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
    return data;
}

// Function to return the element with the highest priority (without removing it)
int peek(struct Node* head) {
    if (head == NULL) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    return head->data;
}

// Function to check if the priority queue is empty
int isEmpty(struct Node* head) {
    return (head == NULL);
}

