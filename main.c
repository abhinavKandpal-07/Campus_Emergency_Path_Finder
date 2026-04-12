#include<stdio.h>
#include "graph.h"
#include "dijkstra.h"
#include "bfs.h"
#include "locations.h"

int main() {

    struct Node* graph[V];
    int choice;

    initGraph(graph);

    while(1){
        printf("\n========================================\n");
        printf("   CAMPUS EMERGENCY PATH FINDER SYSTEM\n");
        printf("========================================\n");

        printf("1. Show Campus Map\n");
        printf("2. Find Shortest Path (Dijkstra)\n");
        printf("3. Evacuation Order (BFS)\n");
        printf("4. Simulate Emergency\n");
        printf("5. Exit\n");

        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){

            case 1:
                printGraph(graph);
                break;
            case 2:
                dijkstra(graph, 0);
                break;
            case 3:
                bfs(graph, 0);
                break;
            case 4: {
                int u, v;
                printf("\n----------------------------------------\n");
                printf("Emergency Simulation\n");
                printf("----------------------------------------\n");

                printf("Enter locations to block (u v): ");
                scanf("%d %d", &u, &v);

                blockPath(graph, u, v);

                printf("Blocked path between %s and %s\n", locations[u], locations[v]);
                break;
            }
            case 5:
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}