#include<stdio.h>
#define TAM 5
struct pilha
{
	int vet[TAM];
	int topo;
};
typedef struct pilha tipoPilha;
void inicia(tipoPilha *p);
int vazia(tipoPilha *p);
int cheia(tipoPilha *p);
void insere(tipoPilha *p, int valor);
void imprime(tipoPilha *p);
int desempilha(tipoPilha *p);
int main()
{
	tipoPilha pilha;
	int aux; // variavel para receber os valores do desempilha
	inicia(&pilha);
	insere(&pilha, 1);
	insere(&pilha, 2);
	insere(&pilha, 3);
	insere(&pilha, 4);
	insere(&pilha, 5);
	printf("\nIMPRIMINDO A PILHA\n");
	imprime(&pilha);
	printf("\nDESEMPILHANDO\n");
	aux=desempilha(&pilha);
	aux=desempilha(&pilha);
	aux=desempilha(&pilha);
	printf("\nIMPRIMINDO A PILHA DESEMPILHADA\n");
	imprime(&pilha);
	printf("\n");
	return 1;
}
void inicia(tipoPilha *p)
{
	p->topo= -1;
}
int vazia(tipoPilha *p)
{
	if(p->topo == -1)
		return 1;
	else
		return 0;
}
int cheia(tipoPilha *p)
{
	if(p->topo == TAM -1)
		return 1;
	else
		return 0;
}
void insere(tipoPilha *p, int valor)
{
	if(cheia(p) == 1)
		printf("ERRO PILHA CHEIA\n");
	else
	{
		p->topo++;
		p->vet[p->topo]=valor;
	}
}
void imprime(tipoPilha *p)
{
	int i;
	if(vazia(p))
		printf("\nPILHA VAZIA\n");
	else
	{
		
		for(i=0;i < p->topo+1; i++)
			printf("%d\t", p->vet[i]);
	}
}
int desempilha(tipoPilha *p)
{
	int aux;
	if(vazia(p) == 1)
		printf("\nPILHA VAZIA\n");
	else
	{
		aux=p->vet[p->topo];
		p->topo--;
		return aux;
	}
}
