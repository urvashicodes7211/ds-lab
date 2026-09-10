/*Write a program to create a graph & implement the adjacency list 
representation of the graph 
 Apply DFS and BFS on the given graph. */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int vertex;
    struct Node *next;
};

struct Graph{
    int vertices;
    struct Node **adjList;
    int *visited;
};

struct Node* createNode(int vertex){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int vertices){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->vertices = vertices;

    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++){
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest){
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void displayGraph(struct Graph *graph){
    printf("\nAdjacency List:\n");

    for (int i = 0; i < graph->vertices; i++){
        struct Node *temp = graph->adjList[i];

        printf("%d -> ", i);

        while (temp != NULL){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

void DFS(struct Graph *graph, int vertex){
    struct Node *temp;

    graph->visited[vertex] = 1;

    printf("%d ", vertex);

    temp = graph->adjList[vertex];

    while (temp != NULL){
        if (graph->visited[temp->vertex] == 0){
            DFS(graph, temp->vertex);
        }

        temp = temp->next;
    }
}

void BFS(struct Graph *graph, int start){
    int queue[100];
    int front = 0;
    int rear = 0;

    int visited[100] = {0};

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear){
        int vertex = queue[front++];

        printf("%d ", vertex);

        struct Node *temp = graph->adjList[vertex];

        while (temp != NULL){
            if (visited[temp->vertex] == 0){
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }

            temp = temp->next;
        }
    }
}

int main(){
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");

    for (int i = 0; i < edges; i++){
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    displayGraph(graph);

    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);

    for (int i = 0; i < vertices; i++){
        graph->visited[i] = 0;
    }

    printf("DFS Traversal: ");
    DFS(graph, start);

    printf("\n\nEnter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(graph, start);

    return 0;
}