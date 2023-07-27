#include "geradorsenha.h"

void inicializaFila(tipoFila * fila){
  fila->inicio = NULL;
  fila->fim = NULL;
}

int listaVazia(tipoFila *fila){
  return fila->inicio == NULL;
}

void imprimeItem(tipoDados dados){
  printf("\nNome: %s \n", dados.nome);
  printf("senha: %d \n",dados.senha);
  if (dados.prioridade =='n') printf("Prioridade: senha normal\n");
  else printf("Prioridade: senha priortaria\n");
}

int imprimeFila(tipoFila *fila){
  tipoNode *ptrAux = fila->inicio;
  if (!listaVazia(fila)){
    while (ptrAux != NULL){
      imprimeItem(ptrAux->dados);
      ptrAux = ptrAux->prox;
      }
        return 1;
  }else return 0;
}

int adicionaItem(tipoFila *fila, tipoDados dados){
 tipoNode *newnode;
  newnode = (tipoNode*) malloc(sizeof(tipoNode));
  if(newnode!=NULL){
    if(!listaVazia(fila)){
      fila->fim->prox = newnode;
    }
    else{
      fila->inicio = newnode;
    }
    newnode->dados = dados;
    newnode->prox = NULL;
    fila->fim = newnode;
    return 1;
  }
  return 0;
}


int removeItemPrioridade(tipoFila *fila, tipoDados *dados, char prioridade){
  tipoNode *ptrAux, *ptrAnt;  //ptrAnt eh o elemento anterior ao elemento cuja prioridade eh requerida
  if (!listaVazia(fila) && verificaNXORchar(fila,'n','p')){
    ptrAux = fila->inicio;
        while(ptrAux->dados.prioridade != prioridade && ptrAux->prox != NULL){
            ptrAnt = ptrAux;
            ptrAux = ptrAux->prox;
        }
          if(ptrAux == fila->inicio) {
            fila->inicio = fila->inicio->prox;
            *dados = ptrAux->dados;
            }
            else if(ptrAux->prox == NULL) {
              fila->fim = ptrAnt;
              ptrAnt->prox = NULL;
              *dados = ptrAux->dados;
            }else{
              ptrAnt->prox = ptrAux->prox;
              *dados = ptrAux->dados;
            }
                return 1;
   }else if (!listaVazia(fila) && !verificaNXORchar(fila,'n','p')){
      ptrAux = fila->inicio;
      fila->inicio = fila->inicio->prox;
      *dados = ptrAux->dados;
      return 1;
   }else return 0;
}

char decideSenha(){
  int n;
  char prioridade;
  srand(time(NULL));
    n = rand()%100;
      if(n>=0 && n<70) prioridade = 'p';
      else prioridade = 'n';
        return prioridade;
}

int verificaNXORchar(tipoFila *fila, char n, char p){
  tipoNode *ptrAux;
  int charncounter = 0,charpcounter = 0;
  if(!listaVazia(fila)){
    ptrAux = fila->inicio;
      while (ptrAux->prox != NULL){
        if(ptrAux->dados.prioridade == n) charncounter++;
        else if (ptrAux->dados.prioridade == p) charpcounter++;
        else return 0;
          ptrAux = ptrAux->prox;
      }
  }else return 0;  
  if(charncounter == 0 || charpcounter ==0) return 0;
  else return 1; //isso significa que ha pelo menos um item da fila que contem o 'n' e que pelo menos um contem o 'p'
}
