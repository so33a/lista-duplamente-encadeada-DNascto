#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

link novoNo (int item, link prev, link next) {
  link aux = malloc(sizeof(struct node));
  if (aux == NULL) {
    printf ("Erro ao alocar um novo no\n");
    exit(-1);
  }
  aux->item = item;
  aux->prev = prev;
  aux->next = next;
  return aux;
}


ListaDupla inicializa() {
  ListaDupla aux;
  aux = malloc(sizeof *aux);
  aux->head = NULL;
  aux->z = novoNo(0, NULL, NULL);
  return aux;
}

void insereDepois (ListaDupla l, link x, link t) {
  if (x == NULL) {
    l->head = t;
    t->next = l->z;
    t->prev = l->z;
    l->z->prev = t;
    l->z->next = t; 
  } else {
    t->next = x->next;
    t->prev = x;
    x->next = t;
    t->next->prev = t;
  }
}

link removeNo (link x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  return x;
}
void imprimeReverso(ListaDupla l) {
  link t = l->z->prev;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->prev;
  }
  printf("\n");
}


void imprime(ListaDupla l) {
  link t = l->head;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->next;
  }
  printf("\n");
}

link buscar(ListaDupla l, int item) {
  link t = l->head;
  while ( t != l->z ) {
    if(t->item == item)
      return t;
    t = t->next;
  }
  return NULL;
}
/* 
void insereAntes (ListaDupla l, link x, link t);
*/

void destroiLista(ListaDupla l) {
  link t = l->head;
  while (t != l->z) {
    l->head = t->next;
    l->z->next = t->next;
    l->head->prev = l->z;
    free(t); 
    t = l->head;
  } 
  free(t);
  free(l);
}


link encontraMenor(ListaDupla lista){
  link aux = lista->head, t = lista->head;
  while (t != lista->z ) {
    if(t->item < aux){
      aux->item = t->item;
    }
    t = t->next;
  }
  return aux;
}
  
void ordenaLista(ListaDupla lista){
  link aux = lista->head;
  link aux2 = aux->next;
  int troca = 0;
  do{
    troca = 0;
    if(aux->item > aux2->item){
      link muda;
      muda->item = aux->item;
      muda->next = aux->next;
      muda->prev = aux->prev;
      aux->item = aux2->item;
      aux->next = aux2->next;
      aux->prev = aux2->prev;
      aux2->item = muda->item;
      aux2->next = muda->next;
      aux2->prev = muda->prev;
      troca = 1;
    }
    aux2 = aux->next;
    aux = aux->next;
  }while(troca != 0);
  imprimeLista(&lista);
}


