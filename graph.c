#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "locations.h"

int danger[V] = {0};

struct Node* createNode(int v, int w){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adjList[], int u, int v, int w){
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

    addEdge(adjList, 0, 8,6);
    addEdge(adjList, 8, 9, 4);
    addEdge(adjList, 9, 4, 6);
    addEdge(adjList, 3, 6, 4);
    addEdge(adjList, 6, 7, 3);
}

void printGraph(struct Node* adjList[]){
    printf("\n=========== Campus Map ===========\n");

    for(int i = 0; i < V; i++) {
        if(danger[i])
            printf("%s [DANGER] : ", locations[i]);
        else
            printf("%s : ", locations[i]);

        struct Node* temp = adjList[i];
        while(temp) {
            printf("(%s, %d)", locations[temp->vertex], temp->weight);
            if(temp->next) printf(" -> ");
            temp = temp->next;
        }
        printf("\n");
    }
}

void setEmergency(int node) {
    danger[node] = 1;
}

void resetEmergency() {
    for(int i = 0; i < V; i++)
        danger[i] = 0;
}
