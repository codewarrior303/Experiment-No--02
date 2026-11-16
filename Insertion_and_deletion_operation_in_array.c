#include <stdio.h>

#define MAX 100

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int arr[MAX], n, choice, pos, value;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (n < 1 || n > MAX) {
        printf("Invalid size!\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    // Menu Loop
    for (choice = 0; choice != 4; ) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        // Insert
        if (choice == 1) {
            if (n == MAX) {
                printf("Array is full!\n");
            } else {
                printf("Enter position and value: ");
                if (scanf("%d %d", &pos, &value) != 2) {
                    printf("Invalid input!\n");
                    clear_input_buffer();
                    continue;
                }
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                } else {
                    for (int i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos - 1] = value;
                    n++;
                    printf("Element inserted!\n");
                }
            }
        }
        // Delete
        else if (choice == 2) {
            if (n == 0) {
                printf("Array is empty!\n");
            } else {
                printf("Enter position: ");
                if (scanf("%d", &pos) != 1) {
                    printf("Invalid input!\n");
                    clear_input_buffer();
                    continue;
                }
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (int i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Element deleted!\n");
                }
            }
        }
        // Display
        else if (choice == 3) {
            if (n == 0) {
                printf("Array is empty!\n");
            } else {
                printf("Array elements: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        }
        // Exit
        else if (choice == 4) {
            printf("Program exited!\n");
        }
        // Invalid Choice
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}