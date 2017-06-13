#include <stdio.h>
#include <stdlib.h>

/*Grafos*/

typedef struct elementoA{
	char dado;
	struct elementoA* prox;
} t_elementoA;

typedef struct elementoV{
	char dado;
	t_elementoA* aresta;
	struct elementoV* prox;
} t_elementoV;

typedef struct lista{
	t_elementoV* inicio;
	t_elementoV* fim;
} t_lista;

/*Listas e Pilhas*/

typedef struct elemento{
	char dado;
	struct elemento* proximo;
} t_elemento;

typedef struct listapi{
	t_elemento* inicio;
	t_elemento* fim;
} t_listapi;

typedef struct pilha{
	t_listapi* l;
}t_pilha;

/*Coisas para os grafos*/


t_elementoA* criaAresta(char n){
	t_elementoA* nv = (t_elementoA*)malloc(sizeof(t_elementoA));
	nv->dado = n;
	nv->prox = NULL;
	return nv;
}

t_lista* criaLista(){
	t_lista* nv = (t_lista*)malloc(sizeof(t_lista));
	nv->inicio = NULL;
	nv->fim = NULL;
	return nv;
}

int insereVertice(char valor, t_lista* l){
	t_elementoV* nv;
	nv = (t_elementoV*)malloc(sizeof(t_elementoV));
	nv -> dado = valor;
	nv->aresta = NULL;
	nv -> prox = NULL;
	if(l -> inicio == NULL){
		l -> inicio = nv; 
	}
	else{
		l -> fim -> prox = nv;
	}
	l -> fim = nv;
	return 0;
}

int insereAresta(char valorA, char valorV, t_lista*l){
	t_elementoV* atual = l->inicio;
	t_elementoA* atualA;
	t_elementoA* antA = NULL;
	while(atual != NULL && atual->dado != valorV){
		atual = atual->prox;
	}
	if (atual == NULL){
		return -1;
	}
	atualA = atual->aresta;
	while(atualA != NULL && atualA->dado != valorA){
		antA = atualA;
		atualA = atualA->prox;
	}
	if(atualA != NULL){
		return -1;
	}
	atualA = criaAresta(valorA);
	if(antA == NULL){
		atual->aresta = atualA;
	}
	else{
		antA->prox = atualA;
	}
	return 0;
}

void mostraGrafo(t_lista* l){
	t_elementoV* atualV = l->inicio;
	t_elementoA* atualA;
	while(atualV != NULL){
		printf("%c ", atualV->dado);
		atualA = atualV->aresta;
		while(atualA != NULL){
			printf("%c ", atualA->dado);
			atualA = atualA->prox;
		}
		printf("\n");
		atualV = atualV->prox;
	}
}

/*Coisas para a pilha*/

int insereinicio(char valor, t_listapi* l){
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

int removeinicio(t_listapi* l){
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

t_lista* crialistapi(){
	t_listapi* l = (t_listapi*)malloc(sizeof(t_listapi));
	l->inicio=NULL;
	l->fim=NULL;
	return l;
}

t_pilha* criapilha(){
	t_pilha* p = (t_pilha*)malloc(sizeof(t_pilha));
	p->l = crialistapi();
	return p;
}

void empilhar(char valor, t_pilha* p){
	insereinicio(valor, p->l);
}

int desempilhar(t_pilha* p){
	return removeinicio(p->l);
}

/*Coisas para a pilha*/

t_elemento* buscaProfundidade(t_lista* inicio, char valor){
	t_listapi* marcados = crialistapi();
	t_pilha* p = criapilha();
	char encontrado;
	empilhar(valor, p);
	insereinicio();
}

int main(){
	t_lista* lista;
	lista = criaLista();
	insereVertice('A',lista);
	insereVertice('B',lista);
	insereVertice('C',lista);
	insereAresta('A','A',lista);
	insereAresta('B','A',lista);
	insereAresta('C','A',lista);
	insereAresta('B','C',lista);
	mostraGrafo(lista);
	return 0;
}