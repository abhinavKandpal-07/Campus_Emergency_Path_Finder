#ifndef GRAPH_H
#define GRAPH_H

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

void initGraph(struct Node* adjList[]);
void printGraph(struct Node* adjList[]);
void addEdge(struct Node* adjList[], int u, int v, int w);

void setEmergency(int node);
void resetEmergency();

#endif
