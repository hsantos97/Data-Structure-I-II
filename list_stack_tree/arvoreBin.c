#include<stdio.h>
#include<stdlib.h>

struct arvore
{
	int dado;
	struct arvore *esq;
	struct arvore *dir;
};

typedef struct arvore tipoArv;

tipoArv *alocaNo(int valor)
{
	tipoArv *novoNo;
	novoNo = (tipoArv*) malloc ( sizeof (tipoArv) );

	if(novoNo == NULL)
		printf("IMPOSSIVEL ALOCAR NÓ\n");
	else
	{
		novoNo->dado = valor;
		novoNo->esq = NULL;
		novoNo->dir = NULL;
		
		return novoNo;
	}		
}
void insereNo(tipoArv **arv, int vl)
{
	
	if( (*arv) == NULL )
		(*arv) = alocaNo(vl);
	else
	{
		if( vl > (*arv)->dado )
			insereNo( &(*arv)->dir, vl);
		else
			insereNo( &(*arv)->esq, vl);
	}
}
void imprimePre(tipoArv *arv)
{
	if( arv != NULL )
	{
		printf("%d\t", arv->dado);
		imprimePre(arv->esq);
		imprimePre(arv->dir);
	}	
}
void imprimeOrdem(tipoArv *arv)
{
	if ( arv != NULL)
	{
		imprimeOrdem(arv->esq);
		printf("%d\t", arv->dado);
		imprimeOrdem(arv->dir);
	}
}
void imprimePos(tipoArv *arv)
{
	if ( arv != NULL)
	{
		imprimeOrdem(arv->esq);
		imprimeOrdem(arv->dir);
		printf("%d\t", arv->dado);
	}
}
void imprimeNivel(tipoArv *arv, int cont)
{
	if( arv!= NULL )
	{
		if( cont == 0 )
			printf("%d\t", arv->dado);
		else
		{
			if(cont > 0 )
			{
				imprimeNivel(arv->esq, cont-1);
				imprimeNivel(arv->dir, cont-1);
			}
		}
	}
}
void imprimeFolhas(tipoArv *arv)
{
	if( arv != NULL )
	{
		if( (arv->esq == NULL) && (arv->dir == NULL) )
			printf("%d\t", arv->dado);
		imprimeFolhas(arv->esq);
		imprimeFolhas(arv->dir);
	}
	
}
int alturaArv(tipoArv *arv)
{
	int hdir, hesq;
	if( arv != NULL )
	{
		if( (arv->esq == NULL) && (arv->dir == NULL) )
			return 0;
		else
		{
			hesq = alturaArv(arv->esq);
			hdir = alturaArv(arv->dir);
		}
		if( hesq > hdir )
			return hesq +1;
		else
			return hdir+1;
	}
	else
		return -1;
}
void maiorValor(tipoArv *arv)
{
	if( arv != NULL )
	{
		if( arv->dir != NULL )
			maiorValor(arv->dir);
		else
			printf("maior valor: %d\n", arv->dado);
	}
}
tipoArv *menorValor(tipoArv *arv)
{
	if( arv != NULL )
	{
		if ( arv->esq != NULL )
			menorValor(arv->esq);
		else
		{
			printf("menor valor: %d\n", arv->dado);
			return arv;
		}
	}
	else
		return NULL;
}
int buscaValor(tipoArv *arv, int vl)
{
	
	if( arv != NULL )
	{
		if( vl == arv->dado )
		{
			printf("VALOR ENCONTRADO: %d\n", arv->dado);
			return 1;
		}
		else
		{
			if( vl < arv->dado)
				buscaValor(arv->esq, vl);
			else
				buscaValor(arv->dir, vl);
		}
		
	}
	else
	{
		printf("VALOR NÃO ENCONTRADO\n");
		return 0;
	}
}
tipoArv *removeVL(tipoArv *arv, int vl)
{
	tipoArv *aux;
	
	if( arv != NULL )
	{
		if(vl < arv->dado )
			arv->esq = removeVL( arv->esq, vl);
		else if (vl > arv->dado )
			arv->dir = removeVL( arv->dir, vl);
		else
		{
			if( arv->esq == NULL && arv->dir == NULL )
			{
				free( arv );
				return NULL;
			}
			else if ( arv->esq == NULL && arv->dir != NULL )
			{	
				aux = arv->dir;
				free(arv);
				return aux;
			}
			else if (arv->dir == NULL && arv->esq != NULL )
			{
				aux = arv->esq;
				free(arv);
				return aux;
			}
			else
			{	
				int menor;
				aux = menorValor(arv->dir);
				menor = aux->dado;
				arv = removeVL(arv, menor);
				arv->dado = menor;
				return arv;
			}				
		}
	}
	else
	{
		printf("VALOR NÃO ENCONTRADO\n");
		return arv;
	}
}			
int main()
{
	tipoArv *arvo;
	arvo = NULL;
	
	insereNo(&arvo, 1);
	insereNo(&arvo, 7);
	insereNo(&arvo, 3);
	insereNo(&arvo, 2);
	insereNo(&arvo, 11);
	insereNo(&arvo, 5);
	insereNo(&arvo, 0);
	insereNo(&arvo, -1);
	
	imprimeOrdem(arvo);
	
	printf("\nIMPRIMINDO OS NÓS DO NÍVEL:\n");
	imprimeNivel(arvo, 2);
	printf("\n");
	
	printf("IMPRIMINDO AS FOLHAS DA ÁRVORE\n");
	imprimeFolhas(arvo);
	printf("\n");
	
	printf("ALTURA DA ARVORE: %d\n", alturaArv(arvo));
	
	maiorValor(arvo);
	menorValor(arvo);
	
	buscaValor(arvo, 11);
	
	removeVL(arvo, 1);
	printf("IMPRIMINDO DEPOIS DA REMOÇÃO:\n");
	imprimeOrdem(arvo);
	printf("\n");
	
	return 1;
}
