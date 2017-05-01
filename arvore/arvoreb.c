#include "stdio.h"
#include "stdlib.h"

typedef struct no{
	int raiz;
	struct no* esq;
	struct no* dir;	
} t_no;

typedef struct elemento{
	t_no* no;
	struct elemento* proximo;
} t_elemento;

typedef struct lista{
	t_elemento* inicio;
	t_elemento* fim;
} t_lista;

typedef struct fila{
	t_lista* l;
}t_fila;

/*ALGORITMOS DE LISTA!*/

int insereinicio(t_no* no, t_lista* l){
	t_elemento* nv;

	nv = (t_elemento*)malloc(sizeof(t_elemento)); 
	nv->no = no;
	nv -> proximo = l->inicio;
	l -> inicio = nv;
	if(l -> fim == NULL){
		l -> fim = nv;
	} 
	return 0;
}

int estavazia(t_lista* l){
	if(l -> inicio == NULL){
		return 1;
	}
	return 0;
}

t_no* removefim(t_lista* l){
	if(estavazia(l)){
		printf("Lista vazia\n");
		return NULL;
	}
	t_elemento* ultimo = l -> inicio;
	t_elemento* penultimo = NULL;
	t_no* tmp = l -> fim -> no;

	while(ultimo -> proximo != NULL){
		penultimo = ultimo;
		ultimo = ultimo -> proximo;
	}
	if(penultimo != NULL){
		penultimo -> proximo = NULL;
		l -> fim = penultimo;
	}
	else{
		l -> fim = NULL;
		l -> inicio = NULL;
	}
	free(ultimo);
	return tmp;
}

t_lista* crialista(){
	t_lista* l = (t_lista*)malloc(sizeof(t_lista));
	l->inicio=NULL;
	l->fim=NULL;
	return l;
}

/*FIM ALGORITMO LISTAS*/

/*ALGORITMO FILAS*/

t_fila* criafila(){
	t_fila* f = (t_fila*)malloc(sizeof(t_fila));
	f->l = crialista();
	return f;
}

void enfileira(t_no* no, t_fila* f){
	insereinicio(no, f->l);
}

t_no* desenfileira(t_fila* f){
	return removefim(f->l);
}

int filavazia(t_fila* f){
	if(f->l->inicio == NULL){
		return 1;
	}
	return 0;
}

/*FIM ALGORITMO FILAS*/


/*ALGORITMOS DE ARVORE*/

t_no* criaArvore(int raiz){
	t_no* no = (t_no*)malloc(sizeof(t_no));
	no->raiz = raiz;
	no->dir = NULL;
	no->esq = NULL;
	return no; 
}

int insereArvore(int v, t_no* r){
	if(r == NULL || r->raiz == v){
		printf("Erro, arvore vazia ou elemento ja inserido\n");
		return -1;
	}
	if(v > r->raiz){
		if(r->dir == NULL){
			r->dir = criaArvore(v);
		}
		else{
			insereArvore(v,r->dir);
		}
	}
	else{
		if(r->esq == NULL){
			r->esq = criaArvore(v);
		}
		else{
			insereArvore(v,r->esq);
		}
	}
	return 0;
}

int mostraArvore(t_no* r){
	if(r == NULL){
		printf("Arvore vazia\n");
		return -1;
	}
	t_fila* f = criafila();
	t_no* no_atual;

	enfileira(r, f);
	while(!filavazia(f)){
		no_atual = desenfileira(f);
		printf("%d ", no_atual->raiz);
		if(no_atual->esq != NULL){
			enfileira(no_atual->esq, f);
		}
		if(no_atual->dir != NULL){
			enfileira(no_atual->dir, f);
		}
	}
	printf("\n");
	return 0;
}

/*FIM ALGORITMOS DE ARVORE*/

int main(){
	t_no* arvore;
	int raiz;

	printf("Qual a raiz da arvore binaria de busca que deseja criar?\n");
	scanf("%d", &raiz);
	arvore = criaArvore(raiz);
	printf("Deseja inserir algum valor? (0 caso nao)\n");
	scanf("%d", &raiz);
	while(raiz!=0){
		insereArvore(raiz, arvore);
		printf("Deseja inserir algum valor? (0 caso nao)\n");
		scanf("%d", &raiz);
	}
	mostraArvore(arvore);
	return 0;
}