#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

typedef struct{
    char data [SIZE];
    int head;
    int tail;
    int qtde;
}Fila;

void inicializa(Fila *fila){
    fila->head = 0;
    fila->tail = 0;
    fila->qtde = 0;

}

int isEmpty(Fila *fila){

    return fila->head == fila->tail;
}

int isFull(Fila *fila){
    return (fila->tail + 1) % SIZE == fila->head; 
}

void enfileirar(Fila *fila, char valor){
    if (isFull(fila)) return;
    fila->data[fila->tail] = valor;
    fila->tail = (fila->tail + 1) % SIZE;
    fila->qtde++;
}

char desenfileirar(Fila *fila){
    if (isEmpty(fila)) return -1;
    char character = fila->data[fila->head];
    fila->head = (fila->head + 1) % SIZE;
    fila->qtde--;
    return character;
}

void imprimir(Fila *fila){
    printf("[ ");
    for(int i = fila->head; i != fila->tail; i = (i + 1) % SIZE)
        printf("%c ",fila->data[i]);
    printf("]\n");
}

int main(){
    printf("fila estatica\n");
    Fila fila;
    inicializa(&fila);
    imprimir(&fila);
    enfileirar(&fila, 'a');
    imprimir(&fila);
    desenfileirar(&fila);
    imprimir(&fila);
    return 0;
}