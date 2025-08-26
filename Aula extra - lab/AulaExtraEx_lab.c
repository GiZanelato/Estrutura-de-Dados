#include <stdio.h>

// Função que troca os valores de dois inteiros usando ponteiros
void trocar(int *num1, int *num2) {
    int aux;

    aux = *num1;     // Armazena o valor original de num1
    *num1 = *num2;   // Coloca o valor de num2 em num1
    *num2 = aux;     // Coloca o valor original de num1 em num2

    // Agora os valores apontados por num1 e num2 foram trocados
}

int main() {
    // Exemplo 1: Demonstrando o uso de & e *
    int x = 10;

    printf("Valor de x: %d\n", x);       // Imprime o valor da variável x
    printf("Endereço de x: %p\n", &x);   // Imprime o endereço de memória de x

    int *px = &x;                        // Ponteiro px armazena o endereço de x
    printf("Valor apontado por px: %d\n", *px); // Acessa o valor de x através do ponteiro

    printf("\n");

    // Exemplo 2: Usando a função 'trocar' com ponteiros
    int num1 = 10;
    int num2 = 20;

    printf("Antes da troca:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2); // Mostra os valores originais

    trocar(&num1, &num2); // Troca os valores de num1 e num2 usando ponteiros

    printf("Depois da troca:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2); // Mostra os valores trocados

    return 0;
}


// usa * para guardar o endereço/ponteiro na memoria
// usa & para pegar o endereço/ponteiro da memoria