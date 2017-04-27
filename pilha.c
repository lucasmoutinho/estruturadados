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

/*ALGORITMOS DE LISTA*/

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

/*FIM ALGORITMO LISTAS/

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

void desempilhartudo(t_pilha*p){
	int tmp;

	while(p->l->inicio != NULL){
		tmp = removeinicio(p->l);
		printf("Removido %d", tmp);
	}
}

/*FIM ALGORITMO PILHAS*/

/*ALGORITMO FILAS*/





/*FIM ALGORITMO FILAS*/

/*ALGORITMO DEQUES*/




/*FIM ALGORITMO DEQUES*/

/*MAIN*/

int main(){

	return 0;
}