#include "aluno.h"

int number_of_removals = 0;

void imprimeMenu(){
  printf("\n1 - Inserir Aluno.");
  printf("\n2 - Remover Aluno.");
  printf("\n3 - Listar Alunos.");
  printf("\n4 - Buscar Aluno.");
  printf("\n5 - Sair.");
}

void insereAluno(struct aluno turma[],int n){
  int i;

  getchar();
  printf("Nome: ");
  fgets(turma[n].nome,sizeof(turma[n].nome),stdin);
  turma[n].nome[strlen(turma[n].nome)-1] = '\0';
  printf("Data de Nascimento\n");
  printf("Dia: ");
  scanf("%i",&turma[n].dataNasc.dia);
  printf("Mes: ");
  scanf("%i",&turma[n].dataNasc.mes);
  printf("Ano: ");
  scanf("%i",&turma[n].dataNasc.ano);
  printf("RA: ");
  scanf("%i",&turma[n].ra);
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&turma[n].notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&turma[n].freq);
}

void listaAlunos(struct aluno turma[],int n){
  int i,j;

  for(i=0;i<n;i++){
    printf("\n\nNome: %s\n",turma[i].nome);
    printf("Data de Nascimento: %i/%i/%i\n",turma[i].dataNasc.dia,turma[i].dataNasc.mes,turma[i].dataNasc.ano);
    printf("RA: %i\n",turma[i].ra);
    for(j=0;j<3;j++)
      printf("Nota %i: %.2f\n",i+1,turma[i].notas[j]);
    printf("Frequencia: %i\n",turma[i].freq);
  }
}
void remover_aluno(struct aluno turma[], int n){
  struct aluno *pointer;
  int RA;
  printf("Para remover aluno, digite o RA correspondente: ");
  scanf("%d",&RA);
  for (int i=0;i<n;i++){
    if (turma[i].ra==RA){
      number_of_removals++;
       for (int j=i;j<n-number_of_removals;j++){
          turma[j]=turma[j+1];
          pointer = &turma[n-number_of_removals];
       }
            
    }
    
  }
}

void buscarAluno(struct aluno turma[],int n){
  int i,j,RA;
  printf("Digite o RA do aluno que deseja encontrar: ");
  scanf("%d",&RA);
      for (int i=0; i<n;i++ ) {
      if (turma[i].ra==RA){
    printf("\n\nNome: %s\n",turma[i].nome);
    printf("Data de Nascimento: %i/%i/%i\n",turma[i].dataNasc.dia,turma[i].dataNasc.mes,turma[i].dataNasc.ano);
    printf("RA: %i\n",turma[i].ra);
      for(j=0;j<3;j++){
        printf("Nota %i: %.2f\n",i+1,turma[i].notas[i]);}
        printf("Frequencia: %i\n",turma[i].freq);
        break;
        } else if (i==n-1)
          printf("\nAluno nao encontrado!\n");
      }
}