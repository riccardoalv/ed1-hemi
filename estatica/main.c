#include <stdbool.h>
#include <stdio.h>
#include "stackStatic.h"

int main() {
  pilha a;

  pilha *b = &a;

  define(b);

  vazia(b);

  cheia(b);

  imprimir(b);

  empilha('a', b);
  imprimir(b);

  empilha('b', b);
  imprimir(b);

  empilha('c', b);
  imprimir(b);

  desempilha(b);
  imprimir(b);

  printf("Elemento do topo: %c\n", top(b));

  printf("Imprimir\n");
  imprimir(b);

  printf("Imprimir Inversa\n");
  imprimir_inv(b);

  printf("Limpando Pilha\n");
  limpar(b);
  vazia(b);

  char arara[] = "arara";
  for(int i = 0; i < 5; i++){
    empilha(arara[i], b);
  }
  imprimir(b);

  bool isAraraPalindrome = palindromo(b);
  printf("palindromo: %s\n", isAraraPalindrome ? "true" : "false");

  limpar(b);

  char araras[] = "barara";
  for(int i = 0; i < 6; i++){
    empilha(araras[i], b);
  }
  imprimir(b);

  bool isArarasPalindrome = palindromo(b);
  printf("palindromo: %s\n", isArarasPalindrome ? "true" : "false");

  if(elimina('b', b)){
    printf("Elemento removido com sucesso!\n");
  } else {
    printf("Elemento nao existe!\n");
  }

  imprimir(b);

  if(elimina('b', b)){
    printf("Elemento removido com sucesso!\n");
  } else {
    printf("Elemento nao existe!\n");
  }

  imprimir(b);

  limpar(b);

  pilha_int x;

  define_int(&x);

  for(int i = 1; i < 10; i++){
    empilha_int(i, &x);
  }

  imprimir_int(&x);

  pilha_int impar;
  pilha_int par;

  define_int(&impar);
  define_int(&par);

  desempilha_impar_par(&x, &impar, &par);

  printf("Pilha Impar\n");
  imprimir_int(&impar);
  printf("Pilha Par\n");
  imprimir_int(&par);

  printf("Pilha Normal\n");
  imprimir_int(&x);
  vazia(&x);

  return 0;
}
