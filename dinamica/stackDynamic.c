#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackDynamic.h"

void imprimir(pilha *p){
  if (p->topo == NULL) {
    printf("Lista esta vazia\n");
    return;
  }
  char_elem *it = p->topo;
  int i = 0;

  while(it != NULL){
    printf("%d | %c |\n", i, it->val);
    it = it->lig;
    i++;
  }
}

void empilha(char x, pilha *p) {
  char_elem *q = malloc(sizeof(char_elem));

  q->val = x;
  q->lig = p->topo;
  p->topo = q;

  printf("Inserindo elemento %c\n", x);
}

void define(pilha *p) {
  printf("Pilha Definida\n");
  p->topo = NULL;
}

bool vazia(pilha *p){
  if(p->topo == NULL){
    printf("Lista esta Vazia!\n");
    return true;
  } else {
    printf("Lista nao esta Vazia!\n");
    return false;
  }
  return (p->topo == NULL);
}

char topo(pilha *p){
  return p->topo->val;
}

char_elem desempilha(pilha *p){
  printf("Desempilhando\n");
  if(p->topo != NULL){
    char_elem *q = p->topo;
    p->topo = p->topo->lig;
    return *q;
  } else{
    printf("topo is NULL");
  }
}

void imprimir_inv(pilha *p){
  pilha b;
  define(&b);


  char_elem *it = p->topo;

  while(it != NULL){
    empilha(it->val, &b);
    it = it->lig;
  }

  imprimir(&b);
}

bool limpar(pilha *p){
  if(p->topo == NULL) return false;

  printf("Limpando Pilha\n");
  p->topo = NULL;

  return true;
}

bool palindromo(pilha *p){
  pilha b;
  define(&b);

  bool ans = true;
  char_elem *it = p->topo;

  while(it != NULL){
    empilha(it->val, &b);
    it = it->lig;
  }

  it = p->topo;
  char_elem *it2 = b.topo;

  while(it != NULL){
    if(it->val != it2->val){
      return false;
    }
    it2 = it2->lig;
    it = it->lig;
  }

  return ans;
}

bool elimina(char x, pilha *p){
  pilha b;

  define(&b);
  char_elem *it = p->topo;

  while(it->val != x){
    empilha(desempilha(p).val, &b);
    it = it->lig;
    if(it == NULL) {
      it = b.topo;
      while(it != NULL){
        empilha(desempilha(&b).val, p);
        it = it->lig;
      }
      return false;
    };
  }
  desempilha(p);

  it = b.topo;

  while(it != NULL){
    empilha(desempilha(&b).val, p);
    it = it->lig;
  }

  return true;
}

void define_int(pilha_int *p) {
  printf("Pilha Definida\n");
  p->topo = NULL;
}

void empilha_int(int x, pilha_int *p) {
  int_elem *q = malloc(sizeof(int_elem));

  q->val = x;
  q->lig = p->topo;
  p->topo = q;

  printf("Inserindo elemento %d\n", x);
}

int_elem desempilha_int(pilha_int *p){
  printf("Desempilhando\n");
  if(p->topo != NULL){
    int_elem *q = p->topo;
    p->topo = p->topo->lig;
    return *q;
  } else{
    printf("topo is NULL");
  }
}

void desempilha_impar_par(pilha_int *p, pilha_int *impar, pilha_int *par){
  int_elem *it = p->topo;
  int i = 0;

  while(it != NULL){
    if(it->val % 2 == 0){
      empilha_int(desempilha_int(p).val, par);
    } else {
      empilha_int(desempilha_int(p).val, impar);
    }
    it = it->lig;
  }
}

void imprimir_int(pilha_int *p){
  if (p->topo == NULL) {
    printf("Lista esta vazia\n");
    return;
  }
  int_elem *it = p->topo;
  int i = 0;

  while(it != NULL){
    printf("%d | %d |\n", i, it->val);
    it = it->lig;
    i++;
  }
}
