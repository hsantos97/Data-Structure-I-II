// Nyberus - Artyon

#include <stdio.h>
#include <stdlib.h>

#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>

// Estrutura
struct estrutura{
	int dado;
	struct estrutura *prox;
};
typedef struct estrutura tipoEstru;

// Funções Insere
void insereInicio(tipoEstru**, int);
void insereFim(tipoEstru**, int);
void inserePosicao(tipoEstru**, int, int);
void insereValor(tipoEstru**, int, int);
// Funções Remove
int removeInicio(tipoEstru**);
int removeFim(tipoEstru**);
int removePosicao(tipoEstru**, int);
int removeValor(tipoEstru**, int);

// Funções de Busca
int buscaValor(tipoEstru*, int);
int buscaPosicao(tipoEstru*, int);

// Função Ordena
void ordena(tipoEstru**, int);
void quickSort(int*, int, int);

// Função Contador
int contador(tipoEstru*);

// Fução Imprime
void imprimeLista(tipoEstru*);

// Função Principal
int main(){
	struct tms time;
	int tics_per_second;
	tics_per_second = sysconf(_SC_CLK_TCK);
	
	tipoEstru *lista;
	lista = NULL;
	
	insereInicio(&lista, 1);
	insereInicio(&lista, 2);
	insereInicio(&lista, 3);
	insereInicio(&lista, 4);
	insereInicio(&lista, 5);
	insereInicio(&lista, 6);
	insereInicio(&lista, 7);
	insereInicio(&lista, 8);
	imprimeLista(lista);

	insereFim(&lista, 9);
	imprimeLista(lista);
	
	inserePosicao(&lista, 10, 1);
	inserePosicao(&lista, 11, 2);
	imprimeLista(lista);
	
	insereValor(&lista, 12, 2);
	imprimeLista(lista);
	
	imprimeLista(lista);
	printf("Valor removido -> %d\n", removeInicio(&lista));

	imprimeLista(lista);
	printf("Valor removido -> %d\n", removeFim(&lista));

	imprimeLista(lista);
	printf("Valor removido -> %d\n", removePosicao(&lista, 3));
	imprimeLista(lista);
	printf("Na posicao -> %d; contem o valor -> %d\n", 2, buscaPosicao(lista, 2));
	
	imprimeLista(lista);
	printf("Valor removido -> %d\n", removeValor(&lista, 3));
	imprimeLista(lista);
	printf("Valor -> %d; na posicao -> %d\n", 5, buscaValor(lista, 5));
	imprimeLista(lista);
	
	printf("Vetor Ordenado\n");
	ordena(&lista, contador(lista));
	imprimeLista(lista);
	
	printf("Contador -> %d\n", contador(lista));
	times(&time);
	printf("Tempo de uso do processador pelo processo: %f segundos\n", ((double)time.tms_utime) / tics_per_second);
	
	return 0;
}

// Função insereInicio
void insereInicio(tipoEstru **lista, int valor){
	tipoEstru *novoNo;
	novoNo = (tipoEstru*)malloc(sizeof(tipoEstru));
	novoNo->dado = valor;
	novoNo->prox == NULL;
	if((*lista) == NULL){
		(*lista) = novoNo;
	}else{
		novoNo->prox = (*lista);
		(*lista) = novoNo;
	}
}

// Função insereFim
void insereFim(tipoEstru **lista, int valor){
	tipoEstru *novoNo, *aux;
	novoNo = (tipoEstru*)malloc(sizeof(tipoEstru));
	novoNo->dado = valor;
	novoNo->prox = NULL;
	if((*lista) == NULL){
		(*lista) = novoNo;
	}else{
		aux = (*lista);
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novoNo;
	}
}

// Função inserePosicao
void inserePosicao(tipoEstru **lista, int valor, int posicao){
	tipoEstru *novoNo, *aux1, *aux2;
	int i;
	novoNo = (tipoEstru*)malloc(sizeof(tipoEstru));
	novoNo->dado = valor;
	novoNo->prox = NULL;
	if((*lista) == NULL){
		(*lista) = novoNo;
	}else{
		if(posicao == 1){
			insereInicio(&*lista, valor);
		}else{
			aux1 = (*lista);
			aux2 = (*lista);
			for(i = 1; i < (posicao - 1); i++){
				aux1 = aux1->prox;
				aux2 = aux2->prox;
			}
			aux1 = aux1->prox;
			aux2->prox = novoNo;
			novoNo->prox = aux1;
		}
	}
}

