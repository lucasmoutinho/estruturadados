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

int percursoLargura(t_no* r){
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
	return 0;
}

int percursoPre(t_no* r){
	if (r == NULL){
		return 0;
	}
	printf("%d ", r->raiz);
	percursoPre(r->esq);
	percursoPre(r->dir);
	return 0;
}

int percursoPos(t_no* r){
	if(r == NULL){
		return 0;;
	}
	percursoPos(r->esq);
	percursoPos(r->dir);
	printf("%d ", r->raiz);
	return 0;
}

int percursoEmOrdem(t_no* r){
	if(r == NULL){
		return 0;
	}
	percursoEmOrdem(r->esq);
	printf("%d ", r->raiz);
	percursoEmOrdem(r->dir);
	return 0;
}

int esvaziaArvore(t_no* r){
	if(r == NULL){
		return 0;
	}
	esvaziaArvore(r->esq);
	esvaziaArvore(r->dir);
	free(r);
	return 0;
}

int removeArvore(t_no** r){
	if(*r == NULL){
		printf("Arvore vazia\n");
		return 0;
	}
	esvaziaArvore(*r);
	*r = NULL;
	return 0;
}

t_no* busca(t_no* r, int valor){
	if(r == NULL){
		return NULL;
	}
	if(r->raiz == valor){
		return r; 
	}
	if (valor < r->raiz){
		return busca(r->esq, valor);
	}
	return busca(r->dir, valor);
}

int alturaArvore(t_no* r){
	if(r == NULL){
		return 0;
	}
	int he, hd;
	he = alturaArvore(r->esq);
	hd = alturaArvore(r->dir);
	if(he>hd){
		return he+1;
	}
	return hd+1;
}

int arvoreIguais(t_no* r1, t_no* r2){
	if (r1 == r2){
		return 1;
	}
	if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){
		return 0;
	}
	if(r1->raiz != r2->raiz){
		return 0;
	}
	if(!arvoreIguais(r1->esq, r2->esq) || !arvoreIguais(r1->dir, r2->dir)){
		return 0;
	}
	return 1;
}

/*FIM ALGORITMOS DE ARVORE*/

int main(){
	t_no* arvore;
	t_no* arvore2;
	int raiz, valor;

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
	percursoLargura(arvore);
	printf("\n");
	percursoPos(arvore);
	printf("\n");
	percursoEmOrdem(arvore);
	printf("\n");
	percursoPre(arvore);
	printf("\n");
	printf("Altura arvore = %d\n", alturaArvore(arvore));
	printf("Qual valor deseja procura?\n");
	scanf("%d", &valor);
	arvore2 = busca(arvore, valor);
	if (arvore2 == NULL){
		printf("Valor nao encontrado\n");
	}
	else{
		printf("No com valor %d encontrado\n", arvore2->raiz);
	}
	printf("Qual a raiz da segunda arvore binaria de busca que deseja criar?\n");
	scanf("%d", &raiz);
	arvore2 = criaArvore(raiz);
	printf("Deseja inserir algum valor? (0 caso nao)\n");
	scanf("%d", &raiz);
	while(raiz!=0){
		insereArvore(raiz, arvore2);
		printf("Deseja inserir algum valor? (0 caso nao)\n");
		scanf("%d", &raiz);
	}
	if (arvoreIguais(arvore, arvore2)){
		printf("Arvores iguais\n");
	}
	else{
		printf("Arvores distintas\n");
	}
	removeArvore(&arvore);
	removeArvore(&arvore2);
	percursoLargura(arvore);
	percursoLargura(arvore2);
	return 0;
}