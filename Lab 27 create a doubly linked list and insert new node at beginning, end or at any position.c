#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next; 
};

void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void displayList(struct Node* node);
int getLength(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert (1-based index): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
    printf("Node inserted at the beginning.\n");
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        printf("Node inserted at the end.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at the end.\n");
}

void insertAtPosition(struct Node** head, int data, int position) {
	int i;
    int len = getLength(*head);

    if (position < 1 || position > len + 1) {
        printf("Invalid position! The current list length is %d.\n", len);
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = *head;

    for (i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly linked list: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int getLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

