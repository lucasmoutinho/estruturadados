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
			if(a[j+1] < a[j]){
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				houvetroca = 1;
			}
		}
		i++;
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
	return 0;
}