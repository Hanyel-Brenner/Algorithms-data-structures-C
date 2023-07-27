#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

typedef struct dados{
  char prioridade;
  int senha;
  char nome[30];
}tipoDados;

struct node{
  tipoDados dados;
  struct node *prox; 
};

typedef struct node tipoNode;

typedef struct fila{
  tipoNode *inicio;
  tipoNode *fim;
}tipoFila;

void inicializaFila(tipoFila *);
int listaVazia(tipoFila *);
void imprimeItem(tipoDados);
int imprimeFila(tipoFila *);
int adicionaItem(tipoFila *,tipoDados);
int removeItemPrioridade(tipoFila*,tipoDados *,char ); 
char decideSenha();
int verificaNXORchar(tipoFila *,char,char);  //verifica se ha a presenca de ambos os tipos de caractere 'n' e 'p' na fila, retorna 1 se houver, e retorna 0 caso nao
