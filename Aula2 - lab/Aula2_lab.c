#include <stdio.h>      // Biblioteca padrão de entrada/saída
#include <stdlib.h>     // Biblioteca para alocação dinâmica (malloc, free)

// Definição da estrutura de uma célula (nó) da lista encadeada
typedef struct Celula {
    int valor;                  // Valor armazenado na célula
    struct Celula *proximo;     // Ponteiro para a próxima célula
} Celula;

// Definição da estrutura da lista encadeada (LDE)
typedef struct {
    Celula *primeiro;           // Ponteiro para a primeira célula da lista
    int qtd;                    // Quantidade de elementos na lista
} LDE;

// Função para criar uma nova célula com o valor fornecido
Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula)); // Aloca memória para a célula
    nova->proximo = NULL;                  // Inicializa o ponteiro como NULL
    nova->valor = valor;                   // Atribui o valor
    return nova;                           // Retorna a nova célula criada
}

// Função para criar e inicializar uma nova lista
LDE *criar_lista(){
    LDE *lista = malloc(sizeof(LDE));  // Aloca memória para a lista
    lista->primeiro = NULL;            // Inicializa como vazia
    lista->qtd = 0;                    // Começa com 0 elementos
    return lista;                      // Retorna a nova lista criada
}

// Função para inserir um valor na lista de forma ordenada (ordem crescente)
void inserir(LDE *lista, int valor){
    Celula *nova = criar_celula(valor);    // Cria nova célula com o valor
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    // Percorre a lista até encontrar a posição correta para inserção
    while(atual != NULL && atual->valor < nova->valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior == NULL){
        // Inserção no início da lista
        lista->primeiro = nova;
    } else {
        // Inserção no meio ou fim da lista
        anterior->proximo = nova;
    }

    nova->proximo = atual;    // Aponta a nova célula para o próximo nó
    lista->qtd++;             // Atualiza a quantidade de elementos
}

// Função para remover um valor da lista 
void remover(LDE *lista, int valor) {   
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }

    //lista vazia
   
 if(atual == NULL){
        return;
    } 
    //meio da lista
    if (atual->proximo != NULL && anterior != NULL) {
        anterior->proximo = atual->proximo;
        free(atual);
    }

    //começo da lista
    if (atual != NULL && anterior == NULL) {
        lista->primeiro = atual->proximo;
        free(atual);
    }

    //fim da lista
    if (atual != NULL && atual->proximo == NULL) {
        anterior->proximo = NULL;
        free(atual);
    }
    

    
    lista->qtd--;             // Atualiza a quantidade de elementos


}

// Função para mostrar todos os valores da lista
void mostrar(LDE *lista){
    Celula *atual = lista->primeiro;
    while(atual != NULL){
        printf("%d ", atual->valor);       // Imprime o valor da célula atual
        atual = atual->proximo;            // Avança para a próxima célula
    }
    printf("\n");
}

// Função principal do programa
int main(){
    LDE *lista = criar_lista();            // Cria e inicializa a lista
    int num;

    // Lê 10 números do usuário e insere na lista ordenadamente
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);                 // Lê um número
        inserir(lista, num);              // Insere na lista em ordem
        mostrar(lista);                   // Mostra a lista após cada inserção
    }

    // Lê mais 10 números e tenta removê-los da lista (mas função ainda não implementada)
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);                 // Lê um número a remover
        remover(lista, num);              // Tenta remover (sem efeito ainda)
        mostrar(lista);                   // Mostra a lista após tentativa
    }

    return 0;
}
