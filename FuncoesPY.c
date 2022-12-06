#define MAX 100
#include <stdio.h>
#include <stdlib.h>

struct usuario {
  int codigo;
  char nome[30];
  float n1, n2, n3;
};

typedef struct lista Lista;

struct lista {
  int quantidade;
  struct usuario dados[MAX];
};

Lista *list;

int full(Lista *li) {
  if (list == NULL)
    return -1;
  return (list->quantidade == MAX);
}

int empty(Lista *list) {
  if (list == NULL)
    return -1;
  return (list->quantidade == 0);
}

int insere_ordenado(Lista *list, struct usuario us) {
  if (list == NULL)
    return 0;
  if (full(list))
    return 0;
  int k, j = 0;
  while (j < list->quantidade && list->dados[k].codigo < us.codigo)
    j++;
  for (k = list->quantidade - 1; k >= j; k--)
    list->dados[k + 1] = list->dados[k];
  list->dados[j] = us;
  list->quantidade++;
  return 1;
}

int remove_indice(Lista *list, int cod) {
  if (list == NULL)
    return 0;
  if (list->quantidade == 0)
    return 0;
  int k, j = 0;

  while (j < list->quantidade && list->dados[j].codigo != cod)
    j++;
  if (j == list->quantidade)
    return 0;
  for (k = j; k < list->quantidade - 1; k++)
    list->dados[k] = list->dados[k + 1];
  list->quantidade--;
}

void print(Lista *l) { printf("Elementos: %d", l->vet[l->quantidade]); }

int tamanho(Lista *l) {
  if (l == NULL)
    return -1;
  else
    return l->quantidade;
}

Lista *gerar_lista();

Lista *gerar_lista() {
  Lista *list;
  list = (Lista *)malloc(sizeof(struct lista));
  if (list != NULL)
    list->quantidade = 0;
  return list;
}

int inserir_inicio(Lista *list, struct usuario us) {
  if (list == NULL)
    return 0;
  if (full(list))
    return 0;
  int k;
  for (k = list->quantidade - 1; k >= 0; k--)
    list->dados[k + 1] = list->dados[k];
  list->dados[0] = us;
  list->quantidade++;
  return 1;
}

int inserir_final(Lista *li, struct usuario us) {
  if (list == NULL)
    return 0;
  if (full(list))
    return 0;
  list->dados[list->quantidade] = us;
  list->quantidade++;
  return 1;
}

int remove_final(Lista *li) {
  if (list == NULL)
    return 0;
  if (list->quantidade == 0)
    return 0;
  list->quantidade--;
  return 1;
}
