
#include <stdio.h>

#define MAX 20

int n;                     // number of cities
int adj[MAX][MAX];         // adjacency matrix
int visited[MAX];          // visited array

// Depth First Search
void DFS(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0/1):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start DFS from city 0
    DFS(0);

    // Check connectivity
    int connected = 1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("\nGraph is Connected\n");
    else
        printf("\nGraph is Not Connected\n");

    return 0;
}
