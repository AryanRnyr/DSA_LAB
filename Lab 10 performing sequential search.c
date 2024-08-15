#include <stdio.h>
int main() {
    int a[100], key, i, n;

    printf("Enter the number of elements in array (max 100):\n");
    scanf("%d", &n);

    if (n <= 0 && n > 100) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to search:\n");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("%d is present at location %d.\n", key, i + 1);
            break;
        }
    }

    if (i == n) {
        printf("%d is not present in array.\n", key);
    }

    return 0;
}
