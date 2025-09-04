#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int valor;                  // Valor armazenado na célula
    struct Celula *proxima;     // Ponteiro para a próxima célula
    struct Celula *anterior;     // Ponteiro para a próxima célula
} Celula;

typedef struct {
    int qtde;
    Celula *primeira;
}LDDE;

void inserir(LDDE *lista, int dado){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = dado;
    nova->proxima = NULL;
    nova->anterior = NULL;

    /* PONTEIROS AUXILIARES*/
    Celula *atual = lista->primeira;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor  <= dado){
        anterior = atual;
        atual = atual->proxima;

    }

    if (atual == NULL && anterior == NULL){  /*LISTA VAZIA*/
        lista->primeira = nova;

    }
    else if(atual == NULL && anterior != NULL){  /* fim da lista*/
        anterior->proxima = nova;
        nova->anterior = anterior;
    }
    else if(atual != NULL && anterior != NULL){ /*Inserir no meio */
        anterior->proxima = nova;
        nova->proxima = atual;
        nova->anterior = anterior;
        atual->anterior = nova;
    }
    else if(atual != NULL  && anterior == NULL){  /* inicio da lista*/
        lista->primeira = nova;
        nova->proxima = atual;
        atual->anterior = nova;
    }

    lista->qtde++;
}

void imprimir(LDDE *lista){
    printf("[");
    Celula *atual = lista->primeira;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proxima;
    }
    printf("] qtde: %d ", lista->qtde);
}

void imprimir_reverso(LDDE *lista){
    printf("[");
    Celula *atual = lista->primeira;
    Celula *anterior = NULL;
    while(atual != NULL){
        anterior = atual;
        atual = atual->proxima;
    }
    while(anterior != NULL){
        printf("%d ", anterior->valor);
        anterior = anterior->anterior;
    }
    printf("] qtde: %d ", lista->qtde);
}

int main(){
    printf("Lista duplamente encadeada\n");
    LDDE *lista = malloc(sizeof(LDDE));
    lista->qtde = 0;
    lista->primeira = NULL;
    inserir(lista, 10);
    inserir(lista, 20);
    inserir(lista, 15);
    inserir(lista, 5);
    imprimir(lista);
    imprimir_reverso(lista);
    return 0;
}