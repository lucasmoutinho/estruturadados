#include <stdio.h>
#include <stdlib.h>

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