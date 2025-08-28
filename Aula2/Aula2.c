#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{          //coloca o nome Celula no começo e no fim porque esta referenciando ela mesma 
    int valor;
    struct Celula *proximo;
}Celula;

typedef struct{
    int qtde;
    Celula *primeira;
}Lista;                            // aqui coloca só no final pq não referencia ela mesma 

Lista *inicializa(){
    Lista *lista = malloc(sizeof(Lista));
    lista->qtde = 0;
    lista->primeira = NULL;
    return lista;
}

void imprimir(Lista *lista){
    printf("[");
    Celula *atual = lista -> primeira;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("] -> qtde: %d\n", lista->qtde);

}

void inserir(Lista *lista, int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;

    Celula *atual = lista->primeira;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor <= valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL && anterior == NULL){ //lista vazia
        lista->primeira = nova;
    }

    if(atual == NULL && anterior != NULL){ //final da lista
        anterior->proximo = nova;    
    }

    if(atual != NULL && anterior != NULL){ //no meio da lista
        anterior->proximo = nova;
        nova->proximo = atual;
    }

    if(atual != NULL && anterior == NULL){  //primeiro da lista
        nova->proximo = atual;
        lista->primeira = nova;
    }



    lista->qtde++;
}


int main(){
    printf("Lista dinamica encadeada\n");
    
    Lista *lista = inicializa();
    inserir(lista, 2);
    inserir(lista, 10);
    inserir(lista, 7);
    inserir(lista, 1);
    imprimir(lista);
}
