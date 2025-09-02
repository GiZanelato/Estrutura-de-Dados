#include <stdio.h>      // Biblioteca padrão de entrada e saída

#define LEN 10          // Define o tamanho máximo da lista como 10

// Definição de uma estrutura chamada 'list'
typedef struct {
    int values[LEN];    // Vetor que armazena os elementos da lista
    int n;              // Número atual de elementos na lista
} list;

// Função que verifica se a lista está cheia
int is_full(list *l){
    return l->n == LEN; // Retorna 1 (true) se estiver cheia, senão 0 (false)
    // Não precisa usar if/else pois a comparação já retorna 0 ou 1
}

// Função que verifica se a lista está vazia
int is_empty(list *l){
    return l->n == 0;   // Retorna 1 se estiver vazia, senão 0
}

// Função que encontra a posição (índice) onde um valor deve ser inserido
int get_idx(list *l, int value){
    int i = 0;
    // Percorre os elementos enquanto o valor for maior que os da lista
    while(i < l->n && value > l->values[i]){
        i++;
    }
    return i; // Retorna o índice onde o valor deve ser inserido
}

// Função que move os elementos para a direita a partir de um índice
// Isso abre espaço para inserir um novo valor mantendo a ordem
void move(list *l, int idx){
    int i;
    // Começa do último elemento e vai até o índice, movendo cada elemento para a direita
    for(i = l->n; i > idx; i--){
        l->values[i] = l->values[i - 1];
    }
}

// Função que exibe os elementos da lista na tela
void show (list *l){
    int i;
    printf("[");
    for(i = 0; i < l->n; i++){
        printf("%d ", l->values[i]);
    }
    printf("]\n");
}

// Função que insere um valor na lista mantendo-a ordenada
void insert(list *l, int value){
    if (is_full(l)){        // Se a lista estiver cheia, não insere nada
        return;
    }

    int idx = 0;
    // Se a lista não estiver vazia, calcula onde inserir
    if(!is_empty(l)){
        idx = get_idx(l, value); // Encontra a posição correta
        move(l, idx);            // Move os elementos para abrir espaço
    }

    // Insere o valor no índice encontrado
    l->values[idx] = value;
    l->n++; // Atualiza o número de elementos da lista
}

// Função principal (ponto de entrada do programa)
int main(){
    list l;           // Declara uma variável do tipo list
    l.n = 0;          // Inicializa a lista como vazia

    list *pl = &l;    // Cria um ponteiro para a lista

    // Insere alguns valores na lista
    insert(pl, 8);
    insert(pl, 42);
    insert(pl, 9);
    insert(pl, 7);

    // Mostra o conteúdo da lista após as inserções
    show(pl);

    return 0;         // Finaliza o programa
}
