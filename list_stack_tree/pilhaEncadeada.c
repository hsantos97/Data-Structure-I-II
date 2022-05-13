#include<stdio.h>
#include<stdlib.h>

struct est_pilha
{
	int dado;
	struct est_pilha *prox;
};

typedef struct est_pilha tipoNo;

void empilha(tipoNo **pilha, int vl);
int desempilha(tipoNo **pilha);
tipoNo *copiaPilha(tipoNo *pilha);
void imprime(tipoNo *pilha);

int main()
{
	tipoNo *p, *cop;
	p = cop = NULL;
	
	empilha(&p, 1);
	empilha(&p, 3);
	empilha(&p, 9);
	empilha(&p, 7);
	empilha(&p, 4);
	empilha(&p, 2);
	
	printf("PILHA\n");
	imprime(p);
	
	/*desempilha(&p);
	desempilha(&p);
	desempilha(&p);*/
	
	cop = copiaPilha(p);
	
	printf("\nCOPIA\n");
	imprime(cop);

	return 1;
}
void empilha(tipoNo **pilha, int vl)
{
	tipoNo *topo, *novoNo;

	novoNo = (tipoNo*) malloc ( sizeof (tipoNo) );
	if(novoNo == NULL)
		printf("IMPOSSIVEL ALOCAR NÓ\n");
	else
	{
		novoNo->dado = vl;
		novoNo->prox = NULL;
	}
	if( (*pilha) == NULL )
		(*pilha) = novoNo;
	else
	{
		topo = (*pilha);
		
		while( topo->prox != NULL )
			topo = topo->prox;
		topo->prox = novoNo;
	}
}
int desempilha(tipoNo **pilha)
{
	tipoNo *topo, *aux;
	int valor;
	
	if( (*pilha) == NULL )
	{
		printf("PILHA VAZIA\n");
		return -1;
	}
	else if( (*pilha)->prox == NULL )
	{
		valor = (*pilha)->dado;
		free( (*pilha) );
		(*pilha) = NULL;
		return valor;
	}
	else
	{
		topo = (*pilha);
		
		while( topo->prox != NULL)
		{
			aux = topo;
			topo = topo->prox;
		}
		valor = topo->dado;
		free( topo );
		aux->prox = NULL;
		return valor;
	}
	
}
tipoNo *copiaPilha(tipoNo *pilha)
{
	tipoNo *aux, *cop;	
	aux = cop = NULL;
	int valor;'

	valor = desempilha(&pilha);
	do
	{
		empilha(&aux, valor);
		valor = desempilha(&pilha);
	} while( valor != -1);
	
	
	valor = desempilha(&aux);
	do
	{
		empilha(&cop, valor);
		empilha(&pilha, valor);
		valor = desempilha(&aux);
	} while ( valor != -1);
		
	return cop;
}
void imprime(tipoNo *pilha)
{
	tipoNo *aux;
	
	if( pilha == NULL )
		printf("PILHA VAZIA\n");
	else
	{
		aux = pilha;
		while( aux->prox != NULL )
		{
			printf("%d\t", aux->dado);
			aux = aux->prox;
		}
		printf("%d\t", aux->dado);
		printf("\n");
	}
}		
