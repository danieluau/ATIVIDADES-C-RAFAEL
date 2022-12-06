#include <stdio.h>

typedef struct {

  int num;
  double saldo;

} conta;

void iniciar(conta *a, int num, double saldo) {
  a->num = num;
  a->saldo = saldo;
}

void print(conta a) {
  printf("Saldo: %.2f \n", a.saldo);
  printf("Número da conta: %d \n", a.num);
}

void sacar(conta *a, double valor) {
  a->saldo = a->saldo - valor;
  printf("Seu saque foi realizado com sucesso! \n");
}

void depositar(conta *a, double valor) {
  a->saldo = a->saldo + valor;
  printf("Seu depósito foi realizado com sucesso!\n ");
}

int main() {
  conta a;
  iniciar(&a, 1001, 100);
  print(a);
  depositar(&a, 4);
  print(a);
  sacar(&a, 3);
  print(a);
}