#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 11
#define C1 1
#define C2 3

struct HashTable {
    int *keys;
    int size;
};

int hash(int key, int m) {
    return key % m;
}

struct HashTable* initHashTable(int size) {
	int i;
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->keys = (int*)malloc(size * sizeof(int));
    ht->size = size;
    for (i = 0; i < size; i++) {
        ht->keys[i] = -1;
    }
    return ht;
}

void quadraticProbe(struct HashTable* ht, int key, int m) {
    int hashValue = hash(key, m);
    int i = 0;
    while (ht->keys[hashValue] != -1) {
        hashValue = (hash(key, m) + C1 * i + C2 * i * i) % m;
        if (ht->keys[hashValue] == key)
            return;
        i++;
    }
    ht->keys[hashValue] = key;
}

void displayHashTable(struct HashTable* ht) {
	int i;
    printf("Hash Table:\n");
    for (i = 0; i < ht->size; i++) {
        printf("%d: %d\n", i, ht->keys[i] == -1 ? -1 : ht->keys[i]);
    }
}

int main() {
	int i;
    struct HashTable* ht = initHashTable(TABLE_SIZE);

    int keys[] = {76, 26, 37, 5, 9, 21, 65, 85};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (i = 0; i < numKeys; i++) {
        quadraticProbe(ht, keys[i], TABLE_SIZE);
    }

    displayHashTable(ht);

    free(ht->keys);
    free(ht);
    return 0;
}

