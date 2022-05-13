#include<stdio.h>
#define TAM 5
struct lista
{
	int quant;
	int vet[TAM];
};
typedef struct lista tipoLista;
tipoLista insere(tipoLista lst, int pos, int valor);
void imprime(tipoLista lst);
int main()
{
	tipoLista tl;
	tl.quant=TAM;
	tl=insere(tl, 0, 1);
	tl=insere(tl, 1, 2);
	tl=insere(tl, 2, 3);
	tl=insere(tl, 3, 4);
	tl=insere(tl, 4, 5);
	printf("\nIMPRIMINDO A LISTA\n");
	imprime(tl);
	return 1;
}
tipoLista insere(tipoLista lst, int pos, int valor)
{
	int i;
	if(lst.quant < TAM)
	{
		if(pos >= 0 && pos < TAM && pos <= lst.quant)
		{
			for(i=lst.quant; i<pos; i--)
				lst.vet[i]=lst.vet[i-1];
			lst.vet[pos]=valor;
			lst.quant++;
			return lst;
		}
	}
}		
void imprime(tipoLista lst)
{
	int i;
	if(lst.quant > 0)
	{
		for(i=0;i<lst.quant;i++)
			printf("%d\t", lst.vet[i]);
	}
}
