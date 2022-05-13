#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef trabArv_c
#define trabArv_c

struct arvore
{
	char caracter;
	char letra;
	struct arvore *esq;
	struct arvore *dir;
};

typedef struct arvore tipoArv;

void alocaNo(tipoArv **arv)
{
	tipoArv *novoNo;
	
	novoNo = (tipoArv*) malloc ( sizeof (tipoArv) );
	
	if( novoNo == NULL )
		printf("IMPOSSIVEL ALOCAR \n");
	else
	{
		novoNo->caracter = ' ';
		novoNo->letra = ' ';
		novoNo->esq = NULL;
		novoNo->dir = NULL;
		
		(*arv) = novoNo;
	}
}
void insereNo(tipoArv **arv, char *carac, char let, int tamVet)
{
	tipoArv *aux;
	int i;
	
	if( (*arv) == NULL )
		alocaNo( &(*arv) );
	if( carac[0] == '.' && (*arv)->esq != NULL )
		aux = (*arv)->esq;
	else if( carac[0] == '.' && (*arv)->esq == NULL )
	{
		alocaNo( &(*arv)->esq );
		aux = (*arv)->esq;
		aux->caracter = '.';
	}	
	else if( carac[0] == '-' && (*arv)->dir != NULL )
		aux = (*arv)->dir;
	else if( carac[0] == '-' && (*arv)->dir == NULL )
	{
		alocaNo( &(*arv)->dir );
		aux = (*arv)->dir;
		aux->caracter = '-';
	}
	
	
	for(i=1; i < tamVet; i++)
	{
		if( carac[i] == '.' && aux->esq != NULL )
			aux = aux->esq;
		else if( carac[i] == '.' && aux->esq == NULL )
		{
			alocaNo( &aux->esq );
			aux = aux->esq;
			aux->caracter = carac[i];
		}
		if ( carac[i] == '-' && aux->dir != NULL )
			aux = aux->dir;
		else if( carac[i] == '-' && aux->dir == NULL )
		{
			alocaNo( &aux->dir );
			aux = aux->dir;
			aux->caracter = carac[i];
		}
	}
	aux->letra = let;
}
void imprimePreOrdem(tipoArv *arv)
{
	int i;
	
	if( arv != NULL )
	{

		printf("[%c][%c]\n", arv->caracter, arv->letra);
		imprimePreOrdem(arv->esq);
		imprimePreOrdem(arv->dir);
	}
}
void traducao(tipoArv *arv, char *carac, int tamVet)
{

	tipoArv *aux;
	int i;
	
	if( carac[0] == '.' && arv->esq != NULL )
		aux = arv->esq;
	else if( carac[0] == '.' && arv->esq == NULL )
	{
		aux = arv->esq;
		aux->caracter = '.';
	}	
	else if( carac[0] == '-' && arv->dir != NULL )
		aux = arv->dir;
	else if( carac[0] == '-' && arv->dir == NULL )
	{
		aux = arv->dir;
		aux->caracter = '-';
	}
	
	
	for(i=1; i < tamVet; i++)
	{
		if( carac[i] == '.' && aux->esq != NULL )
			aux = aux->esq;
		else if( carac[i] == '.' && aux->esq == NULL )
		{
			aux = aux->esq;
			aux->caracter = carac[i];
		}
		if ( carac[i] == '-' && aux->dir != NULL )
			aux = aux->dir;
		else if( carac[i] == '-' && aux->dir == NULL )
		{
			aux = aux->dir;
			aux->caracter = carac[i];
		}
	}
	printf("%c", aux->letra);
	
}				
#endif
