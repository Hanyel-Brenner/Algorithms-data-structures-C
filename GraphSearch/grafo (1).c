#include "grafo.h"

Graph inicializaGrafo(int V){
  Graph grafo = (Graph)malloc(sizeof(struct graph));
  grafo->V = V;
  grafo->E = 0;
  grafo->adj = malloc(V* sizeof(Node));
    for(int i = 0; i<V; i++){
      grafo->adj[i]=NULL;
    }
  grafo->visited = malloc(V*sizeof(int)) ;
    for(int k=0; k<V; k++){
      grafo->visited[k] = 0;  //todos inicialmente brancos
    }
  return grafo;
}

Node inserirOrdenado(Node lista, int num){
  Node novo = malloc(sizeof(struct node));
  Node aux1,aux2;
  if(lista == NULL){
    novo->v = num;
    novo->prox = NULL;
    return novo;
  }
  else{
    aux1 = lista;  //inicio da lista
    aux2 = aux1->prox;
      if(num < aux1->v){
        novo->v = num;
        novo->prox = aux1;
        return novo;
      }
    
    while(1){
      if(aux2 == NULL && num > aux1->v){
        novo->v = num;
        aux1->prox = novo;
        novo->prox = NULL;
        
        return lista;
      }
      if(num < aux2->v){
        novo->v = num;
        novo->prox = aux2;
        aux1->prox = novo;
        return lista;
      }
      else{
      aux1 = aux2;
      aux2 = aux2->prox;
      }
    }
  }
}

Graph inserirGrafo(Graph grafo, int vertex, int w) {  
  for (Node x = grafo->adj[vertex]; x != NULL; x = x->prox) 
      if ((x->v == w) || (w == vertex)) {return grafo;}
  
    if(w <= grafo->V-1 && w != vertex){
      grafo->adj[vertex] = inserirOrdenado(grafo->adj[vertex],w);
      grafo->E++;
      return grafo;
    }
}

void imprimeSubListaGrafo(Graph grafo, int vertice){
  Node aux = grafo->adj[vertice];
  while(aux != NULL){
    printf("%d ",aux->v);
    aux = aux->prox;
  }
}

void imprimeLista(Node lista){
  Node ptrAux = lista;
  while(ptrAux != NULL){
    printf("%d ",ptrAux->v);
    ptrAux = ptrAux->prox;
  }
  if(ptrAux == NULL) printf("END");
}

void DFS(Graph grafo,int vertex){
  /*Nesse caso, todos os nos do grafo já devem ser brancos como
  foi feito na inicializacao,
  e o que e feito nessa função e que ela chamara a DFS visit
  para cada um dos vertices do grafo, mas especificamente 
  chamara o grafo com indice 'vertex'*/
  DFSvisit(grafo,vertex);
  
  for(int i=0; i<grafo->V; i++){
    if(grafo->visited[i] == 0){
      DFSvisit(grafo,i);
    } 
  }
  
}

void DFSvisit(Graph grafo, int u){
  // O no e pintado de cinza pois e visitado pela primeira vez;
  grafo->visited[u] = 1;
  printf("%d ",u);
  
  for(Node x=grafo->adj[u]; x != NULL; x = x->prox){
    if(grafo->visited[x->v] == 0){
      DFSvisit(grafo,x->v);
    }
  }
}



Node insereFila(Node fila, int num){
  Node aux = fila;
  Node novo = malloc(sizeof(struct node));
  if(aux != NULL){
      while(aux->prox != NULL){
        aux = aux->prox;
      }
        aux->prox = novo;
        novo->v = num;
        novo->prox = NULL;
  }else{
    fila = novo;
    novo->v = num;
    novo->prox = NULL;
  }
  return fila;
}

Node retiraFila(Node fila){  //retorna lista atualizada
  Node aux = fila;
    if(aux == NULL){  //fila vazia
      return NULL;
    }else{
      fila = fila->prox;
      free(aux);
      return fila;
    }
}

void BFS(Graph grafo,int verticeInicial){
  int removed;
  Node fila = NULL; //fila auxiliar que sera usada para todo o programa
  fila = insereFila(fila,verticeInicial);  //printa todos os nos na ordem em que sao visitados
 // imprimeLista(fila);

while(fila != NULL){
  removed = fila->v;
  fila = retiraFila(fila);
 // imprimeLista(fila);
  grafo->visited[removed] = 1; 
  printf("%d ",removed);

  
  for(Node x = grafo->adj[removed]; x != NULL; x = x->prox){
    if(grafo->visited[x->v] == 0){
      fila = insereFila(fila,x->v);
    }
  }
  
}
}