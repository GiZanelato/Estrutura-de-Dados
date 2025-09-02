#include <stdio.h>

// Define uma constante para o tamanho máximo da lista
#define TAMANHO 10

// Define uma estrutura chamada Lista, que possui:
// - um array de inteiros com TAMANHO posições
// - um inteiro n que representa o número atual de elementos na lista
typedef struct {
    int valores[TAMANHO];
    int n;
} Lista;

/**
 * Verifica se a lista está cheia (n == TAMANHO).
 * Retorna 1 se cheia, 0 caso contrário.
 */
int esta_cheia(Lista *lista) {
    return lista->n == TAMANHO;
}

/**
 * Verifica se a lista está vazia (n == 0).
 * Retorna 1 se vazia, 0 caso contrário.
 */
int esta_vazia(Lista *lista) {
    return lista->n == 0;
}

/**
 * Encontra a posição correta (ordenada) onde um novo valor deve ser inserido.
 * Percorre o array até achar onde o novo valor é menor ou igual ao valor atual.
 * Retorna o índice onde o valor deve ser inserido.
 */
int encontrar_posicao(Lista *lista, int valor) {
    int idx = 0;
    while (idx < lista->n && valor > lista->valores[idx]) {
        idx++;
    }
    return idx;
}

/**
 * Move os elementos da lista uma posição para a direita a partir do índice dado.
 * Isso abre espaço para inserção de um novo valor.
 */
void deslocar_direita(Lista *lista, int indice) {
    for (int i = lista->n; i > indice; i--) {
        lista->valores[i] = lista->valores[i - 1];
    }
}

/**
 * Move os elementos da lista uma posição para a esquerda a partir do índice dado.
 * Isso "remove" um valor do meio do vetor.
 */
void deslocar_esquerda(Lista *lista, int indice) {
    for (int i = indice; i < lista->n - 1; i++) {
        lista->valores[i] = lista->valores[i + 1];
    }
}

/**
 * Insere um valor na lista, mantendo a ordem crescente.
 * Retorna 1 se a inserção for bem-sucedida, ou 0 se a lista estiver cheia.
 */
int inserir(Lista *lista, int valor) {
    if (esta_cheia(lista)) {
        return 0; // Falha ao inserir (lista cheia)
    }

    // Encontra onde o valor deve ser inserido
    int idx = encontrar_posicao(lista, valor);

    // Move elementos para a direita para abrir espaço
    deslocar_direita(lista, idx);

    // Insere o valor na posição correta
    lista->valores[idx] = valor;

    // Incrementa a contagem de elementos
    lista->n++;

    return 1;
}

/**
 * Remove um valor da lista.
 * Retorna o valor removido ou -1 se não foi possível (lista vazia ou valor não encontrado).
 */
int remover(Lista *lista, int valor) {
    if (esta_vazia(lista)) {
        return -1; // Falha (lista vazia)
    }

    // Encontra o índice onde o valor estaria (mesmo se não existir)
    int idx = encontrar_posicao(lista, valor);

    // Se o índice for além do final da lista, valor não está presente
    if (idx >= lista->n) {
        return -1;
    }

    // Remove o valor deslocando os elementos à esquerda
    deslocar_esquerda(lista, idx);

    // Decrementa o número de elementos
    lista->n--;

    return valor;
}

/**
 * Imprime todos os elementos atuais da lista.
 */
void exibir_lista(const Lista *lista) {
    for (int i = 0; i < lista->n; i++) {
        printf("%d ", lista->valores[i]);
    }
    printf("\n");
}

/**
 * Função principal (main): testa a funcionalidade da lista ordenada.
 */
int main(void) {
    Lista lista = { .n = 0 }; // Inicializa a lista com 0 elementos
    Lista *pl = &lista;       // Cria um ponteiro para a lista

    // Vetor com 10 valores para inserir na lista
    int valores[] = {21, 14, 13, 10, 87, 35, 27, 56, 85, 29};

    // Insere os valores na lista um por um e exibe o estado da lista após cada inserção
    for (int i = 0; i < TAMANHO; i++) {
        inserir(pl, valores[i]);
        exibir_lista(pl);
    }

    // Mostra a posição onde cada valor está (após ordenação)
    for (int i = 0; i < TAMANHO; i++) {
        printf("O valor %d está na posição %d\n", valores[i], encontrar_posicao(pl, valores[i]));
    }

    // Remove os valores da lista um por um e exibe o estado da lista após cada remoção
    for (int i = 0; i < TAMANHO; i++) {
        remover(pl, valores[i]);
        exibir_lista(pl);
    }

    return 0;
}

//gcc aula2_lab.c 
// ./a.out
//ll mostar pasta
//cd abrir pasta