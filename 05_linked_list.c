#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int roll) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = NULL;

    return newNode;
}

/* Insert element at end */
void insert(struct Node **head, int roll) {
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(roll);

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

/* Check whether element is present */
int isPresent(struct Node *head, int roll) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

/* Display set */
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Empty Set");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
}

/* Find intersection */
struct Node* getIntersection(struct Node *A, struct Node *B) {
    struct Node *result = NULL;
    struct Node *temp = A;

    while (temp != NULL) {
        if (isPresent(B, temp->roll)) {
            insert(&result, temp->roll);
        }

        temp = temp->next;
    }

    return result;
}

/* Find symmetric difference */
struct Node* getSymDiff(struct Node *A, struct Node *B) {
    struct Node *result = NULL;
    struct Node *temp;

    /* Elements in A but not in B */
    temp = A;

    while (temp != NULL) {
        if (!isPresent(B, temp->roll)) {
            insert(&result, temp->roll);
        }

        temp = temp->next;
    }

    /* Elements in B but not in A */
    temp = B;

    while (temp != NULL) {
        if (!isPresent(A, temp->roll)) {
            insert(&result, temp->roll);
        }

        temp = temp->next;
    }

    return result;
}

/* Find union */
struct Node* getUnion(struct Node *A, struct Node *B) {
    struct Node *result = NULL;
    struct Node *temp;

    /* Insert all elements of A */
    temp = A;

    while (temp != NULL) {
        insert(&result, temp->roll);
        temp = temp->next;
    }

    /* Insert elements of B which are not in A */
    temp = B;

    while (temp != NULL) {
        if (!isPresent(result, temp->roll)) {
            insert(&result, temp->roll);
        }

        temp = temp->next;
    }

    return result;
}

/* Count number of nodes */
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    struct Node *A = NULL;
    struct Node *B = NULL;

    struct Node *intersection;
    struct Node *symDiff;
    struct Node *unionSet;

    int n, i, roll;

    printf("Enter total number of students: ");
    scanf("%d", &n);

    /* Set A */
    printf("\nEnter roll numbers of students who like Vanilla:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &roll);
        insert(&A, roll);
    }

    /* Set B */
    printf("\nEnter roll numbers of students who like Butterscotch:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &roll);
        insert(&B, roll);
    }

    printf("\nSet A (Vanilla): ");
    display(A);

    printf("\nSet B (Butterscotch): ");
    display(B);

    /* Intersection */
    intersection = getIntersection(A, B);

    printf("\n\nStudents who like both Vanilla and Butterscotch: ");
    display(intersection);

    /* Symmetric Difference */
    symDiff = getSymDiff(A, B);

    printf("\n\nStudents who like either Vanilla or Butterscotch, but not both: ");
    display(symDiff);

    /* Union */
    unionSet = getUnion(A, B);

    printf("\n\nStudents who like at least one ice-cream: ");
    display(unionSet);

    /* Neither */
    printf("\n\nNumber of students who like neither: ");

    printf("%d", n - countNodes(unionSet));

    return 0;
}