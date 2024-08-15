#include <stdio.h>

// Function to perform shell sort on array
void shellSort(int arr[], int n) {
	int gap, i;
    // Start with a large gap, then reduce the gap
    for (gap = n/2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (i = gap; i < n; i++) {
            // Save arr[i] in temp and make a hole at position i
            int temp = arr[i];

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the shell sort
int main() {
     int n, i;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Ask user to input the array elements
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    shellSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

