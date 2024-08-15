#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to delete a node with given value from the list
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the first node
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the previous node of the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the list
    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to free memory allocated to the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete a node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                freeList(head);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

