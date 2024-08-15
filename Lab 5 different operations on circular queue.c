#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue *queue) {
    return ((queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1));
}

int isEmpty(CircularQueue *queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("%d enqueued to queue.\n", value);
}

void dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue->items[queue->front]);
    if (queue->front == queue->rear)
        initializeQueue(queue);
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
}

void display(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->items[i]);
    printf("%d\n", queue->items[i]);
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);
    int choice, item;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

