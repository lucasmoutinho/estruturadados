#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int raiz;
	int fb;
	struct no* esq;
	struct no* dir;	
} t_no;

t_no* criaArvore(int valor){
	t_no* no = (t_no*)malloc(sizeof(t_no));
	no->raiz = valor;
	no->fb = 0;
	no->dir = NULL;
	no->esq = NULL;
	return no; 
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

int insereArvore(int v, t_no** r){
	if(*r == NULL){
		*r = criaArvore(v);
		return 1;
	}
	if(v > (*r)->raiz){
		if(insereArvore(v,&((*r)->dir))){
			(*r)->fb = alturaArvore((*r)->dir) - alturaArvore((*r)->esq);
			
			return 1;
		}
	}
	else if(v < (*r)->raiz){
		if(insereArvore(v,&((*r)->esq))){
			(*r)->fb = alturaArvore((*r)->dir) - alturaArvore((*r)->esq);
			return 1;
		}
	}
	return 0;
}

int percursoPos(t_no* r){
	if(r==NULL){
		return 0;
	}
	percursoPos(r->esq);
	percursoPos(r->dir);
	printf("raiz: %d, fb: %d\n", r->raiz, r->fb);
	return 0;
}

int main(){
	t_no* raiz = NULL;
	insereArvore(5, &raiz);
	insereArvore(6, &raiz);
	insereArvore(4, &raiz);
	insereArvore(2, &raiz);
	insereArvore(1, &raiz);
	insereArvore(3, &raiz);
	percursoPos(raiz);
	return 0;
}