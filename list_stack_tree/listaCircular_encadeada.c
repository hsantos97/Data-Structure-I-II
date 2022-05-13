#include<stdio.h>
#include<stdlib.h>

struct no
{
	int valor;
	struct no *prox;
};

typedef struct no tipoNo;

void insereInicio(tipoNo **lst, int vl);
void insereFim(tipoNo **lst, int vl);
void inserePosicao(tipoNo **lst, int vl, int pos);
int removeInicio(tipoNo **lst);
int removeFim(tipoNo **lst);
int removePosicao(tipoNo **lst, int pos);
int removeNum(tipoNo **lst, int n);
void imprime(tipoNo *lst);

int main()
{
	tipoNo *no;
	
	no = NULL;
	
	//INSERINDO NO INICIO
	/*insereInicio(&no, 1);
	insereInicio(&no, 3);
	insereInicio(&no, 7);*/
	
	//INSERINDO NO FIM
	insereFim(&no, 2);
	insereFim(&no, 7);
	insereFim(&no, 5);
	insereFim(&no, 3);
	insereFim(&no, 10);
	
	//INSERE POR POSICAO
	/*inserePosicao(&no, 2, 0);
	inserePosicao(&no, 5, 1);
	inserePosicao(&no, 3, 2);
	inserePosicao(&no, 7, 3);
	inserePosicao(&no, 10, 0);
	inserePosicao(&no, 20, 2);
	inserePosicao(&no, 22, 3);*/
	
	//IMPRIMINDO LISTA
	imprime(no);
	
	//REMOVER NO INICIO
	/*removeInicio(&no);
	removeInicio(&no);*/
	
	//REMOVER NO FIM
	//removeFim(&no);
	//removeFim(&no);
	
	//REMOVE POR POSIÇÃO
	/*removePosicao(&no, 2);
	removePosicao(&no, 0);
	removePosicao(&no, 4);*/
	
	//REMOVER POR BUSCA
	removeNum(&no, 2);
	removeNum(&no, 5);
	removeNum(&no, 10);	
	
	//IMPRIMINDO LISTA
	imprime(no);
	
	
	return 1;
	
}

void insereInicio(tipoNo **lst, int vl)
{
	tipoNo *novoNo, *aux;
	
	novoNo = (tipoNo*) malloc ( sizeof (tipoNo) );
	if(novoNo == NULL)
		printf("IMPOSSIVEL ALOCAR NÓ\n");
	else
	{
		novoNo->valor = vl;
		novoNo->prox = (*lst);
	}
	
	if( (*lst) == NULL )
	{
		(*lst) = novoNo;
		novoNo->prox = (*lst);
	}
	else
	{
		aux = (*lst);
		
		while( aux->prox != (*lst) )
			aux = aux->prox;
		aux->prox = novoNo;
		novoNo->prox = (*lst);
		(*lst) = novoNo;
		
	}
}
void insereFim(tipoNo **lst, int vl)
{
	tipoNo *novoNo, *aux;

	novoNo = (tipoNo*) malloc ( sizeof (tipoNo) );
	if(novoNo == NULL)
		printf("IMPOSSIVEL ALOCAR O NÓ\n");
	else
	{
		novoNo->valor = vl;
		novoNo->prox = (*lst);
	}
	if( (*lst) == NULL )
	{
		(*lst) = novoNo;
		novoNo->prox = (*lst);
	}
	else
	{
		aux = (*lst);
		while( aux->prox != (*lst) )
			aux = aux->prox;
		aux->prox = novoNo;
		novoNo->prox = (*lst);
	}
}
void inserePosicao(tipoNo **lst, int vl, int pos)
{
	tipoNo *novoNo, *aux1, *aux2;
	int cont;
	
	cont = 0;
	
	novoNo = (tipoNo*) malloc ( sizeof(tipoNo) );
	if( novoNo == NULL )
		printf("IMPOSSIVEL ALOCAR\n");
	else
	{
		novoNo->valor = vl;
		novoNo->prox = (*lst);
	}
	if( (*lst) == NULL || pos == 0 )
		insereInicio( lst, vl );
	else
	{
		aux1 = (*lst);
		
		while( ( aux1->prox != (*lst) ) && (cont < pos) )
		{
			cont++;
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		
		if( (cont == pos) && (pos > 0) )
		{
			aux2->prox = novoNo;
			novoNo->prox = aux1;
			
		}
		else
			insereFim(lst, vl);
	}	
}

int removeInicio(tipoNo **lst)
{
	tipoNo *aux1, *aux2;
	int dado;
	
	
	if( (*lst) == NULL )
		printf("\nLISTA VAZIA\n");
	else if( (*lst) == (*lst)->prox )
	{
		aux1 = (*lst);
		dado = aux1->valor;
		free( (*lst) );
		(*lst) = NULL;
		
		return dado;
		
	}
	else
	{
		aux2 = (*lst);
		while( aux2->prox != (*lst) )
			aux2 = aux2->prox;
		aux1 = (*lst);
		dado = aux1->valor;
		(*lst) = (*lst)->prox;
		aux2->prox = (*lst);
		
		free(aux1);
		
		return dado;
	}
	
}
int removeFim(tipoNo **lst)
{
	tipoNo *aux1, *aux2;
	int dado;
	
	if( (*lst) == NULL ) 
		printf("LISTA VAZIA\n");
	else if ( (*lst) == (*lst)->prox )
	{
		aux1 = (*lst);
		dado = aux1->valor;
		free( (*lst) );
		(*lst) = NULL;
		
		return dado;
	}
	else
	{
		aux1 = (*lst);
		while( aux1->prox != (*lst) )
		{
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		dado = aux1->valor;
		aux2->prox = aux1->prox;
		free(aux1);
		
		return dado;
	}
}
int removePosicao(tipoNo **lst, int pos)
{
	tipoNo *aux1, *aux2;
	int dado, cont;
	
	cont = 0;
	
	if( (*lst) == NULL )
		printf("LISA VAZIA\n");
	else if( (*lst) == (*lst)->prox)
	{
		aux1 = (*lst);
		dado = aux1->valor;
		free( (*lst) );
		(*lst) = NULL;
		
		return dado;
	}
	else if(pos == 0)
		removeInicio(lst);
	else
	{
		aux1 = (*lst);
		
		while( ( aux1->prox != (*lst) ) && (cont < pos) )
		{
			cont++;
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		if( (cont == pos) && (pos > 0) )
		{
			dado = aux1->valor;
			aux2->prox = aux1->prox;
			free(aux1);
			
			return dado;
		}
		else
			removeFim(lst);
	}
}	
int removeNum(tipoNo **lst, int n)
{
	tipoNo *aux1, *aux2;
	int dado;
	
	if( (*lst) == NULL )
		printf("LISTA VAZIA\n");
	else if( (*lst)->valor == n )
		removeInicio(lst);
	else
	{
		aux1 = (*lst);
		
		while( (aux1->prox != (*lst)) && (aux1->valor != n) )
		{
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		if( aux1->valor == n )
		{
			dado = aux1->valor;
			aux2->prox = aux1->prox;
			free(aux1);
			
			return dado;
		}
		else
			removeFim(lst);
	}
}												
void imprime(tipoNo *lst)
{
	tipoNo *aux;	
	
	if( lst == NULL )
		printf("LISTA VAZIA\n");
	else
	{
		aux = lst;
		
		do
		{
			printf("%d\t", lst->valor);
			lst = lst->prox;
		}while ( aux != lst);
		printf("\n");
	}
}	
