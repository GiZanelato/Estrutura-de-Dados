#include <stdio.h>
#include <stdlib.h>

typedef struct No{
int valor;
struct No *esq;
struct No *dir;
} No;

typedef struct Arvore{
No *raiz;
int n;
}Arvore;

No *criaVertice(int valor){
No *vertice = malloc(sizeof(No));
vertice->esq = NULL;
vertice->dir = NULL;
vertice->valor = valor;
return vertice;
}

void mostrarInOrder(No *raiz){
if(raiz != NULL){
mostrarInOrder(raiz->esq);
printf("%d ", raiz->valor);
mostrarInOrder(raiz->dir);
}
}

void mostrarPreOrder(No *raiz){
if(raiz != NULL){
printf("%d ", raiz->valor);
mostrarPreOrder(raiz->esq);
mostrarPreOrder(raiz->dir);
}
}

void mostrarPosOrder(No *raiz){
if(raiz != NULL){
mostrarPosOrder(raiz->esq);
mostrarPosOrder(raiz->dir);
printf("%d ", raiz->valor);
}
}

No *inserir(No *raiz, int valor){
if(raiz == NULL){
return criaVertice(valor);
}
if(valor < raiz->valor){
raiz->esq = inserir(raiz->esq, valor);
}
if(valor > raiz->valor){
raiz->dir = inserir(raiz->dir, valor);
}
return raiz;
}

void add(Arvore *t, int valor){
    t->raiz = inserir(t->raiz, valor);
    t->n++;
}

int main(){
printf("Arvore binaria\n");
Arvore *t = malloc(sizeof(Arvore));
t->raiz = NULL;
t->n = 0;
add(t, 5);
add(t, 3);
add(t, 7);
add(t, 1);
add(t, 8);
add(t, 4);
add(t, 6);
add(t, 2);
add(t, 9);
// t->raiz = inserir(t->raiz, 5);
// t->raiz = inserir(t->raiz, 3);
// t->raiz = inserir(t->raiz, 7);
// t->raiz = inserir(t->raiz, 1);
// t->raiz = inserir(t->raiz, 8);
// t->raiz = inserir(t->raiz, 4);
// t->raiz = inserir(t->raiz, 6);
// t->raiz = inserir(t->raiz, 2);
// t->raiz = inserir(t->raiz, 9);

mostrarInOrder(t->raiz);
printf("\n");
mostrarPreOrder(t->raiz);
printf("\n");
mostrarPosOrder(t->raiz);
printf("\n");
return 0;
}