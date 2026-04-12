#include<stdio.h>
#include "bfs.h"
#include "locations.h"

void bfs(struct Node* adjList[], int start){
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\n========================================\n");
    printf("Evacuation Order (BFS Traversal)\n");
    printf("========================================\n");

    while(front < rear){
        int node = queue[front++];

        printf("%s", locations[node]);

        struct Node* temp = adjList[node];
        while(temp) {
            if(temp->weight>0 && !visited[temp->vertex]){
                visited[temp->vertex] =1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
        if(front < rear)
            printf(" -> ");
    }
    printf("\n");
    
}