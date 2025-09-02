#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da célula (nó) da lista encadeada
// É necessário repetir o nome 'Celula' antes e depois porque ela se referencia (auto-referência)
typedef struct Celula {
    int valor;                  // Valor armazenado na célula
    struct Celula *proximo;     // Ponteiro para a próxima célula
} Celula;

// Definição da estrutura da lista em si
// Aqui não é necessário o nome antes porque ela não se auto-referencia
typedef struct {
    int qtde;                   // Quantidade de elementos na lista
    Celula *primeira;           // Ponteiro para a primeira célula (início da lista)
} Lista;

// Função para inicializar uma nova lista vazia
Lista *inicializa() {
    Lista *lista = malloc(sizeof(Lista)); // Aloca memória para a estrutura da lista
    lista->qtde = 0;                      // Começa com zero elementos
    lista->primeira = NULL;              // Lista inicialmente vazia
    return lista;                         // Retorna ponteiro para a nova lista
}

// Função para imprimir todos os elementos da lista
void imprimir(Lista *lista) {
    printf("[");
    Celula *atual = lista->primeira;     // Começa pela primeira célula
    while(atual != NULL) {               // Percorre até o final da lista
        printf("%d ", atual->valor);     // Imprime o valor atual
        atual = atual->proximo;          // Vai para o próximo nó
    }
    printf("] -> qtde: %d\n", lista->qtde); // Exibe a quantidade total de elementos
}

// Função para inserir um novo valor na lista em ordem crescente
void inserir(Lista *lista, int valor) {
    Celula *nova = malloc(sizeof(Celula)); // Cria nova célula
    nova->valor = valor;                   // Atribui o valor
    nova->proximo = NULL;                  // Inicialmente não aponta para ninguém

    Celula *atual = lista->primeira;       // Começa a busca pelo início da lista
    Celula *anterior = NULL;               // Ponteiro para manter o nó anterior

    // Procura a posição correta para inserção (lista ordenada)
    while(atual != NULL && atual->valor <= valor) {
        anterior = atual;                  // Atualiza o anterior
        atual = atual->proximo;            // Avança para o próximo nó
    }

    // Caso 1: Lista vazia (inserção no primeiro elemento)
    if (atual == NULL && anterior == NULL) {
        lista->primeira = nova;
    }

    // Caso 2: Inserção no final da lista
    if (atual == NULL && anterior != NULL) {
        anterior->proximo = nova;
    }

    // Caso 3: Inserção no meio da lista
    if (atual != NULL && anterior != NULL) {
        anterior->proximo = nova;
        nova->proximo = atual;
    }

    // Caso 4: Inserção no início da lista (valor menor que todos)
    if (atual != NULL && anterior == NULL) {
        nova->proximo = atual;
        lista->primeira = nova;
    }

    lista->qtde++; // Incrementa a quantidade de elementos da lista
}

// Função principal do programa
int main() {
    printf("Lista dinamica encadeada\n");

    Lista *lista = inicializa(); // Cria e inicializa a lista

    // Insere alguns valores (em ordem não ordenada)
    inserir(lista, 2);
    inserir(lista, 10);
    inserir(lista, 7);
    inserir(lista, 1);

    imprimir(lista); // Exibe a lista ordenada após as inserções

    return 0;
}
