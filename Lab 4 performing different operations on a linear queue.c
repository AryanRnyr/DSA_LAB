#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a linear queue
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

// Function prototypes
void initQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);
int i;

int main() {
    Queue q;
    int choice, value;

    initQueue(&q);

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (!isFull(&q)) {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                } else {
                    printf("Queue is full.\n");
                }
                break;
            case 2:
                if (!isEmpty(&q)) {
                    printf("Dequeued element: %d\n", dequeue(&q));
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 3:
                if (!isEmpty(&q)) {
                    printf("Queue elements: ");
                    display(&q);
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to enqueue an element into the queue
void enqueue(Queue *q, int value) {
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue *q) {
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Function to display elements of the queue
void display(Queue *q) {
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
