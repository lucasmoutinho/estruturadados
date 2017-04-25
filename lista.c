#include "stdio.h"
#include "stdlib.h"

typedef struct elemento{
	int dado;
	struct elemento* proximo;
} t_elemento;

typedef struct lista{
	t_elemento* inicio;
	t_elemento* fim;
} t_lista;

int insereinicio(int valor, t_lista* l){
	t_elemento* nv;

	nv = (t_elemento*)malloc(sizeof(t_elemento)); 
	nv -> dado = valor;
	nv -> proximo = l->inicio;
	l -> inicio = nv;
	if(l -> fim == NULL){
		l -> fim = nv;
	} 
	return 0;
}

int inserefim(int valor, t_lista* l){
	t_elemento* nv;

	nv = (t_elemento*)malloc(sizeof(t_elemento));
	nv -> dado = valor;
	l -> fim = nv;
	if(l -> inicio == NULL){
		l -> inicio = nv; 
	}
	return 0;
}


int main(){
	
	return 0;
}