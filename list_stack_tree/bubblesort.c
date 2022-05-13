#include<stdio.h>
#include<stdlib.h>

struct lista
{
	int *vet;
	int frente, tras;
	int tam;
};
typedef struct lista tipoLista;

void inicializa(tipoLista *lst, int tamanho);
void inserefim(tipoLista *lst);
void imprime(tipoLista *lst);
int vazio(tipoLista *lst);
int cheia(tipoLista *lst);
void bubbleSort(tipoLista *lst);

int main()
{
	tipoLista lista;
	
	int tam;
	
	printf("informe o tamanho do vetor\n");
	scanf("%d", &tam);
	
	inicializa(&lista, tam);
	
	inserefim(&lista);
	
	printf("\nIMPRIMINDO A LISTA\n");
	imprime(&lista);
	printf("\n");
	
	printf("ORDENANDO\n");
	bubbleSort(&lista);
	printf("\n");
	
	printf("IMPRIMINDO LISTA ORDENADA\n");
	imprime(&lista);
	printf("\n");
	
	return 1;
}
void inicializa(tipoLista *lst, int tamanho)
{
	lst->vet=(int*) malloc( tamanho*sizeof(int) );
	if(lst->vet == NULL)
		printf("IMPOSSIVEL ALOCAR\n");
	else
	{
		lst->frente = 0;
		lst->tras = -1;
		lst->tam = tamanho;
	}
}
int vazio(tipoLista *lst)
{
	if(lst->tras == -1)
		return 1;
	else
		return 0;
}
int cheia(tipoLista *lst)
{
	if(lst->tras == lst->tam)
		return 1;
	else
		return 0;
}
void inserefim(tipoLista *lst)
{
	int i, valor;
	
	if(cheia(lst))
		printf("LISTA CHEIA\n");
	else
	{
		for(i=0; i < lst->tam; i++)
		{
			printf("[%d]", i);
			scanf("%d", &valor);
			lst->tras++;
			lst->vet[lst->tras]=valor;
		}
	}
}
void imprime(tipoLista *lst)
{
	int i;
	
	if(vazio(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(i = 0; i <= lst->tras; i++)
			printf("%d\t", lst->vet[i]);
	}
}
void bubbleSort(tipoLista *lst)
{
	int i, contador, aux;
	
	if(vazio(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(contador=1; contador <= lst->tras; contador++)
		{
			for(i=0; i <= lst->tras-1; i++)
			{
				if(lst->vet[i] > lst->vet[i+1])
				{
					aux=lst->vet[i];
					lst->vet[i]=lst->vet[i+1];
					lst->vet[i+1]=aux;
				}
			}
		}
	}
}
