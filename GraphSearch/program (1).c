#include "grafo.h"

void Menu();

int main(void) {
  int choice = 0, size,vertex, toInsert, startNode;
  Graph graph;
  
  printf("Welcome. In this application you can perform DFS and BFS searches in a graph of integers\n");
  printf("\nPlease, enter limit number of nodes for your graph: ");
  scanf("%d",&size);
  graph = inicializaGrafo(size);

  while(choice != 4){
    Menu();
    printf("\nEnter option >>>_");
    scanf("%d",&choice);
    
    switch(choice){
      case 1:
      printf("\nType the node you wish to insert into >>>_");
      scanf("%d", &vertex);
      printf("\nType the node number >>>_");
      scanf("%d", &toInsert);
      graph = inserirGrafo(graph, vertex, toInsert);
      printf("\nYou inserted the node %d into the graph\n",toInsert);
      break;
      
      case 2:
      printf("Type the node by which the search should begin >>>_");
      scanf("%d",&startNode);
      printf("\nBFS:");
      BFS(graph,startNode);
      printf("\n");
      break;
      
      case 3:
      printf("Type the node by which the search should begin >>>_");
      scanf("%d",&startNode);
      printf("\nDFS:");
      DFS(graph,startNode);
      printf("\n");
      break;
      
      case 4:
      printf("You exited application...");
      break;
      
      default:
        printf("Please type a valid option...");
      break;
    }
    
  }
  
  return 0;
}

void Menu(){
  printf("\n1.Insert node");
  printf("\n2.Breadth-First-Search");
  printf("\n3.Deapth-First-Search");
  printf("\n4.End application\n");
}