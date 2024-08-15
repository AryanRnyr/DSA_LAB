#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 11

typedef struct {
    int key;
    int value;
} HashItem;

HashItem* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int hashIndex = hashFunction(key);

    while (hashTable[hashIndex] != NULL) {
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }

    hashTable[hashIndex] = (HashItem*)malloc(sizeof(HashItem));
    hashTable[hashIndex]->key = key;
    hashTable[hashIndex]->value = key;

    printf("Inserted key %d at index %d\n", key, hashIndex);
}

void display() {
	int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d: key %d\n", i, hashTable[i]->key);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
}

int main() {
	int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    int keys[] = {76, 26, 37, 5, 9, 21, 65, 85};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (i = 0; i < numKeys; i++) {
        insert(keys[i]);
    }
    printf("\n\n");
    display();
    return 0;
}
