#include "aluno.h"
  
int main(){
  struct aluno turmaAED[50];
  int n = 0, op = 0, no_remocao=0;

  while(op != 5){
    imprimeMenu();
    printf("\nOpcao: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        insereAluno(turmaAED,n);
        n++;
        break;
      case 2:
        remover_aluno(turmaAED,n);
        n--;
        break;
      case 3:
        listaAlunos(turmaAED,n);
        break;
      case 4:
        buscarAluno(turmaAED,n);
        break;
      case 5:
        printf("\nEND.");
        break;
      default:
        printf("\nOpção Inválida.");
        
    }
  }

  return 0;
}



