
#include <stdio.h>

#define MAX 5   // Maximum number of orders

int queue[MAX];
int front = 0, rear = -1;

// Add order (Enqueue)
void addOrder(int order) {
    if (rear == MAX - 1) {
        printf("Queue is Full! Cannot add more orders.\n");
    } else {
        queue[++rear] = order;
        printf("Order %d added successfully.\n", order);
    }
}

// Serve order (Dequeue)
void serveOrder() {
    if (front > rear) {
        printf("No orders to serve! Queue is empty.\n");
    } else {
        printf("Order %d served successfully.\n", queue[front]);
        front++;
    }
}

// Display queue
void displayOrders() {
    if (front > rear) {
        printf("No orders in the queue.\n");
    } else {
        printf("Current Orders: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, order;

    printf("Pizza Parlor Job Queue Simulation\n");

    do {
        printf("\n1. Add Order\n2. Serve Order\n3. Display Orders\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Order Number: ");
                scanf("%d", &order);
                addOrder(order);
                break;

            case 2:
                serveOrder();
                break;

            case 3:
                displayOrders();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

