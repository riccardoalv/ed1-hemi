#include <stdbool.h>
#include <stdio.h>
#include "stackStatic.h"

void define(pilha *p) {
  printf("Pilha Definida\n");
  p->topo = -1;
}

void define_int(pilha_int *p) {
  printf("Pilha Definida\n");
  p->topo = -1;
}

bool empilha(char x, pilha *p) {
  if (p->topo == MAXP){
    printf("Pilha esta cheia!\n");
    return false;
  }

  printf("Inserindo elemento %c\n", x);
  p->topo++;
  p->A[p->topo] = x;
  return true;
}

int desempilha_int(pilha_int *p){
  int x = p->A[p->topo];
  p->topo--;

  printf("Removendo elemento do topo: %d\n", x);

  return x;
}

char desempilha(pilha *p){
  int x = p->A[p->topo];
  p->topo--;

  printf("Removendo elemento do topo: %c\n", x);

  return x;
}

bool empilha_int(int x, pilha_int *p) {
  if (p->topo == MAXP){
    printf("Pilha esta cheia!\n");
    return false;
  }

  printf("Inserindo elemento: %d\n", x);
  p->topo++;
  p->A[p->topo] = x;
  return true;
}

bool elimina(char x, pilha *p){
  pilha b;

  define(&b);

  for(int i = p->topo; i >= 0; i--){
    if(p->A[p->topo] != x){
      empilha(desempilha(p), &b);
      imprimir(p);
    } else {
      desempilha(p);
      for(int i = b.topo; i >= 0; i--){
        empilha(desempilha(&b), p);
        imprimir(p);
      }
      return true;
    }
  }

  for(int i = b.topo; i >= 0; i--){
    empilha(desempilha(&b), p);
    imprimir(p);
  }

  return false;
}

void desempilha_impar_par(pilha_int *p, pilha_int *impar, pilha_int *par){
  for(int i = p->topo; i >= 0; i--){
    if(p->A[p->topo] % 2 == 0){
      empilha_int(desempilha_int(p), impar);
    } else {
      empilha_int(desempilha_int(p), par);
    }
  }
}

bool vazia(pilha *p){
  if(p->topo == -1){
    printf("Pilha esta vazia!\n");
    return true;
  } else {
    printf("Pilha nao esta vazia!\n");
    return false;
  }
}

bool cheia(pilha *p){
  if(p->topo == MAXP){
    printf("Pilha esta cheia!\n");
    return true;
  } else {
    printf("Pilha nao esta cheia!\n");
    return false;
  }
}

char top(pilha *p){
  return p->A[p->topo];
}


bool limpar(pilha *p){
  if(p->topo == -1) return false;

  printf("Limpando Pilha\n");
  p->topo = -1;

  return true;
}

bool palindromo(pilha *p){
  char s[p->topo];
  for(int i = 0; i <= p->topo; i++){
    s[i] = p->A[i];
  }
  bool ans;
  for(int i = 0, j = p->topo; i <= j; i++, j--){
    if(s[i] == p->A[j]){
      ans = true;
    } else {
      return false;
    }
  }
  return ans;
}



void imprimir(pilha *p){
  int start = p->topo;
  for(; start >= 0; start--){
    printf("%d | %c | \n", start, p->A[start]);
  }
}

void imprimir_int(pilha_int *p){
  int start = p->topo;
  for(; start >= 0; start--){
    printf("%d | %d | \n", start, p->A[start]);
  }
}

void imprimir_inv(pilha *p){
  int start = 0;
  for(; start <= p->topo; start++){
    printf("%d | %c | \n", start, p->A[start]);
  }
}
