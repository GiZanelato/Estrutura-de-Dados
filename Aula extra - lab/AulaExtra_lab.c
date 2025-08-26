#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos do vetor
void trocar(int *a, int *b) {
    int aux;
    aux = *a;       // Salva o valor de *a em aux
    *a = *b;        // Coloca o valor de *b em *a
    *b = aux;       // Coloca o valor original de *a (guardado em aux) em *b
}

// Função que implementa o algoritmo de ordenação Bubble Sort
void bubbleSort(int V[], int n) {
    // Loop externo percorre todas as posições do vetor
    for(int i = 0; i < n; i++){
        // Loop interno compara elementos da direita para a esquerda
        for(int j = n - 1; j >= i + 1; j--){
            // Se o elemento da direita for menor que o da esquerda, troca
            if(V[j] < V[j - 1]){
                trocar(&V[j], &V[j - 1]);
            }
        }
    }
}

// Função auxiliar para imprimir todos os elementos do vetor
void imprimirArray(int arr[], int tamanho) {
    for(int i = 0; i < tamanho; i++){
        printf("%d ", arr[i]); // Imprime cada elemento seguido de um espaço
    }
    printf("\n"); // Nova linha após imprimir o vetor inteiro
}

// Função principal onde o programa começa
int main() {
    // ---------- Primeiro teste ----------
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // Vetor desordenado (decrescente)
    int n = sizeof(arr) / sizeof(arr[0]);   // Calcula o tamanho do vetor

    printf("Array original: ");
    imprimirArray(arr, n); // Imprime o vetor antes da ordenação

    bubbleSort(arr, n);    // Ordena o vetor com Bubble Sort

    printf("Array ordenado: ");
    imprimirArray(arr, n); // Imprime o vetor após a ordenação

    // ---------- Segundo teste ----------
    int arr2[] = {64, 34, 25, 12, 22, 11, 90}; // Outro vetor com valores aleatórios
    int n2 = sizeof(arr2) / sizeof(arr2[0]);   // Calcula o tamanho do segundo vetor

    printf("\nSegundo teste:\n");
    printf("Array original: ");
    imprimirArray(arr2, n2); // Imprime o segundo vetor antes da ordenação

    bubbleSort(arr2, n2);    // Ordena o segundo vetor

    printf("Array ordenado: ");
    imprimirArray(arr2, n2); // Imprime o segundo vetor após a ordenação

    return 0; // Finaliza o programa
}
