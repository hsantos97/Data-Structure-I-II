#include<stdio.h>
#include<stdlib.h>

struct lista
{
	int valor;
	struct lista *prox;
	struct lista *ant;
};

typedef struct lista tipoNo;

tipoNo *alocaNo(int vl);
void insereInicio(tipoNo **lst, int vl);
void insereFim(tipoNo **lst, int vl);
void inserePosicao(tipoNo **lst, int vl, int pos);
int removeInicio(tipoNo **lst);
int removeFim(tipoNo **lst);
int removePosicao(tipoNo **lst, int pos);
int removeBusca(tipoNo **lst, int n);
void imprime(tipoNo *lst);

int main()
{
	tipoNo *no;
	
	no = NULL;
	
	//INSERIR NO INICIO DA LISTA
	/*insereInicio(&no, 1);
	insereInicio(&no, 3);
	insereInicio(&no, 2);
	insereInicio(&no, 7);
	insereInicio(&no, 9);*/
	
	//INSERINDO NO FIM DA LISTA 
	insereFim(&no, 1);
	insereFim(&no, 9);
	insereFim(&no, 3);
	insereFim(&no, 7);
	insereFim(&no, 4);
	
	//INSERINDO NA POSIÇÃO
	//inserePosicao(&no, 2, 0);
	//inserePosicao(&no, 15, 2);
	//inserePosicao(&no, 50, 7);
	
	//IMPRIMINDO OS VALORES NA LISTA
	imprime(no);
	
	//REMOVENDO NO INICIO
	//removeInicio(&no);
	//removeInicio(&no);
	
	//REMOVENDO NO FIM
	//removeFim(&no);
	//removeFim(&no);
	
	//REMOVE POR POSIÇÃO
	//removePosicao(&no, 4);
	//removePosicao(&no, 1);
	//removePosicao(&no, 0);
	
	//REMOVE POR BUSCA
	removeBusca(&no, 1);
	removeBusca(&no, 3);
	removeBusca(&no, 4);
	
	//IMPRIMINDO OS REMOVIDOS DA LISTA
	imprime(no);
	
	return 1;
}

tipoNo *alocaNo(int vl)
{
	tipoNo *novoNo;
	
	novoNo = (tipoNo*) malloc ( sizeof(tipoNo) );
	if(novoNo == NULL)
		printf("NÃO FOI POSSIVEL ALOCAR NÓ\n");
	else
	{
		novoNo->valor = vl;
		novoNo->prox = novoNo;
		novoNo->ant = novoNo;
		
		return novoNo;
	}
}
void insereInicio(tipoNo **lst, int vl)
{
	tipoNo *novoNo, *aux;
	
	if( (*lst) == NULL )
		(*lst) = alocaNo(vl);
	else
	{	
		aux = (*lst);
		novoNo = alocaNo(vl);
		aux->ant->prox = novoNo;
		novoNo->ant = aux->ant;
		novoNo->prox = aux;
		aux->ant = novoNo;
		(*lst) = novoNo;
	}
}
void insereFim(tipoNo **lst, int vl)
{
	tipoNo *novoNo, *aux;
	
	if( (*lst) == NULL )
		insereInicio(lst, vl);
	else
	{
		aux = (*lst);
		novoNo = alocaNo(vl);
		novoNo->ant = aux->ant;
		aux->ant->prox = novoNo;
		novoNo->prox = aux;
		aux->ant = novoNo;
	}
}
void inserePosicao(tipoNo **lst, int vl, int pos)
{
	tipoNo *novoNo, *aux1, *aux2;
	int cont = 0;
	
	if( (*lst) == NULL || pos == 0 )
		insereInicio(lst, vl);
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
			novoNo = alocaNo(vl);
			aux2->prox = novoNo;
			novoNo->ant = aux2;
			novoNo->prox = aux1;
			aux1->ant = novoNo;
		}
		else
			insereFim(lst, vl);
	}
}
int removeInicio(tipoNo **lst)
{
	tipoNo *aux;
	int dado;
	
	if( (*lst) == NULL )
		printf("LISTA VAZIA\n");
	else if( (*lst)->prox == (*lst) )
	{
		dado = (*lst)->valor;
		free( (*lst) );
		(*lst) = NULL;
		
		return dado;
	}
	else
	{
		aux = (*lst);
		dado = aux->valor;
		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		(*lst) = (*lst)->prox;
		free( aux );
		
		return dado;
	}
}
int removeFim(tipoNo **lst)
{
	tipoNo *aux;
	int dado;
	
	if( (*lst) == NULL)
		printf("LISTA VAZIAZ\n");
	else if( (*lst)->prox == (*lst) )
	{
		dado = (*lst)->valor;
		free( (*lst) );
		(*lst) = NULL;
	}
	else
	{
		aux = (*lst);
		
		while( aux->prox != (*lst) )
			aux = aux->prox;
		dado = aux->valor;
		aux->ant->prox = (*lst);
		(*lst)->ant = aux->ant;
		free( aux );
		
		return dado;
	}
}
int removePosicao(tipoNo **lst, int pos)
{
	tipoNo *aux1, *aux2;
	int cont = 0, dado;
	
	if( (*lst) == NULL )
		printf("LISTA VAZIIA\n");
	else
	{
		aux1 = (*lst);
		
		while( ( aux1->prox != (*lst) ) && ( cont < pos) )
		{
			cont++;
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		if( cont == 0 )
			removeInicio(lst);
		else if( (cont == pos) && (pos > 0) )
		{
			dado = aux1->valor;
			aux2->prox = aux1->prox;
			aux1->prox->ant = aux2;
			free( aux1 );
			
			return dado;
		}
		else
			removeFim(lst);
	}
}
int removeBusca(tipoNo **lst, int n)
{
	tipoNo *aux;
	int dado, cont = 0;
	
	if( (*lst) == NULL )
		printf("LISTA VAZIIA\n");
	else
	{
		aux = (*lst);
		while( ( aux->prox != (*lst) ) && (aux->valor != n) )
		{
			cont++;
			aux = aux->prox;
		}
		if( cont == 0 )
			removeInicio(lst);
		else if( aux->prox == (*lst) )
			removeFim(lst);
		else
			removePosicao(lst, cont);
	}
}	 			
void imprime(tipoNo *lst)
{
	tipoNo *aux;
	if( lst == NULL )
		printf("lista vazia\n");
	else
	{
		aux = lst;
		do
		{
			printf("%d\t", aux->valor);
			aux = aux->prox;
		}while( aux->prox != lst );
		printf("%d\t", aux->valor);
		printf("\n");
	}
}
