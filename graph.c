#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "locations.h"

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adjList[], int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adjList[u];
    adjList[u] = node;

    node = createNode(u, w);
    node->next = adjList[v];
    adjList[v] = node;
}

void initGraph(struct Node* adjList[]) {
    for(int i = 0; i < V; i++)
        adjList[i] = NULL;

    addEdge(adjList, 0, 1, 4);
    addEdge(adjList, 1, 2, 2);
    addEdge(adjList, 1, 3, 3);
    addEdge(adjList, 2, 4, 5);
    addEdge(adjList, 3, 4, 2);
    addEdge(adjList, 4, 5, 3);
}

void printGraph(struct Node* adjList[]) {
    printf("\n========================================\n");
    printf("Campus Map (Adjacency List Representation)\n");
    printf("========================================\n");

    for(int i = 0; i < V; i++) {
        printf("%s(%d) : ", locations[i], i);

        struct Node* temp = adjList[i];
        while(temp) {
            printf("(%s, %d)", locations[temp->vertex], temp->weight);
            if(temp->next) printf(" -> ");
            temp = temp->next;
        }
        printf("\n");
    }
}

void blockPath(struct Node* adjList[], int u, int v) {
    struct Node* temp = adjList[u];
    while(temp) {
        if(temp->vertex == v)
            temp->weight = 0;
        temp = temp->next;
    }

    temp = adjList[v];
    while(temp) {
        if(temp->vertex == u)
            temp->weight = 0;
        temp = temp->next;
    }
}