#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "dijkstra.h"
#include "locations.h"

// convert name->index
int getLocationIndex(char input[]){
    for(int i = 0; i < V; i++){
        if(strcmp(input, locations[i]) == 0)
            return i;
    }
    return -1;
}

int main(){
    struct Node* graph[V];
    initGraph(graph);

    int choice;
    char name[50];
    int userNode, emergencyNode;

    while(1){
        printf("\n=========== MENU ===========\n");
        printf("1. Show Campus Map\n");
        printf("2. Find Evacuation Route\n");
        printf("3. Add Emergency Location\n");
        printf("4. Reset System\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printGraph(graph);
                break;

            case 2:
                printf("Enter your location name: ");
                scanf(" %[^\n]", name);

                userNode = getLocationIndex(name);

                if(userNode == -1) {
                    printf("Invalid location name\n");
                    break;
                }

                dijkstraMultiExit(graph, userNode);
                break;

            case 3:
                printf("Enter emergency location name: ");
                scanf(" %[^\n]", name);

                emergencyNode = getLocationIndex(name);

                if(emergencyNode == -1) {
                    printf("Invalid location name\n");
                    break;
                }

                setEmergency(emergencyNode);
                printf("%s marked as DANGER\n", locations[emergencyNode]);
                break;

            case 4:
                resetEmergency();
                printf("System reset. All locations are safe now.\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
