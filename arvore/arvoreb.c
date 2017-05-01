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

insere 

int main(){
	return 0;
}