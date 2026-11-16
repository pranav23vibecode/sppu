#include <stdio.h>
#include <string.h>

#define SIZE 10      // Hash Table Size

typedef struct {
    char name[20];
    long long phone;
} Client;

Client table[SIZE];       // Hash Table
int occupied[SIZE];       // 0 = empty, 1 = filled

// Hash Function
int hashFunction(long long phone) {
    return phone % SIZE;
}

// Linear Probing Insert
void insertLinear(char name[], long long phone) {
    int index = hashFunction(phone);
    int i;

    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (!occupied[newIndex]) {
            strcpy(table[newIndex].name, name);
            table[newIndex].phone = phone;
            occupied[newIndex] = 1;
            printf("Inserted at index %d\n", newIndex);
            return;
        }
    }

    printf("Hash Table Full (Linear Probing)\n");
}

// Quadratic Probing Insert
void insertQuadratic(char name[], long long phone) {
    int index = hashFunction(phone);
    int i;

    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (!occupied[newIndex]) {
            strcpy(table[newIndex].name, name);
            table[newIndex].phone = phone;
            occupied[newIndex] = 1;
            printf("Inserted at index %d\n", newIndex);
            return;
        }
    }

    printf("Hash Table Full (Quadratic Probing)\n");
}

// Double Hashing Insert
int secondHash(long long phone) {
    return 7 - (phone % 7); // second hash function
}

void insertDoubleHash(char name[], long long phone) {
    int index = hashFunction(phone);
    int step = secondHash(phone);
    int i;

    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i * step) % SIZE;

        if (!occupied[newIndex]) {
            strcpy(table[newIndex].name, name);
            table[newIndex].phone = phone;
            occupied[newIndex] = 1;
            printf("Inserted at index %d\n", newIndex);
            return;
        }
    }

    printf("Hash Table Full (Double Hashing)\n");
}

// Search function
void search(long long phone) {
    int index = hashFunction(phone);
    int i;

    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE; // Linear probing search

        if (occupied[newIndex] && table[newIndex].phone == phone) {
            printf("Found: %s - %lld at index %d\n",
                   table[newIndex].name,
                   table[newIndex].phone,
                   newIndex);
            return;
        }
    }

    printf("Not Found\n");
}

// Display Table
void displayTable() {
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++) {
        if (occupied[i])
            printf("[%d] %s : %lld\n", i, table[i].name, table[i].phone);
        else
            printf("[%d] Empty\n", i);
    }
}

int main() {
    int choice;
    char name[20];
    long long phone;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert (Linear)\n");
        printf("2. Insert (Quadratic)\n");
        printf("3. Insert (Double Hashing)\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name and phone: ");
                scanf("%s %lld", name, &phone);
                insertLinear(name, phone);
                break;

            case 2:
                printf("Enter name and phone: ");
                scanf("%s %lld", name, &phone);
                insertQuadratic(name, phone);
                break;

            case 3:
                printf("Enter name and phone: ");
                scanf("%s %lld", name, &phone);
                insertDoubleHash(name, phone);
                break;

            case 4:
                printf("Enter phone to search: ");
                scanf("%lld", &phone);
                search(phone);
                break;

            case 5:
                displayTable();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}