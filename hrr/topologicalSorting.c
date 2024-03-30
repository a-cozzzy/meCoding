#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node*)malloc(vertices * sizeof(struct Node));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int vertex, int* stack, int* top) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = vertex;
}

void topologicalSort(struct Graph* graph) {
    int stack[MAX_VERTICES];
    int top = -1;
    int i;

    for (i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            DFS(graph, i, stack, &top);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    int i, src, dest;
    for (i = 0; i < E; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    topologicalSort(graph);

    return 0;
}