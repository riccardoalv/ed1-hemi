#include <stdbool.h>

typedef struct elem {
  char val;
  struct elem *lig;
} char_elem;

typedef struct {
  char_elem *topo;
} pilha;

typedef struct elem_int {
  int val;
  struct elem_int *lig;
} int_elem;

typedef struct {
  int_elem *topo;
} pilha_int;

void define(pilha *p);

void empilha(char item, pilha *p);

void imprimir(pilha *p);

char_elem desempilha(pilha *p);

char topo(pilha *p);

void imprimir_inv(pilha *p);

bool limpar(pilha *p);

bool vazia(pilha *p);

bool palindromo(pilha *p);

bool elimina(char x, pilha *p);

void define_int(pilha_int *p);

int_elem desempilha_int(pilha_int *p);

void empilha_int(int x, pilha_int *p);

void imprimir_int(pilha_int *p);

void desempilha_impar_par(pilha_int *p, pilha_int *impar, pilha_int *par);

