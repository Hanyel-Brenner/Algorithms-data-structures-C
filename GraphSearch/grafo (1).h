#include <stdio.h>
#include <malloc.h>

#define BRANCO 0;
#define CINZA 1;
#define PRETO 2;

struct node{
  int v;  // numero que representa o vertice
  struct node* prox;
};

typedef struct node* Node;

struct graph{
  int V, E;  //numero de vertices e arestas do grafo
  int *visited;
  Node* adj;
};

typedef struct graph* Graph;


Graph inicializaGrafo(int V);
Node novoNo(int vertice, Node prox);
Node inserirOrdenado(Node,int);
Graph inserirGrafo(Graph,int,int);
void imprimeSubListaGrafo(Graph, int);
void imprimeLista(Node);
void DFS(Graph,int);
void DFSvisit(Graph,int);

Node retiraFila(Node);
Node insereFila(Node,int);
void BFS(Graph,int);