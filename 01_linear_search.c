#include <stdio.h>

#define MAX 100

void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Student with roll number %d has attended the training.\n", key);
            return;
        }
    }

    printf("Student with roll number %d has NOT attended the training.\n", key);
}

int main() {
    int rollNumbers[MAX], n, choice, key;

    printf("Enter number of students who attended training: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll %d: ", i + 1);
        scanf("%d", &rollNumbers[i]);
    }

    do {
        printf("\n---- Menu ----\n");
        printf("1. Search for a student\n");
        printf("2. Display all roll numbers\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number to search: ");
                scanf("%d", &key);
                linearSearch(rollNumbers, n, key);
                break;

            case 2:
                printf("Roll numbers of attended students: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", rollNumbers[i]);
                printf("\n");
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}