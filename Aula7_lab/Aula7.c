#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
  struct Cell *anterior;
  struct Cell *proximo;
  char valor;
} Cell;

typedef struct {
  Cell *top;
  int qtde;
} Stack;

Cell *start_cell(char valor) {
  Cell *nova = malloc(sizeof(Cell));
  nova->anterior = NULL;
  nova->proximo = NULL;
  nova->valor = valor;
  return nova;
}

Stack *start_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->qtde = 0;
  stack->top = NULL;
  return stack;
}

void push(Stack *stack, char valor) {
  Cell *nova = start_cell(valor);
  if (stack->qtde != 0) {
    nova->proximo = stack->top;
    stack->top->anterior = nova;
  }
  stack->top = nova;
  stack->qtde++;
}

char pop(Stack *stack) {
  if (stack->qtde > 0) {
    char valor = stack->top->valor;
    Cell *top = stack->top;
    stack->top = stack->top->proximo;
    if (stack->top != NULL)
      stack->top->anterior = NULL;
    stack->qtde--;
    free(top);
    return valor;
  } else {
    return 'x';
  }
}

int verifica_equacao(Stack *stack, char expr[]){
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;

    for (int i = 0; expr[i] != '\n'; i++) {
        if (expr[i] == '('){
            push(stack,expr[i]);
            cont1 = cont1 + 1;
        }

        if (expr[i] == '[' ){
          if(cont1 >= 1){
            return 1;
          }
          else{
            push(stack,expr[i]);
            cont2 = cont2 + 1;
          }
        }

        if (expr[i] == '{'){
          if(cont2 >= 1){
            return 1;
          }
          else{
            push(stack,expr[i]);
            cont3 = cont3 + 1;
          }
        }
  
        if (expr[i] == ')'){
          if(pop(stack) != '('){
            return 1;
          }
          cont1 = cont1 - 1;
        }

        if (expr[i] == ']'){
          if(pop(stack) != '['){
            return 1;
          }
          cont2 = cont2 - 1;
        }

        if (expr[i] == '}'){
          if(pop(stack) != '{'){
            return 1;
          }
          cont3 = cont3 - 1;
        }
    }

      if(stack->qtde == 0){
        return 0;
      }
      return 1;

}

int main(void) {
    Stack *stack = start_stack();
  
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    if (verifica_equacao(stack, expr))
      printf("incorreto");
      
    else
      printf("correto");

    return 0;
}
