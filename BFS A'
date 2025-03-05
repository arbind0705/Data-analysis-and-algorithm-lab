#include <iostream>
using namespace std;

#define MAX 10  // Adjust as needed

int adj[MAX][MAX];  // Adjacency matrix
bool visited[MAX];  // Visited array
int V, E;  // Number of vertices and edges

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void BFS(int start, int component[], int &size) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];
        component[size++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void findConnectedComponents() {
    cout << "Connected Components:\n";
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            int component[MAX], size = 0;
            BFS(i, component, size);

            for (int j = 0; j < size; j++) {
                cout << component[j] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    findConnectedComponents();
    
    return 0;
}
