#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no * esq;
	struct no * dir;
}t_no;

t_no * criarNo(int dado){
   t_no * n =  (t_no *)malloc(sizeof(t_no));
   n->esq = NULL;
   n->dir = NULL;
   n->dado = dado;
   return n;
}

int inserir(t_no * raiz, int dado){
    if(raiz == NULL){
       return -1;
    }
    if(raiz->dado > dado){//Esquerda
       if(raiz->esq == NULL){
	  raiz->esq = criarNo(dado);
	 
       }else{
          return inserir(raiz->esq, dado);
       }
    }else if(raiz->dado < dado){//Direita
	if(raiz->dir == NULL){
	  raiz->dir = criarNo(dado);
       }else{
          return inserir(raiz->dir, dado);
       }
    }
    return -1;
}


//esta função deve retornar 1 caso um nó foi removido e 0 caso contrário
int remover(t_no * raiz, int dado){

   //COMPLETAR
   return 0;
}


//esta função deve calcular a altura de uma árvore
int altura(t_no * raiz){
  if(raiz == NULL){
    return 0;
  }
  he = altura(raiz->esq);
  hd = altura(raiz->dir);
  if(he>hd){
    return he + 1;
  }
  return hd + 1;
}

//esta função deve retornar 1 caso a arvore esteja balanceada, 0 caso contrário
int estaBalanceada(t_no * raiz){
  if(raiz == NULL){
    return 1;
  }
  if (!estaBalanceada(raiz->dir)){
    return 0;
  }
  if (!estaBalanceada(raiz->esq)){
    return 0;
  }
  he = altura(raiz->esq);
  hd = altura(raiz->dir);
  int dif;
  if(he>hd){
    dif = he - hd;
  }
  else{
    dif = hd - he;
  }
  if(dif > 1){
    return 0;
  }
  return 1;
}


//esta função recebe a raiz de uma árvore não balanceada e retorna a raiz de uma 
//árvore balanceada pelo método do vetor
t_no * vetor(t_no * raiz){
  //COMPLETAR 
  return NULL;
}

void em_ordem(t_no * raiz){
   if(raiz != NULL){
      em_ordem(raiz->esq);
      printf("%d\n",raiz->dado);
      em_ordem(raiz->dir);
   }

}


int main (int argc, char *argv[]){
    t_no * r = criarNo(100);
    em_ordem(r);
    printf("\n");
    inserir(r,50);
    em_ordem(r);
    printf("\n");
    inserir(r,150);
    em_ordem(r);
    printf("\n");
    printf("FIM!!!\n");
}