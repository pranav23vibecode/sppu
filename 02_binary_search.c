#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return 1; // Found

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return 0; // Not found
}

int main() {
    int n, roll[100], key, found, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter sorted roll numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    found = binarySearch(roll, n, key);

    if (found)
        printf("Student with roll number %d attended the training program.\n", key);

    else
        printf("Student with roll number %d did NOT attend the training program.\n", key);

    return 0;
}