#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    char valor;
    struct Celula *proxima;
    struct Celula *anterior;
}Celula;

typedef struct{
    int qtde;
    Celula *topo;
}Pilha;

void imprimir(Pilha *pilha){
    printf("[ ");
    Celula *atual = pilha->topo;
    while(atual != NULL){
        printf("%c ", atual->valor);
        atual = atual->anterior;
    }
    printf("] qtde: %d\n", pilha->qtde);
}

void inserir(Pilha *pilha, char valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proxima = NULL;
    nova->anterior = NULL;

    if(pilha->qtde > 0){
        nova->anterior = pilha->topo;
        pilha->topo->proxima = nova;
    }

    pilha->topo = nova;
    pilha->qtde++;
}

char remover(Pilha *pilha){
    char valor = pilha->topo->valor;
    if (pilha->qtde > 1){
        valor = pilha->topo->valor;
        pilha->topo = pilha->topo->anterior;
        free(pilha->topo->proxima);
        pilha->topo->proxima = NULL;
    }
    else if(pilha->qtde == 1){
        valor = pilha->topo->valor;
        free(pilha->topo);
        pilha->topo = NULL;
    }
    else{
        return -1;
    }

    pilha->qtde--;
    return valor;
}

int main(){
    printf("Pilha Dinamica\n");
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->qtde = 0;
    pilha->topo = NULL;

    inserir(pilha, 'a');
    inserir(pilha, 'l');
    inserir(pilha, 'o');
    imprimir(pilha);
    remover(pilha);
    imprimir(pilha);


    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    for(int i = 0; expr[i] != '\n'; i++){
        // printf("%c ", expr[i]);
        if(expr[i] == '(' || expr[i] == ')'){
            inserir(pilha, expr[i]);
        }
        else if (expr[i] == ')'){
            remover(pilha);
        }
    }
    if(pilha->qtde != 0){
        printf("A expressao nao esta bem formada");
    }

    else{
        printf("A expressao esta bem formada");
    }

    return 0;

}
