#ifndef GRAPH_H
#define GRAPH_H

#define V 6

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

void initGraph(struct Node* adjList[]);
void printGraph(struct Node* adjList[]);
void blockPath(struct Node* adjList[], int u, int v);

#endif