#include<stdio.h>
#include<stdlib.h>

struct fila
{
	int valor;
	struct fila *prox;
};

typedef struct fila tipoFila;

void insereFila(tipoFila **fl, int vl);
int removeFila(tipoFila **fl);
void imprime(tipoFila *fl);

int main()
{
	tipoFila *fila;	

	fila = NULL;
	
	printf("INSERINDO NA FILA\n");
	insereFila(&fila, 1);
	insereFila(&fila, 15);
	insereFila(&fila, 7);
	insereFila(&fila, 5);
	insereFila(&fila, 2);
	
	imprime(fila);
	
	printf("REMOVENDO DA FILA\n");
	removeFila(&fila);
	removeFila(&fila);
	
	imprime(fila);
	
	
	return 1;
}

void insereFila(tipoFila **fl, int vl)
{
	tipoFila *aux, *novoNo;
	
	novoNo = (tipoFila*) malloc ( sizeof(tipoFila) );
	if( novoNo == NULL )
		printf("IMPOSSIVEL ALOCAR\n");
	else
	{
		novoNo->valor = vl;
		novoNo->prox = NULL;
	}
	
	if( (*fl) == NULL )
		(*fl) = novoNo;
	else
	{
		aux = (*fl);
		
		while ( aux->prox != NULL )
			aux = aux->prox;
		aux->prox = novoNo;
	}
}
int removeFila(tipoFila **fl)
{
	tipoFila *aux;
	int dado;
	
	if( (*fl) == NULL )
	{
		printf("FILA VAZIA\n");
		return -1;
	}
	else if( (*fl)->prox == NULL )
	{
		dado = (*fl)->valor;
		free( (*fl) );
		(*fl) = NULL;
		return dado;
	}
	else
	{
		aux = (*fl);
		dado = aux->valor;
		(*fl) = (*fl)->prox;
		free ( aux );
		
		return dado;
	}
}
void imprime(tipoFila *fl)
{
	if( fl == NULL )
		printf("FILA VAZIA\n");
	else
	{
		while( fl->prox != NULL )
		{
			printf("%d\t", fl->valor);
			fl = fl->prox;
		}
		printf("%d\t", fl->valor);
		printf("\n");
	}
}