// Função insereValor
void insereValor(tipoEstru **lista, int valor, int pos){
	tipoEstru *novoNo, *aux1, *aux2;
	int i;
	novoNo = (tipoEstru*)malloc(sizeof(tipoEstru));
	novoNo->dado = valor;
	novoNo->prox = NULL;
	if((*lista) == NULL){
		(*lista) = novoNo;
	}else{
		aux1 = (*lista);
		while((pos != aux1->dado) && (aux1->prox != NULL)){
			aux1 = aux1->prox;
		}
		if(aux1->prox != NULL){
			aux2 = aux1->prox;
			novoNo->prox = aux2;
			aux1->prox = novoNo;
		}
	}
}

// Função removeInicio
int removeInicio(tipoEstru **lista){
	int valor;
	if((*lista) != NULL){
		tipoEstru *aux1;
		aux1 = (*lista);
		(*lista) = aux1->prox;
		valor = aux1->dado;
		free(aux1);
	}
	return valor;
}

// Função removeFim
int removeFim(tipoEstru **lista){
	int valor;
	if(contador(*lista) > 1){
		tipoEstru *aux1, *aux2;
		aux1 = (*lista);
		while(aux1->prox != NULL){
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		aux2->prox = NULL;
		valor = aux1->dado;
		free(aux1);
	}else{
		if(contador(*lista) == 1){
			valor = removeInicio(&(*lista));
		}
	}
	return valor;
}

// Função removePosicao
int removePosicao(tipoEstru **lista, int posicao){
	tipoEstru *aux1, *aux2;
	int i, valor;
	if(posicao > contador(*lista)){
		printf("Posicao Inesistente.\n");
		return -1;
	}else{
		aux1 = (*lista);
		aux2 = (*lista);
		for(i = 1; i < posicao; i++){
			aux1 = aux1->prox;
			if(i < (posicao - 1)){
				aux2 = aux2->prox;
			}
		}
		aux2->prox = aux1->prox;
		valor = aux1->dado;
		free(aux1);
		return valor;
	}
}

// Função removeValor
int removeValor(tipoEstru **lista, int valor){
	tipoEstru *aux;
	int i = 1;
	aux = (*lista);
	if(lista != NULL){
		while((aux->dado != valor) && (i < contador(*lista))){
			aux = aux->prox;
			i++;
		}
		if(i > contador(*lista)){
			return -1;
		}else{
			return removePosicao(&(*lista), i);
		}
	}else{
		return -1;
	}
}

// Função buscaValor
int buscaValor(tipoEstru *lista, int valor){
	if(lista != NULL){
		int i = 1;
		tipoEstru *aux;
		aux = lista;
		while((aux->dado != valor) && (i < contador(lista))){
			aux = aux->prox;
			i++;
		}
		if(i > contador(lista)){
			return -1;
		}else{
			return i;
		}
	}else{
		return -1;
	}
}

// Função buscaPosicao
int buscaPosicao(tipoEstru *lista, int posicao){
	if(posicao > contador(lista)){
		return -1;
	}else{
		int i;
		tipoEstru *aux;
		aux = lista;
		for(i = 1; i < posicao; i++){
			aux = aux->prox;
		}
		return aux->dado;
	}
}

// Função de Ordenação
void ordena(tipoEstru **ls, int tam){
	tipoEstru *aux;
	int *vet, i;
	vet = (int*)malloc(sizeof(int) * tam);
	aux = (*ls);
	for(i = 0; i < tam; i++){
		vet[i] = aux->dado;
		aux = aux->prox;
	}
	quickSort(vet, 0, (tam - 1));
	aux = (*ls);
	for(i = 0; i < tam; i++){
		aux->dado = vet[i];
		aux = aux->prox;
	}
}

void quickSort(int *st,int inicio, int fim){
	int meio, i, j, pivo, aux;
	
	i = inicio;
	j = fim;
	
	meio = (int)((i + j) / 2);
	pivo = st[meio];
	
	do{
		while (st[i] < pivo) i++;
		while (st[j] > pivo) j--;
		
		if(i <= j){
			aux = st[i];
			st[i] = st[j];
			st[j] = aux;
			i++;
			j--;
		}
	}while(j > i);
	
	if(inicio < j) quickSort(st, inicio, j);
	if(i < fim) quickSort(st, i, fim);
}

// Função contador
int contador(tipoEstru *lista){
	int i = 0;
	while(lista != NULL){
		i++;
		lista = lista->prox;
	}
	return i;
}

// Função imprimeLista
void imprimeLista(tipoEstru *ls){
	while(ls != NULL){
		printf("[%d]", ls->dado);
		ls = ls->prox;
	}
	printf("[NULL]\n");
}
