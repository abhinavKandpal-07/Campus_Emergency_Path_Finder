#include <stdio.h>
#include <limits.h>
#include "dijkstra.h"
#include "locations.h"

extern int danger[V];

int exits[] = {5, 7};

int minDistance(int dist[], int visited[]){
    int min = INT_MAX, index = -1;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void runDijkstra(struct Node* adjList[], int src, int dist[], int parent[]){
    int visited[V];

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        if(u == -1) break;

        visited[u] = 1;

        struct Node* temp = adjList[u];
        while(temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if(!visited[v] && danger[v] == 0 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }

            temp = temp->next;
        }
    }
}

void printPath(int parent[], int node) {
    if(parent[node] == -1) return;
    printf(" -> %s", locations[parent[node]]);
    printPath(parent, parent[node]);
}

void dijkstraMultiExit(struct Node* adjList[], int userNode) {
    int bestDist = INT_MAX;
    int bestExit = -1;
    int finalParent[V];

    if(danger[userNode]) {
        printf("\nWARNING: You are in a dangerous location!\n");
    }

    for(int e = 0; e < 2; e++) {
        int dist[V], parent[V];

        runDijkstra(adjList, exits[e], dist, parent);

        if(dist[userNode] < bestDist) {
            bestDist = dist[userNode];
            bestExit = exits[e];

            for(int i = 0; i < V; i++)
                finalParent[i] = parent[i];
        }
    }

    printf("\n=========== Evacuation Route ===========\n");

    if(bestDist == INT_MAX) {
        printf("No safe path available from %s\n", locations[userNode]);
        return;
    }

    printf("%s -> %s | Distance: %d\nPath: %s",
           locations[userNode],
           locations[bestExit],
           bestDist,
           locations[userNode]);

    printPath(finalParent, userNode);
    printf("\n");
}
