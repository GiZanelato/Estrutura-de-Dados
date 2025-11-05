#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice {
    int valor;
    struct Vertice* esq;
    struct Vertice* dir;
    struct Vertice* pai;
} Vertice;

typedef struct Arvore {
    Vertice* raiz;
    int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

Vertice *cria_vertice(int valor) {
    Vertice* novo = malloc(sizeof(Vertice));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->valor = valor;
    return novo;
}

Arvore *cria_arvore() {
    Arvore* arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    arvore->qtde = 0;
    return arvore;
}

Vertice* inserir_recursivo(Vertice* raiz, Vertice* pai, int valor) {
    if (raiz == NULL) {
        Vertice* novo = cria_vertice(valor);
        novo->pai = pai;
        return novo;
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir_recursivo(raiz->esq, raiz, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir_recursivo(raiz->dir, raiz, valor);
    }
    return raiz;
}

void inserir(Arvore* arvore, int valor) {
    arvore->raiz = inserir_recursivo(arvore->raiz, NULL, valor);
    arvore->qtde++;
}

Vertice *buscar_valor(Arvore* arvore, int valor) {
    Vertice* atual = arvore->raiz;
    while (atual != NULL) {
        if (valor < atual->valor) {
            atual = atual->esq;
        } else if (valor > atual->valor) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}

void transplantar(Arvore* arvore, Vertice* u, Vertice* v) {
    if (u->pai == NULL) {
        arvore->raiz = v;
    } else if (u == u->pai->esq) {
        u->pai->esq = v;
    } else {
        u->pai->dir = v;
    }
    if (v != NULL) {
        v->pai = u->pai;
    }
}

Vertice* maximo(Vertice* raiz) {
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}

void remover_vertice(Arvore* arvore, Vertice* vertice) {
    if (vertice->esq == NULL) {
        transplantar(arvore, vertice, vertice->dir);
    } else if (vertice->dir == NULL) {
        transplantar(arvore, vertice, vertice->esq);
    } else {
        Vertice* antecessor = maximo(vertice->esq);
        if (antecessor->pai != vertice) {
            transplantar(arvore, antecessor, antecessor->esq);
            antecessor->esq = vertice->esq;
            antecessor->esq->pai = antecessor;
        }
        transplantar(arvore, vertice, antecessor);
        antecessor->dir = vertice->dir;
        antecessor->dir->pai = antecessor;
    }
    free(vertice);
    arvore->qtde--;
}

int main(void) {
    int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
    Arvore *arvore = cria_arvore();

    for (int i = 0; i < 10; i++) {
        inserir(arvore, dados[i]);
        printf("Inseriu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        Vertice *vertice = buscar_valor(arvore, dados[i]);
        if (vertice != NULL) {
            remover_vertice(arvore, vertice);
        }
        printf("Removeu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    free(arvore);
    return 0;
}
