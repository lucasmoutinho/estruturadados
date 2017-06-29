#include <stdio.h>
#include <stdlib.h>

void mostraVetor(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void insertion_sort_orderned(int a[],int n){
	int i, j, elemento;

	for(j=1;j<n;j++){
		i = j-1;
		elemento = a[j];
		while(i>=0 && a[i] > elemento){
			a[i+1] = a[i];
			a[i] = elemento;
			i--;
		}
	}
}

void insertion_sort_reversed(int a[],int n){
	int i, j, elemento;

	for(j=1;j<n;j++){
		i = j-1;
		elemento = a[j];
		while(i>=0 && a[i] < elemento){
			a[i+1] = a[i];
			a[i] = elemento;
			i--;
		}
	}
}

void bubble_sort_ordened(int a[], int n){
	int houvetroca = 1, i = 0, j, aux;
	while(i<n-1 && houvetroca){
		houvetroca = 0;
		for(j=0; j< n-1; j++){
			if(a[j+1] > a[j]){
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				houvetroca = 1;
			}
		}
		i++;
	}
}

void bubble_sort_reversed(int a[], int n){
	int houvetroca = 1, i = 0, j, aux;
	while(i<n-1 && houvetroca){
		houvetroca = 0;
		for(j=0; j< n-1; j++){
			if(a[j+1] < 	a[j]){
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				houvetroca = 1;
			}
		}
		i++;
	}
}

void selection_sort_ordened(int a[], int n){
	int i, j, min, aux;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		aux = a[min];
		a[min] = a[i];
		a[i] = aux;
	}
}

void selection_sort_reversed(int a[], int n){
	int i, j, max, aux;
	for(i=0;i<n-1;i++){
		max = i;
		for(j=i+1;j<n;j++){
			if(a[j]>a[max]){
				max = j;
			}
		}
		aux = a[max];
		a[max] = a[i];
		a[i] = aux;
	}
}

int particiona(int a[], int inicio, int fim){
	int esquerda, direita, pivo, aux;
	esquerda = inicio;
	direita = fim;
	pivo = a[inicio];
	while(esquerda < direita){
		while(a[esquerda]<=pivo){
			esquerda++;
		}
		while(a[direita]>pivo){
			direita--;
		}
		if(esquerda<direita){
			aux = a[esquerda];
			a[esquerda] = a[direita];
			a[direita] = aux;
		}
	}
	a[inicio] = a[direita];
	a[direita] = pivo;
	return direita;
}

void quicksort(int a[], int inicio, int fim){
	int pivo;
	if(fim>inicio){
		pivo = particiona(a,inicio,fim);
		quicksort(a,inicio,pivo-1);
		quicksort(a,pivo+1,fim);
	}
}

void merge(int a[],int inicio,int meio,int fim){
	int* temp;
	int p1, p2, tam, i, j, k, fim1 = 0, fim2 = 0;
	tam = fim - inicio + 1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int*)malloc(sizeof(int)*tam);
	if(temp != NULL){
		for(i=0;i<tam;i++){
			if(!fim1 && !fim2){
				if(a[p1] < a[p2]){
					temp[i] = a[p1];
					p1++;
				}
				else{
					temp[i] = a[p2];
					p2++;
				}
				if(p1 > meio){
					fim1 = 1;
				}
				if(p2 > fim){
					fim2 = 1;
				}
			}
			else{
				if(!fim1){
					temp[i] = a[p1];
					p1++;
				}
				else{
					temp[i] = a[p2];
					p2++;
				}
			}
		}
	}
	k = inicio;
	for(j=0;j<tam;j++){
		a[k] = temp[j];
		k++;
	}
	free(temp);
}

void mergesort(int a[],int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio+fim)/2;
		mergesort(a,inicio, meio);
		mergesort(a,meio+1, fim);
		merge(a,inicio,meio,fim);
	}
}

void setaValor(int *a){
	a[0] = 7;
	a[1] = 2;
	a[2] = 3;
	a[3] = 1;
	a[4] = 8;
	a[5] = 9;
	a[6] = 6;
	a[7] = 5;
	a[8] = 4;
	a[9] = 10;
}

int main(){
	int a[10] = {7,2,3,1,8,9,6,5,4,10};
	mostraVetor(a,10);
	insertion_sort_orderned(a,10);
	mostraVetor(a,10);
	insertion_sort_reversed(a,10);
	mostraVetor(a,10);
	setaValor(a);
	mostraVetor(a,10);
	bubble_sort_ordened(a,10);
	mostraVetor(a,10);
	bubble_sort_reversed(a,10);
	mostraVetor(a,10);
	setaValor(a);
	mostraVetor(a,10);
	selection_sort_reversed(a,10);
	mostraVetor(a,10);
	selection_sort_ordened(a,10);
	mostraVetor(a,10);
	setaValor(a);
	mostraVetor(a,10);
	quicksort(a,0,9);
	mostraVetor(a,10);
	setaValor(a);
	mostraVetor(a,10);
	mergesort(a,0,9);
	mostraVetor(a,10);
	return 0;
}