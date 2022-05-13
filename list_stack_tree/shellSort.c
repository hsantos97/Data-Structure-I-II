#include<stdio.h>
#include<stdlib.h>
struct pilha
{
	int *vet;
	int topo;
	int tam;
};

typedef struct pilha tipoPilha;

void inicia(tipoPilha *p, int tamanho);
void insere(tipoPilha *p);
void imprime(tipoPilha *p);
int cheia(tipoPilha *p);
int vazia(tipoPilha *p);
void shellSort(tipoPilha *P);

int main()
{
	tipoPilha pilha;
	
	int tam;

	printf("INFORME O TAMANHO DA PILHA\n");
	scanf("%d", &tam);
	
	inicia(&pilha, tam);
	
	printf("INSERINDO A PILHA\n");
	insere(&pilha);
	
	printf("IMPRIMINDO PILHA\n");
	imprime(&pilha);
	printf("\n");
	
	printf("ORDENANDO A PILHA\n");
	shellSort(&pilha);
	
	printf("IMPRIMINDO PILHA ORDENADA\n");
	imprime(&pilha);
	printf("\n");
	
	return 1;
}
void inicia(tipoPilha *p, int tamanho)
{
	p->vet=(int*) malloc( sizeof(int)*tamanho );
	if(p->vet == NULL)
		printf("impossivel alocar\n");
	else
	{
		p->topo = -1;
		p->tam = tamanho;
	}
}
int cheia(tipoPilha *p)
{
	if(p->topo == p->tam)
		return 1;
	else
		return 0;
}
int vazia(tipoPilha *p)
{
	if(p->topo == -1)
		return 1;
	else
		return 0;
}
void insere(tipoPilha *p)
{
	int i;
	
	if(cheia(p))
		printf("PILHA CHEIA\n");
	else
	{	
		for(i=0; i < p->tam; i++)
		{
			p->topo++;
			printf("[%d]", i);
			scanf("%d", &p->vet[i]);	
		}
	}
}
void imprime(tipoPilha *p)
{
	int i;
	
	if( vazia(p) )
		printf("PILHA VAZIA\n");
	else
	{	
		for(i=0; i <= p->topo; i++)
			printf("%d\t", p->vet[i]);
	}
}
void shellSort(tipoPilha *p)
{
	int i, salto, frente, tras, aux;
	
	salto = p->tam/2;
	
	while(salto > 0 )
	{
		for(i=salto; i < p->tam; i++)
		{
			tras= i-salto;
			
			while( tras >= 0)
			{
				frente= tras+salto;
				
				if(p->vet[tras] < p->vet[frente])
					tras= -1;
				else
				{
					aux = p->vet[tras];
					p->vet[tras] = p->vet[frente];
					p->vet[frente] = aux;
					tras = tras - salto;
 				}
 			}
 		}
 		salto = salto/2;
 	}
}
	
