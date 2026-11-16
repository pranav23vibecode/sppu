#include <stdio.h>

// Function for Selection Sort
void selectionSort(float arr[], int n) {
    int i, j, minIndex;
    float temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function for Bubble Sort
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display top 5 scores
void displayTopFive(float arr[], int n) {
    int i, count = (n < 5) ? n : 5;

    printf("\nTop %d Scores:\n", count);

    for (i = n - 1; i >= n - count; i--) {
        printf("%.2f\n", arr[i]);
    }
}

int main() {
    int n, i, choice;
    float marks[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter percentages of students:\n");

    for (i = 0; i < n; i++) {
        scanf("%f", &marks[i]);
    }

    printf("\nChoose Sorting Method:\n1. Selection Sort\n2. Bubble Sort\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        selectionSort(marks, n);
        printf("\nArray sorted using Selection Sort.\n");
    } else {
        bubbleSort(marks, n);
        printf("\nArray sorted using Bubble Sort.\n");
    }

    displayTopFive(marks, n);

    return 0;
}