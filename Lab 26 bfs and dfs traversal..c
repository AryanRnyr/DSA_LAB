#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    bool visited[MAX_VERTICES];
    int** adjMatrix;
};

struct Graph* createGraph(int numVertices) {
	int i, j;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (j = 0; j < numVertices; j++)
            graph->adjMatrix[i][j] = 0;
    }

    for (i = 0; i < numVertices; i++)
        graph->visited[i] = false;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void BFS(struct Graph* graph, int startVertex) {
	int i;
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    queue[++rear] = startVertex;
    visited[startVertex] = true;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

void DFS(struct Graph* graph, int startVertex) {
	int i;
    if (graph->visited[startVertex])
        return;

    graph->visited[startVertex] = true;
    printf("%d ", startVertex);

    for (i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[startVertex][i] == 1 && !graph->visited[i])
            DFS(graph, i);
    }
}

int main() {
	int i;
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("BFS Traversal: ");
    BFS(graph, 0);
    printf("\n");

    for (i = 0; i < graph->numVertices; i++)
        graph->visited[i] = false;

    printf("DFS Traversal: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
