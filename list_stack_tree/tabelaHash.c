#include<stdio.h>
#include<stdlib.h>
#include"listaEncadeada.c"

#define N 10

struct tabHash
{
	int qtd;
	tipoNo *tabela[N];
};

typedef struct tabhash tipoHash;

int funcaoHash(int);
void inicializaHash(tipoHash*);
void insereHash(tipoHash*, int);
void imprimeHash(tipoHash*);
int buscaHash(tipoHash*, int);

int main()
{
	tipoHash *hash;
	hash = NULL;
	
	inicializaHash( hash );
	
	insereHash(hash, 27);
	insereHash(hash, 61);
	insereHash(hash, 34);
	insereHash(hash, 5);
	
	imprimeHash( hash );
	
	return 1;
}
int funcaoHash(int chave)
{
	return ( chave % N );
}

void inicializaHash(tipoHash *hash)
{
	int i;
	
	hash->qtd = 0;
	
	for(i=0; i < N; i++)
		hash->tabela[i] = NULL;
}

void insereHash(tipoHash *hash, int k)
{
	int pos;
	
	pos = funcaoHash( k );
	
	insereFimEn(&hash->tabela[pos], k);
	hash->qtd++;
}
int buscaHash(tipoHash *hash, int k)
{
	tipoNo *aux;
	
	int pos;
	
	pos = funcaoHash( k );
	
	aux = hash->tabela[pos];
	
	while ( aux != NULL )
	{
		if( aux->valor == k )
			return 1;
		else
			aux = aux->prox;
	}
	return 0;
}
void imprimeHsh(tipoHash *hash)
{
	int i;
	
	printf("QUANTIDADE DE DADOS: %d\n", hash->qtd);
	
	for(i=0; i < N; i++)
	{
		printf("\t%d:", i);
		imprimeEn(hash->tabela[i]);
	}
	printf("\n");
}
