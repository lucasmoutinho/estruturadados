#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int dado;
	struct elemento* proximo;
} t_elemento;

typedef struct lista{
	t_elemento* inicio;
	t_elemento* fim;
} t_lista;

typedef struct pilha{
	t_lista* l;
}t_pilha;

typedef struct fila{
	t_lista* l;
}t_fila;

/*ALGORITMOS DE LISTA!*/

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
	nv -> proximo = NULL;
	if(l -> inicio == NULL){
		l -> inicio = nv; 
	}
	else{
		l -> fim -> proximo = nv;
	}
	l -> fim = nv;
	return 0;
}

int estavazia(t_lista* l){
	if(l -> inicio == NULL){
		return 1;
	}
	return 0;
}

int removeinicio(t_lista* l){
	if(estavazia(l)){
		printf("Lista vazia\n");
		return -1;
	}
	t_elemento* p = l -> inicio;
	int tmp = p -> dado;

	l -> inicio = p -> proximo;
	free(p);
	if(l -> inicio == NULL){
		l -> fim = NULL;
	}
	return tmp;
}

int removefim(t_lista* l){
	if(estavazia(l)){
		printf("Lista vazia\n");
		return -1;
	}
	t_elemento* ultimo = l -> inicio;
	t_elemento* penultimo = NULL;
	int tmp = l -> fim -> dado;

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

int inserequalquer(int valor, t_lista* l, int pos){
	
	if (pos == 0){
		insereinicio(valor, l);
		return 0;
	}
	else if( l->inicio == NULL){
		printf("Posicao invalida\n");
		return -1;
	}

	t_elemento* nv = (t_elemento*)malloc(sizeof(t_elemento));
	t_elemento* ultimo = l->inicio;
	t_elemento* penultimo = NULL;
	int i = 0;

	nv->dado = valor;
	while(i!=pos && ultimo->proximo != NULL){
		penultimo = ultimo;
		ultimo = ultimo->proximo;
		i++;
	}
	if(pos==i+1){
		nv->proximo=NULL;
		ultimo->proximo=nv;
		l->fim=nv;
	}
	else if(pos==i){
		penultimo->proximo=nv;
		nv->proximo=ultimo;
	}
	else{
		printf("Posicao invalida\n");
		free(nv);
		return -1;
	}
	return 0;
}

int removequalquer(t_lista* l, int pos){
	int valor, i = 0;

	if(estavazia(l)){
		printf("Lista vazia\n");
		return -1;
	}
	else if(pos == 0){
		valor = removeinicio(l);
		return valor;
	}

	t_elemento* ultimo = l->inicio;
	t_elemento* penultimo = NULL;

	while(i!=pos && ultimo->proximo != NULL){
		penultimo = ultimo;
		ultimo = ultimo->proximo;
		i++;
	}
	if(pos==i){
		penultimo->proximo = ultimo->proximo;
		valor = ultimo->dado;
		if(penultimo->proximo == NULL){
			l->fim = penultimo;
		}
		free(ultimo);
	}
	else{
		printf("Posicao invalida\n");
		return -1;
	}
	return valor;
}

void removetudo(t_lista* l){
	int tmp;

	while(l->inicio != NULL){
		tmp = removeinicio(l);
		printf("Removido %d da posicao 0\n", tmp);
	}
	printf("Lista vazia\n");
}

t_lista* crialista(){
	t_lista* l = (t_lista*)malloc(sizeof(t_lista));
	l->inicio=NULL;
	l->fim=NULL;
	return l;
}

/*FIM ALGORITMO LISTAS*/

/*ALGORITMO PILHAS*/

t_pilha* criapilha(){
	t_pilha* p = (t_pilha*)malloc(sizeof(t_pilha));
	p->l = crialista();
	return p;
}

void empilhar(int valor, t_pilha* p){
	insereinicio(valor, p->l);
}

int desempilhar(t_pilha* p){
	return removeinicio(p->l);
}

void desempilharTudo(t_pilha*p){
	int tmp;

	while(p->l->inicio != NULL){
		tmp = removeinicio(p->l);
		printf("Removido %d\n", tmp);
	}
}

void mostraPilha(t_pilha* p){
	if(p->l->inicio == NULL){
		printf("Pilha vazia\n");
	}
	else{
		mostralista(p->l);
	}
}

/*FIM ALGORITMO PILHAS*/

/*ALGORITMO FILAS*/

t_fila* criafila(){
	t_fila* f = (t_fila*)malloc(sizeof(t_fila));
	f->l = crialista();
	return f;
}

void enfileira(int valor, t_fila* f){
	insereinicio(valor, f->l);
}

int desenfileira(t_fila* f){
	return removefim(f->l);
}

void desenfileiraTudo(t_fila* f){
	int tmp;

	while(f->l->inicio!= NULL){
		tmp = removefim(f->l);
		printf("Removido %d\n", tmp);
	}
}

int filavazia(t_fila* f){
	if(f->l->inicio == NULL){
		return 1;
	}
	return 0;
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

/*ALGORITMO DEQUES*/




/*FIM ALGORITMO DEQUES*/

/*MAIN*/

int main(){
	t_fila* fila;
	t_pilha* pilha;

	fila = criafila();
	pilha = criapilha();

	enfileira(1,fila);
	enfileira(2,fila);
	enfileira(3,fila);
	enfileira(4,fila);
	enfileira(5,fila);
	enfileira(6,fila);

	mostraFila(fila);

	desenfileira(fila);
	desenfileira(fila);
	desenfileira(fila);
	desenfileira(fila);
	desenfileira(fila);
	desenfileira(fila);

	enfileira(1,fila);
	enfileira(2,fila);
	enfileira(3,fila);
	enfileira(4,fila);
	enfileira(5,fila);
	enfileira(6,fila);

	desenfileiraTudo(fila);

	empilhar(1, pilha);
	empilhar(2, pilha);
	empilhar(3, pilha);
	empilhar(4, pilha);
	empilhar(5, pilha);
	empilhar(6, pilha);

	mostraPilha(pilha);

	desempilhar(pilha);
	desempilhar(pilha);
	desempilhar(pilha);
	desempilhar(pilha);
	desempilhar(pilha);
	desempilhar(pilha);

	empilhar(1, pilha);
	empilhar(2, pilha);
	empilhar(3, pilha);
	empilhar(4, pilha);
	empilhar(5, pilha);
	empilhar(6, pilha);

	desempilharTudo(pilha);

	return 0;
}