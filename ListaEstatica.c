#include <stdio.h>
#include<stdlib.h>
#define max 200

//funções de py num app em c, não consegui resolver o problema das coisas aparecerem em cima do menu, de resto tudo funcionando.

int lista[200];
int t_geral= 0;
int valor;

void mostrar(int *lista, int *t);
void inserir (int *lista, int valor, int tamanho, int *t);
int* remover(int *lista, int valor, int *t);


int main(){
	int operacao;

	while(operacao!= 0){

    printf(" 1- Inserir Elemento \n 2- Excluir um elemento \n 3- Mostrar lista \n 0- Sair\n");
    printf(" Escolha o que deseja fazer: "); 
    scanf("%d",&operacao);
		switch(operacao){
			case 1:
				printf(" Informe o elemento que você quer que seja inserido na lista: ");
				scanf("%d", &valor);
				inserir(lista, valor, max, &t_geral);
				break;
			case 2:
				printf(" Digite o elemento que você quer remover: ");
				scanf("%d", &valor);
				remover(lista,valor, &t_geral);
				break;      
			
      case 3:
				mostrar(lista, &t_geral);
				break;

			case 0:
        printf("\n Tchau. \n");
				exit(0);
			default:
				printf(" Essa opção não existe. \n");
				break;
		}
	}
	return 0;
}



int* remover(int *lista, int valor, int *t){
	if(*t == 0){
		printf("\n A lista está vazia. \n");
	}else{
		int i=0;
		while(i< (*t)){
			if(lista[i] == valor){
				for(int x=i; x<(*t)-1; x++){
					lista[i] = lista[i+1];
				}
				(*t)--;
				printf("\n O elemento foi removido. \n");
				i = max*max;
			}
			i++;
		}
		if(i != (max*max)+1){
			printf("\n O elemento não se encontra na lista. \n");
		}
	}
	return lista;
}


void inserir (int *lista, int valor, int tamanho, int *t){
	
	if( *t >= tamanho){
		printf("\n A lista está cheia. \n");
	}else{
	
		int i;
		for(i = (*t)-1; (lista[i] > valor) && (i>=0); i--){
			lista[i+1] = lista[i];
		}
		lista[i+1] = valor;

		(*t)++;
		printf("\n O elemento foi inserido. \n");
	}
}


void mostrar(int *lista, int *t){
	if(*t==0){
		printf("\n A lista está vazia. \n");
	}else{
		printf("\n Lista: " );
		for(int i=0; i<*t; i++){
			printf(" \n %d  \n ",lista[i]);
		}
    printf("");
	}
}