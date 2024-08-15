#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data);
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void deleteFromPosition(struct Node** head, int position);
void displayList(struct Node* node);
int getLength(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, position;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Delete from beginning\n");
        printf("2. Delete from end\n");
        printf("3. Delete from any position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromBeginning(&head);
                break;
            case 2:
                deleteFromEnd(&head);
                break;
            case 3:
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
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

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);

    printf("Node deleted from the beginning.\n");
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);

    printf("Node deleted from the end.\n");
}

void deleteFromPosition(struct Node** head, int position) {
	int i;
    int len = getLength(*head);

    if (position < 1 || position > len) {
        printf("Invalid position! The current list length is %d.\n", len);
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* temp = *head;
    for (i = 1; i < position; i++) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Node deleted from position %d.\n", position);
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

