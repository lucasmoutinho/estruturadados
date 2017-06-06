typedef struct no{
	int raiz;
	struct no* esq;
	struct no* dir;	
} t_no;

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

