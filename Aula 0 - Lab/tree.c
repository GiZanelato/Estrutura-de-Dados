#include <stdio.h>
#include <stdlib.h>

// Definição de uma célula (nó) da árvore binária
typedef struct Celula {
    int valor;                 // Valor armazenado no nó
    struct Celula *esq;        // Ponteiro para o filho à esquerda
    struct Celula *dir;        // Ponteiro para o filho à direita
} Celula;

// Definição da estrutura da árvore
typedef struct Tree {
    Celula *raiz;              // Ponteiro para a raiz da árvore
    int qtde;                  // Quantidade de elementos inseridos na árvore
} Tree;

// Função para inserir um novo valor na árvore
void inserir(Tree *arvore, int valor){
    // Aloca memória para um novo nó
    Celula *nova = malloc(sizeof(Celula));
    nova->dir = NULL;          // Inicializa o ponteiro da direita como NULL
    nova->esq = NULL;          // Inicializa o ponteiro da esquerda como NULL
    nova->valor = valor;       // Atribui o valor recebido ao novo nó

    // Se a árvore está vazia (sem raiz), define o novo nó como raiz
    if(arvore->raiz == NULL){
        arvore->raiz = nova;
    } else {
        // Senão, percorre a árvore para encontrar a posição correta do novo valor
        Celula *atual = arvore->raiz;     // Começa pela raiz
        Celula *anterior = NULL;          // Ponteiro para manter o nó anterior na busca

        // Percorre enquanto não encontrar uma posição livre
        while(atual != NULL){
            anterior = atual;             // Guarda o nó atual
            if(atual->valor > valor){     // Se o valor atual for maior, vai para a esquerda
                atual = atual->esq;
            } else {                      // Caso contrário, vai para a direita
                atual = atual->dir;
            }
        }

        // Insere o novo nó na posição correta (esquerda ou direita)
        if(anterior->valor > valor){
            anterior->esq = nova;         // Insere à esquerda
        } else {
            anterior->dir = nova;         // Insere à direita
        }
    }

    // Incrementa a quantidade de elementos na árvore
    arvore->qtde++;
}

int main(){
    // Aloca memória para a árvore
    Tree *arvore = malloc(sizeof(Tree));
    arvore->qtde = 0;           // Inicializa a quantidade de elementos
    arvore->raiz = NULL;        // Inicializa a raiz como NULL

    // Vetor com os valores que serão inseridos na árvore
    int dados[] = {13, 5, 18, 4, 8, 15, 21, 2, 16};

    // Insere cada valor do vetor na árvore
    for(int i = 0; i < 9; i++){
        inserir(arvore, dados[i]);
    }

    return 0;  // Finaliza o programa
}
