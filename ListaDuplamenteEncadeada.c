#include <stdio.h>
#include <stdlib.h>

//funcionando. Duplamente Encadeada
typedef struct no {
  int valor;
  struct no *p;
  struct no *a;
} No;

void inserir(No **lista, int num) {
  No *aux, *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
    novo->p = NULL;

    if (*lista == NULL) {
      *lista = novo;
      novo->a = NULL;
    } else {
      aux = *lista;
      while (aux->p)
        aux = aux->p;
      aux->p = novo;
      novo->a = aux;
    }
  } else
    printf("Erro.\n");
}

No *remover(No **lista, int num) {
  No *aux, *remover = NULL;

  if (*lista) {
    if ((*lista)->valor == num) {
      remover = *lista;
      *lista = remover->p;
      if (*lista)
        (*lista)->a = NULL;
    } else {
      aux = *lista;
      while (aux->p && aux->p->valor != num)
        aux = aux->p;
      if (aux->p) {
        remover = aux->p;
        aux->p = remover->p;
        if (aux->p)
          aux->p->a = aux;
      }
    }
  }
  return remover;
}

void imprimir(No *no) {
  printf("\n\t Elementos da lista: ");
  while (no) {
    printf("%d ", no->valor);
    no = no->p;
  }
  printf("\n\n");
}

int main(void) {

  int op, valor;
  No *removido, *lista = NULL;

  do {
    printf("\n\t 0- Sair\n\t 1- Inserir Elemento\n\t 2- Remover Elemento\n\t 3- Mostrar Lista\n");
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf(" Digite um elemento para ser inserido: ");
      scanf("%d", &valor);
      inserir(&lista, valor); 
      printf(" Elemento inserido na lista. ");
      break;

    case 2:
      printf(" Digite um elemento da lista para ser removido: ");
      scanf("%d", &valor);
      removido = remover(&lista, valor);
      if (removido) {
        printf(" Elemento removido: %d\n", removido->valor);
        free(removido);
      } else
        printf(" Valor não está na lista. \n");
      break;
    case 3:
      imprimir(lista);
      break;

    default:
      if (op != 0)
        printf(" Essa opção não existe. \n");
      break;
    }

  } while (op != 0);

  return 0;
}
