#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct no{int valor; struct no *po;};
struct listaT{ struct no *ini; };

//funcionando muito bem. Circular

void mostrar_lista(struct listaT *inicio);
void inserir_na_lista(struct listaT *inicio,int d);
void excluir_na_lista(struct listaT *inicio,int d);


int main(void) { 
struct listaT *pon_lista;
 pon_lista = (struct listaT*)malloc(sizeof(struct listaT)); 
 pon_lista->ini = NULL; 
 int op = -2; 
 int d, de;

printf(" 1- Inserir Elemento \n 2- Mostrar lista \n 3- Excluir um elemento\n 0- Sair\n");
while (op!=0){ 

printf(" Escolha o que deseja fazer: "); 
scanf("%d",&op); 

switch(op){

 case 1: 
	 	printf(" Informe o elemento que você quer que seja inserido na lista: "); 
	 	scanf(" %d",&d); 
	 	inserir_na_lista(pon_lista, d); 
 	break;

 case 2: 
 		mostrar_lista(pon_lista); 
 	break;
 case 3: 
		printf(" Informe o elemento que você quer que seja excluido na lista: "); 
		scanf(" %d",&d); 
		excluir_na_lista(pon_lista,d); 
	 break;
 case 0: 
   printf(" Tchau.");
 break;
 
 default:
 	printf("\n Opção inválida \n");
 }  }
  return 0;}


void inserir_na_lista(struct listaT *inicio,int d){ 
struct no *novo,*p; 
novo = (struct no*)malloc(sizeof(struct no)); 
novo->valor = d; 
novo->po = NULL;

 if(inicio->ini == NULL){ 
	 inicio->ini = novo; 
	 novo->po= inicio->ini; 
 }else{ 
	 p = inicio->ini; 
	 while(p->po != inicio->ini){ 
	 	p=p->po; 	
	 } 
	 p->po = novo; 
	 novo->po = inicio->ini; 
 }}

void mostrar_lista(struct listaT *inicio){ 
struct no *p; 
p=inicio->ini; 
printf(" Lista: \n"); 
if(p == NULL){ 
	printf(" A lista está vazia\n"); 
}else if(p->po == p){ 
	printf(" %d\n",p->valor); 
}else{ 
	printf(" %d\n",p->valor); 
	p = p->po; 
	while (p != inicio->ini ){ 
	printf(" %d\n",p->valor); 
	p = p->po;
	 } 
	 }}

void excluir_na_lista(struct listaT *inicio,int d){
 struct no *p,*ini,*excluir; 
 p=inicio->ini; 
 ini = p; 
 if(p == NULL){ 
	printf(" Lista vazia\n"); 
 }else if(p->po == p && p->valor == d){ 
	 free(ini); 
	 inicio->ini = NULL; 
 }else{ 
	 p = p->po; 
	 while (p->po != inicio->ini ){ 
		 if(p->valor == d){  
		 excluir = p; 
		 break; 
		 } 
		 p = p->po;
		} 
	 p=ini;
	 while (p->po != excluir ){ 
	 	p = p->po; 
		}
	 p->po = excluir->po;
	  free(excluir);
 }}
 
 
