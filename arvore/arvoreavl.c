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

t_no* rotacionaRR(t_no* raiz){
	t_no* aux = raiz->dir;
	int dado = raiz->raiz;
	raiz->dir = raiz->esq;
	raiz->esq = raiz->dir->esq;
	raiz->dir->esq = raiz->dir->dir;
	raiz->dir->dir = aux;
	raiz->raiz = raiz->dir->raiz;
	raiz->dir->raiz = dado;
	raiz->fb = alturaArvore(raiz->dir) - alturaArvore(raiz->esq);
	raiz->dir->fb = alturaArvore(raiz->dir->dir) - alturaArvore(raiz->dir->esq);
	return raiz;
}

t_no* rotacionaLL(t_no* raiz){
	t_no* aux = raiz->esq;
	int dado = raiz->raiz;
	raiz->esq = raiz->dir;
	raiz->dir = raiz->esq->dir;
	raiz->esq->dir = raiz->esq->esq;
	raiz->esq->esq = aux;
	raiz->raiz = raiz->esq->raiz;
	raiz->esq->raiz = dado;
	raiz->fb = alturaArvore(raiz->dir) - alturaArvore(raiz->esq);
	raiz->esq->fb = alturaArvore(raiz->esq->dir) - alturaArvore(raiz->esq->esq);
	return raiz;
}

t_no* rotacionaRL(t_no* raiz){
	raiz->esq = rotacionaLL(raiz->esq);
	raiz = rotacionaRR(raiz);
	return raiz;
}

t_no* rotacionaLR(t_no* raiz){
	raiz->dir = rotacionaRR(raiz->dir);
	raiz = rotacionaLL(raiz);
	return raiz;
}

int insereArvore(int v, t_no** r){
	if(*r == NULL){
		*r = criaArvore(v);
		return 1;
	}
	if(v > (*r)->raiz){
		if(insereArvore(v,&((*r)->dir))){
			(*r)->fb = alturaArvore((*r)->dir) - alturaArvore((*r)->esq);
			if((*r)->fb >= 2){
				if((*r)->esq->fb >= 1){
					*r = rotacionaLL(*r);
				}
				else{
					*r = rotacionaLR(*r);
				}
			}
			return 1;
		}
	}
	else if(v < (*r)->raiz){
		if(insereArvore(v,&((*r)->esq))){
			(*r)->fb = alturaArvore((*r)->dir) - alturaArvore((*r)->esq);
			if((*r)->fb <= -2){
				if((*r)->esq->fb <= -1){
					*r = rotacionaRR(*r);
				}
				else{
					*r = rotacionaRL(*r);
				}
			}
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

int balanceada(t_no* raiz){
	if(raiz == NULL){
		return 1;
	}
	if(!balanceada(raiz->esq)){
		return 0;
	}
	if(!balanceada(raiz->dir)){
		return 0;
	}
	int fb = alturaArvore(raiz->dir) - alturaArvore(raiz->esq);
	if(fb<-1 || fb>1){
		return 0;
	}
	return 1;
}

int main(){
	t_no* raiz = NULL;
	insereArvore(5, &raiz);
	insereArvore(6, &raiz);
	insereArvore(4, &raiz);
	insereArvore(2, &raiz);
	percursoPos(raiz);
	printf("balanceada: %d\n", balanceada(raiz));
	insereArvore(1, &raiz);
	percursoPos(raiz);
	printf("balanceada: %d\n", balanceada(raiz));
	insereArvore(3, &raiz);
	percursoPos(raiz);
	printf("balanceada: %d\n", balanceada(raiz));
	return 0;
}