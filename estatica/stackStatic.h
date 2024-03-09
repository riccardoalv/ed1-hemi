#include <stdbool.h>

#define MAXP 1000
#define indice int

typedef struct {
  char A[MAXP + 1];
  indice topo;
} pilha;

typedef struct {
  char A[MAXP + 1];
  indice topo;
} pilha_int;

void define(pilha *p);

bool empilha(char item, pilha *p);

bool vazia(pilha *p);

bool cheia(pilha *p);

void esvaziar(pilha *p);

char top(pilha *p);

char desempilha(pilha *p);

char pop(pilha *p);

void imprimir(pilha *p);

bool limpar(pilha *p);

bool palindromo(pilha *p);

bool elimina(char x, pilha *p);

void imprimir_inv(pilha *p);

void define_int(pilha_int *p);

int desempilha_int(pilha_int *p);

bool empilha_int(int x, pilha_int *p);

void desempilha_impar_par(pilha_int *p, pilha_int *impar, pilha_int *par);
