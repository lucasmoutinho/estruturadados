#include "stdio.h"
#include "stdlib.h"

typedef struct no{
	int raiz;
	no* esq;
	no* dir;	
} t_no;

t_no* criaArvore(int raiz){
	t_no* no = (t_no*)malloc(sizeof(t_no));
	no->raiz = raiz;
	no->dir = NULL;
	no->esq = NULL;
	return no; 
}

int insere(int v, t_no* r){
	if(r == NULL || r->raiz == v){
		printf("Erro, arvore vazia ou elemento ja inserido\n");
		return -1;
	}
	if(v > r->raiz){
		if(r->dir == NULL){
			r->dir = (t_no*)malloc(sizeof(t_no));
		}
		else{
			insere(v,r->dir);
		}
	}
	else{
		if(r->esq == NULL){
			r->esq = (t_no*)malloc(sizeof(t_no));
		}
		else{
			insere(v,r->esq);
		}
	}
	return 0;
}



int main(){
	return 0;
}