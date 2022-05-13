#include<stdio.h>
#include<stdlib.h>
struct fila
{
	int *vet;
	int qtdDados;
	int tam;
};

typedef struct fila tipoFila;

void inicia(tipoFila *fl, int tamanho);
int cheia(tipoFila *fl);
int vazia(tipoFila *fl);
void insere(tipoFila *fl);
void imprime(tipoFila *fl);
void mergeSort(tipoFila *fl, int tamanho);

int main()
{
	tipoFila fila;
	int tam;

	printf("INFORME O TAMANHO DO VETOR\n");
	scanf("%d", &tam);
	
	inicia(&fila, tam);
	
	printf("INSERINDO FILA\n");
	insere(&fila);
	
	printf("IMPRIMINDO FILA\n");
	imprime(&fila);
	printf("\n");
	
	printf("ORDENANDO A FILA\n");
	mergeSort(&fila, tam);
	
	printf("IMPRIMINDO O VETOR ORDENADO\n");
	imprime(&fila);
	printf("\n");
	
	return 1;
}
void inicia(tipoFila *fl, int tamanho)
{
	fl->vet = (int*) malloc( sizeof(int)*tamanho );
	if(fl->vet == NULL)
		printf("IMPOSSIVEL ALOCAR O VETOR\n");
	else
	{
		fl->qtdDados = -1;
		fl->tam = tamanho;
	}
}
int cheia(tipoFila *fl)
{
	if(fl->qtdDados == fl->tam)
		return 1;
	else
		return 0;
}
int vazia(tipoFila *fl)
{
	if(fl->qtdDados == -1)
		return 1;
	else
		return 0;
}
void insere(tipoFila *fl)
{
	int i;
	
	for(i=0; i < fl->tam; i++)
	{
		fl->qtdDados++;
		printf("[%d]", i);
		scanf("%d", &fl->vet[i]);
	}
}
void imprime(tipoFila *fl)
{
	int i;
	
	for(i=0; i <= fl->qtdDados; i++)
		printf("%d\t", fl->vet[i]);
}
void mergeSort(tipoFila *fl, int tamanho)
{
	int i, meio, dir, esq, aux[tamanho], k;
	
	for(i=0; i < tamanho; i++)
		aux[i]=fl->vet[i];
	
	esq = 0;
	meio = tamanho/2;
	dir = meio+1;
	k = 0;
	
	while(esq <= meio && dir<=tamanho)
	{
		if(aux[esq] < aux[dir])
		{
			fl->vet[k] = aux[esq];
			esq++;
		}
		else
		{
			fl->vet[k] = aux[dir];
			dir++;
		}
		k++;
	}
	while(esq <= meio)
	{
		fl->vet[k] = aux[esq];
		k++;
		esq++;
	}
}
