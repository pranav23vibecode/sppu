#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define SEATS 7

// Node structure for doubly linked list
struct Seat {
    int seatNo;
    int booked; // 0 = free, 1 = booked
    struct Seat* prev;
    struct Seat* next;
};

// Array of head pointers for rows
struct Seat* head[ROWS];

// Create doubly linked list for each row
void initializeTheater() {
    for (int i = 0; i < ROWS; i++) {
        head[i] = NULL;
        struct Seat* prevNode = NULL;

        for (int j = 1; j <= SEATS; j++) {
            struct Seat* newSeat =
                (struct Seat*)malloc(sizeof(struct Seat));

            newSeat->seatNo = j;
            newSeat->booked = rand() % 2; // random booking
            newSeat->prev = prevNode;
            newSeat->next = NULL;

            if (prevNode)
                prevNode->next = newSeat;
            else
                head[i] = newSeat; // first seat of row

            prevNode = newSeat;
        }
    }
}

// Display all seats
void displaySeats() {
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d: ", i + 1);
        struct Seat* temp = head[i];

        while (temp) {
            if (temp->booked == 0)
                printf("[S%d:Free] ", temp->seatNo);
            else
                printf("[S%d:Booked] ", temp->seatNo);

            temp = temp->next;
        }

        printf("\n");
    }
}

// Book a seat
void bookSeat(int row, int seat) {
    if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
        printf("Invalid Seat Selection!\n");
        return;
    }

    struct Seat* temp = head[row - 1];

    while (temp && temp->seatNo != seat)
        temp = temp->next;

    if (temp) {
        if (temp->booked == 0) {
            temp->booked = 1;
            printf("Seat Row %d Seat %d successfully booked.\n", row, seat);
        }
        else {
            printf("Seat already booked!\n");
        }
    }
}

// Cancel a seat booking
void cancelSeat(int row, int seat) {
    if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
        printf("Invalid Seat Selection!\n");
        return;
    }

    struct Seat* temp = head[row - 1];

    while (temp && temp->seatNo != seat)
        temp = temp->next;

    if (temp) {
        if (temp->booked == 1) {
            temp->booked = 0;
            printf("Booking cancelled for Row %d Seat %d.\n", row, seat);
        }
        else {
            printf("Seat is not booked!\n");
        }
    }
}

// Main Menu
int main() {
    int choice, row, seat;

    initializeTheater();

    while (1) {
        printf("\n--- Cinemax Theater Ticket Booking ---\n");
        printf("1. Display Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;

            case 2:
                printf("Enter Row (1-10) and Seat (1-7): ");
                scanf("%d %d", &row, &seat);
                bookSeat(row, seat);
                break;

            case 3:
                printf("Enter Row (1-10) and Seat (1-7): ");
                scanf("%d %d", &row, &seat);
                cancelSeat(row, seat);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}