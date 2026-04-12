#include<stdio.h>
#include<limits.h>
#include "dijkstra.h"
#include "locations.h"

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, index = -1;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void printPath(int parent[], int j) {
    if(parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf(" -> %s", locations[j]);
}

void dijkstra(struct Node* adjList[], int src) {
    int dist[V], visited[V], parent[V];

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        struct Node* temp = adjList[u];

        while(temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if(!visited[v] && w > 0 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    printf("\n========================================\n");
    printf("Shortest Paths from %s\n", locations[src]);
    printf("========================================\n");

    for(int i = 0; i < V; i++) {
        printf("%-12s : ", locations[i]);

        if(dist[i] == INT_MAX) {
            printf("Not reachable\n");
        } else {
            printf("%3d | Path: %s", dist[i], locations[src]);
            printPath(parent, i);
            printf("\n");
        }
    }
}