#include "stdio.h"
#include "stdlib.h"

typedef struct elemento{
	int dado;
	struct elemento* proximo;
} t_elemento;

typedef struct lista{
	t_elemento* inicio;
	t_elemento* fim;
} t_lista;

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

void crialista(t_lista* l){
	int valor, tmp, pos;
	char continua, onde;

	printf("Deseja inserir algo na lista? (S/N)\n");
	scanf("%c", &continua);
	getchar();
	while(continua != 'S' && continua != 's' && continua != 'n' && continua != 'N'){
		printf("Caractere invalido, insira outro\n");
		scanf(" %c", &continua);
		getchar();
	}
	while(continua == 'S' || continua == 's'){
		printf("Insira o valor inteiro que deseja inserir\n");
		scanf("%d", &valor);
		printf("Deseja inserir no inicio ou no fim da lista?\nInicio (i), Final(f), Qualquer lugar(Q)\n");
		scanf(" %c", &onde);
		getchar();
		while(onde != 'I' && onde != 'i' && onde != 'F' && onde != 'f' && onde != 'Q' && onde != 'q'){
			printf("Caractere invalido, insira outro\n");
			scanf(" %c", &onde);
			getchar();
		}
		if(onde == 'i' || onde == 'I'){
			insereinicio(valor, l);
		}
		else if(onde == 'F' || onde == 'f'){
			inserefim(valor, l);
		}
		else{
			printf("Qual posicao?\n");
			scanf("%d", &pos);
			getchar();
			inserequalquer(valor, l, pos);
		}
		printf("Deseja inserir algo a mais na lista? (S/N)\n");
		scanf(" %c", &continua);
		getchar();
	}
	printf("Deseja remover algo na lista? (S/N)\n");
	scanf(" %c", &continua);
	getchar();
	while(continua != 'S' && continua != 's' && continua != 'n' && continua != 'N'){
		printf("Caractere invalido, insira outro\n");
		scanf(" %c", &continua);
		getchar();
	}
	while(continua == 'S' || continua == 's'){
		printf("Deseja remover no inicio ou no fim da lista?\nInicio (i), Final(f), Qualquer lugar(Q) ou Tudo(T)\n");
		scanf(" %c", &onde);
		getchar();
		while(onde != 'I' && onde != 'i' && onde != 'F' && onde != 'f'&& onde != 'Q' && onde != 'q' && onde != 'T' && onde !='t'){
			printf("Caractere invalido, insira outro\n");
			scanf(" %c", &onde);
			getchar();
		}
		if(onde == 'i' || onde == 'I'){
			tmp = removeinicio(l);
		}
		else if(onde == 'F' || onde == 'f'){
			tmp = removefim(l);
		}
		else if(onde == 'Q' || onde == 'q'){
			printf("Qual posicao?\n");
			scanf("%d", &pos);
			getchar();
			tmp = removequalquer(l, pos);
		}
		else{
			removetudo(l);
			tmp = -1;
		}
		if(tmp != -1){
			printf("removido valor %d\n", tmp);
		}
		printf("Deseja remover algo a mais na lista? (S/N)\n");
		scanf(" %c", &continua);
		getchar();
	}
}

int main(){
	t_lista teste;

	teste.inicio = NULL;
	teste.fim = NULL;
	crialista(&teste);
	mostralista(&teste);

	return 0;
}