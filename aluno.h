#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
  int dia;
  int mes;
  int ano;
};

struct aluno{
  char nome[30];
  struct data dataNasc;
  int ra;
  float notas[3];
  int freq;
};

void imprimeMenu();
void insereAluno(struct aluno turma[],int);
void listaAlunos(struct aluno turma[],int);
void buscarAluno(struct aluno[],int);
void remover_aluno(struct aluno[],int);