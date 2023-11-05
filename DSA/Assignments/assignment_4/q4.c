#include <stdio.h>
#include <stdlib.h>

#define size 5

void display(int *);  // Function to display the elements of the circular queue.
void enqueue(int *, int *, int *, int);  // Function to enqueue an element.
int dequeue(int *, int *, int *);  // Function to dequeue an element.
int peep(int *, int, int);  // Function to peek at the front element.
void isQueueFull(int, int);  // Function to check if the queue is full.
void isQueueEmpty(int, int);  // Function to check if the queue is empty.

int main() {
    int arr[size];
    int choice, ele, ret;

    int front = -1;  // Initialize the front pointer to -1 (indicating an empty queue).
    int rear = -1;   // Initialize the rear pointer to -1 (indicating an empty queue).

    for (int i = 0; i < size; i++)
        arr[i] = -99;  // Initialize the array elements to a sentinel value (-99).

    while (1) {
        // Display menu for the user to select an operation
        printf("Select:\n1. Enqueue\n2. Dequeue\n3. Peep\n4. Display\n5. Is Queue Full\n6. Is Queue Empty\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter ele: ");
            scanf("%d", &ele);
            enqueue(arr, &front, &rear, ele);  // Enqueue the user-specified element.
            break;

        case 2:
            ret = dequeue(arr, &front, &rear);  // Dequeue an element if the queue is not empty.
            if (ret != -1) {
                printf("Popped Element = %d\n", ret);
                break;
            }
            break;

        case 3:
            ret = peep(arr, front, rear);  // Peek at the front element without removing it.
            printf("Peeped value: %d\n", ret);
            break;

        case 4:
            display(arr);  // Display the current elements in the queue.
            printf("\n\n");
            break;

        case 5:
            isQueueFull(front, rear);  // Check if the queue is full.
            break;

        case 6:
            isQueueFull(front, rear);  // Check if the queue is empty.
            break;

        case 7:
            exit(1);  // Exit the program.

        default:
            printf("Invalid Choice\n");  // Handle invalid menu choices.
            break;
        }
    }
    return 0;
}

void display(int *a) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", a[i]);  // Display each element in the circular queue.
    }
}

void enqueue(int *a, int *f, int *r, int e) {
    // Check if the queue is full (circular queue property).
    if ((*r == size - 1 && *f == 0) || (*r + 1 == *f)) {
        printf("Queue is Full\n");
        return;  // Exit the function if the queue is full.
    }

    if (*r == size - 1)
        *r = 0;  // Wrap around to the beginning of the array if rear reaches the end.
    else
        (*r)++;  // Move the rear pointer to the next position.
    a[*r] = e;  // Add the element to the circular queue.

    if (*f == -1)
        *f = 0;  // Update the front pointer if the queue was previously empty.
}

int dequeue(int *a, int *f, int *r) {
    if (*f == -1) {
        printf("End of Stack\n");  // Handle dequeue from an empty queue.
        return -1;  // Return -1 to indicate an error condition.
    }

    int ret = a[*f];  // Get the value at the front of the queue.
    a[*f] = -99;  // Clear the front position in the circular queue.

    if (*f == size - 1 && *r != size - 1)
        *f = 0;  // Wrap around to the beginning if front is at the end and rear is not.
    else if (*f != *r)
        (*f)++;  // Move the front pointer to the next position.
    else {
        *f = -1;  // Reset front and rear pointers when the queue becomes empty.
        *r = -1;
    }

    return ret;  // Return the dequeued value.
}

int peep(int *p, int a, int b) {
    if (a == -1) {
        printf("End of Stack\n");  // Handle peek on an empty queue.
        return -1;  // Return -1 to indicate an error condition.
    }

    int ret = p[a];  // Get the value at the front of the queue.

    return ret;  // Return the peeked value.
}

void isQueueFull(int a, int b) {
    if ((b == size - 1 && a == 0) || (b + 1 == a))
        printf("Queue is Full\n");  // Check and print whether the queue is full.
    else
        printf("Queue is Empty\n");  // Print that the queue is empty if it's not full.
}
