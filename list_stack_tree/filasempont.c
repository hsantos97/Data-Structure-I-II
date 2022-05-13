#include<stdio.h>
#define N 10
#include<stdlib.h>
struct fila
{
	int vet[N], quant;
};
typedef struct fila tipoFila;
int vazia(tipoFila fl);
int cheia(tipoFila fl);
tipoFila insere(tipoFila fl, int valor);
void imprime(tipoFila fl);
tipoFila remover(tipoFila fl);
int inserepont(tipoFila *fl, int valor);
void imprimepont(tipoFila *fl);
int main()
{
	tipoFila fila;
	int valor;
	fila.quant=0;
	printf("inserindo fila com ponteiro\n");
	inserepont(&fila, 10);
	inserepont(&fila, 20);
	inserepont(&fila, 30);
	inserepont(&fila, 40);
	inserepont(&fila, 50);
	printf("\ninserindo os valores\n");
	fila= insere(fila, 1);
	fila= insere(fila, 2);
	fila= insere(fila, 3);
	fila= insere(fila, 4);
	fila= insere(fila, 5);
	printf("\nimprimindo a fila\n");
	imprime(fila);
	fila=remover(fila);
	fila=remover(fila);
	fila=remover(fila);
	fila=remover(fila);
	fila=remover(fila);
	printf("removendo a fila\n");
	remover(fila);
	printf("fila removida\n");
	imprime(fila);
	return 1;
}
int vazia(tipoFila fl)
{
	if(fl.quant == 0)
		return 1;
	
	else
		return 0;
}
int cheia(tipoFila fl)
{
	if(fl.quant > N)
		return 1;
	else
		return 0;
}
void imprime(tipoFila fl)
{
	int i;
	for(i=0;i<fl.quant;i++)
		printf("%d\t", fl.vet[i]);
	printf("\n");
}
tipoFila insere(tipoFila fl, int valor)
{
	if(fl.quant < N)
	{
		fl.vet[fl.quant]=valor;
		fl.quant++;
		return fl;
	}
	else	
		return fl;
}
tipoFila remover(tipoFila fl)
{
	int i, valor;
	if(fl.quant > 0)
	{
		valor=fl.vet[0];
		for(i=0;i<fl.quant;i++)
			fl.vet[i]=fl.vet[i+1];
	}
	fl.quant--;
	return fl;
}
int inserepont(tipoFila *fl, int valor)
{
	if(!cheia(*fl))
	{
		fl->vet[fl->quant++]=valor;
		return 1;
	}
	else 
		return 0;
}
void imprimepont(tipoFila *fl)
{
	int i;
	if(!vazia(*fl))
	{
		for(i=0;i<fl->quant;i++)
			printf("%d\t", fl->vet[i]);
		printf("\n");
	}
	else
		printf("FILA VAZIA\n");
}
