#include "stdio.h"
#include "stdlib.h"

typedef struct no{
	int raiz;
	no* esq;
	no* dir;	
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

int removefim(t_lista* l){
	if(estavazia(l)){
		printf("Lista vazia\n");
		return -1;
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


void mostralista(t_lista* l){
	if(l -> inicio == NULL){
		printf("Lista vazia\n");
	}
	else{
		t_elemento* p;
		int i = 0;

		p = l -> inicio;
		while(p != NULL){
			printf("Posicao %d --- valor %d\n", i, p->dado);
			p = p -> proximo;
			i++;
		}
	}
	printf("Fim da lista\n");
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

int desenfileira(t_fila* f){
	return removefim(f->l);
}

void filavazia(t_fila* f){
	if(f->l->inicio == NULL){
		return 1;
	}
	return 0
}

void mostraFila(t_fila* f){
	if(filavazia(f)){
		printf("Fila vazia\n");
	}
	else{
		mostralista(f->l);
	}
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
		printf("%d\n", no_atual->raiz);
		if(no_atual->esq != NULL){
			enfileira(no_atual->esq);
		}
		if(no_atual->dir != NULL){
			enfileira(no_atual->dir);
		}
	}
	return 0;
}

/*FIM ALGORITMOS DE ARVORE*/

int main(){
	return 0;
}