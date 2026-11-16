
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert node into BST
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

// Find minimum value
int findMin(struct Node* node) {
    while (node->left != NULL)
        node = node->left;

    return node->data;
}

// Find height (longest path)
int height(struct Node* node) {
    if (node == NULL) return 0;

    int l = height(node->left);
    int r = height(node->right);

    return (l > r ? l : r) + 1;
}

// Mirror tree
void mirror(struct Node* node) {
    if (node == NULL) return;

    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);
}

// Search in BST
struct Node* search(struct Node* node, int key) {
    if (node == NULL || node->data == key)
        return node;

    if (key < node->data)
        return search(node->left, key);

    return search(node->right, key);
}

// Inorder traversal (for display)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    // Initial tree
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Display Inorder Traversal\n");
        printf("3. Find Height (Longest Path)\n");
        printf("4. Find Minimum Value\n");
        printf("5. Mirror Tree\n");
        printf("6. Search Value\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Height of tree: %d\n", height(root));
                break;

            case 4:
                printf("Minimum value: %d\n", findMin(root));
                break;

            case 5:
                mirror(root);
                printf("Tree mirrored!\n");
                break;

            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value) != NULL)
                    printf("Value %d found in tree.\n", value);
                else
                    printf("Value %d not found.\n", value);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 7);

    return 0;
}

