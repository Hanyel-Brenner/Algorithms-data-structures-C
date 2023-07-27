#include "geradorsenha.h"

void imprimeOpcoes(){
  printf("\n1 - Gerar senha normal\n");
  printf("2 - Gerar senha prioritaria\n");
  printf("3 - Imprimir senhas restantes em ordem de chegada\n");
  printf("4 - Chamar proxima pessoa\n");
  printf("5 - Sair\n");
}

int main(void) {
  tipoFila fila;
  tipoDados dados;
  int op = 0, nsenha = 0;
  char prioridade;

  inicializaFila(&fila);

    while (op!=6){
      imprimeOpcoes();
      printf("\nDigite o valor referente a opcao desejada: ");
      scanf("%d",&op);
      getchar();
      switch(op){
        case 1: 
        dados.prioridade = 'n';
        nsenha++;
        dados.senha = nsenha;
        printf("\nDigite o seu nome: ");
          fgets(dados.nome,30,stdin);
            if (adicionaItem(&fila, dados)){
              printf("\nSenha gerada com sucesso. A senha eh: %d\n",dados.senha);
            }else printf("\nERRO\n");
        break;

        case 2: 
        dados.prioridade = 'p';
        nsenha++;
        dados.senha = nsenha;
        printf("\nDigite o seu nome: ");
          fgets(dados.nome,30,stdin);
            if (adicionaItem(&fila, dados)){
              printf("\nSenha gerada com sucesso. A senha eh: %d\n",dados.senha);
            }else printf("\nERRO\n");
           break;

        case 3:
        imprimeFila(&fila);
        break;

        case 4:
        prioridade = decideSenha();
        
        if(!listaVazia(&fila)){
          removeItemPrioridade(&fila,&dados,prioridade);
            printf("\nCHAMANDO SENHA %d\n",dados.senha);
              if(dados.prioridade == 'n') printf("Prioridade: senha normal\n");
              else printf("Prioridade: senha prioritaria\n");
        }else printf("\nNao ha senha esperando chamada\n");
        break;
        
        case 6:
        printf("\nOperacoes encerradas.\n");
        break;
        
        default:   
        printf("\nPor favor, Digite uma opcao valida.\n");
        break;
      }
    }
  return 0;
}