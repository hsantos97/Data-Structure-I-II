#ifndef tabHash_c
#define tabHash_c 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aleatorio
{
	int chave;
	char let[4];
	
	struct aluno *prox;
}ale;

typedef ale* Hash;

int hash(int chav, int tam)
{
	return chav % tam;
}
int hashMult(int chav, int tam)
{
	float w = 64, a = 19; //w- numero de palavras do computador a - numero primo
	
	int h = chav * (a/w);
	
	if(h >= tam) // valor da hash maior que o tamanho da tabela, ir pra ultima posição
		return tam -1;
	else
		return h;
}	
void inicializa(Hash *tab, int m)
{
	int i;
	
	for(i = 0; i < m; i++)
		tab[i] = NULL;
}
ale* aloca(int chav, char *vet )
{
	ale *novo = (ale*) malloc(sizeof(ale));
	novo->chave = chav;
	strcpy(novo->let, vet);
	novo->prox = NULL;
	return novo;
}
void insere(Hash *tab, int m, int chav, char *vet)
{
	int h = hash(chav, m);
	
	ale *p = tab[h];
	ale *ant = NULL;
	
	while((p != NULL) && (p->chave != chav))
	{
		ant = p;
		p = p->prox;
	}
	
	if(p)
	{
		strcpy(p->let, vet);
		return;
	}
	
	ale *novo = aloca(chav, vet);
	
	if(!ant)
		tab[h] = novo;
	else
		ant->prox = novo;
	
}
void imprime(Hash *tab, int m, int *colisao)
{
	int i, coli = 0;
	
	for(i = 0; i < m; i++)
	{
		printf("%d", i);
		if(tab[i])
		{
			ale *p = tab[i];
			printf("\n");
			while(p)
			{
				if(p->prox != NULL)
					coli += 1;
				printf("\t%d\t%s\t%p\n", p->chave, p->let, p->prox);
				p = p->prox;
			}
		}
		else
			printf("\n\tNULL\n");
		
	}
	*colisao = coli;
}
ale* busca(Hash *tab, int m, int chav)
{
	int h = hash(chav, m);
	
	ale *p = tab[h];
	
	while((p) && (p->chave != chav))
		p = p->prox;
	
	return p;
}
void excluir(Hash *tab, int m, int chav)
{
	int h = hash(chav, m);
	
	if(tab[h] == NULL)
		return;
	
	ale *p = tab[h];
	ale *ant = NULL;
	
	while((p != NULL) && (p->chave != chav))
	{
		ant = p;
		p = p->prox;
	}
	
	if(p == NULL)
	{
		printf("Chave não encontrada\n");
		return;
	}
	
	if( ant == NULL)
		tab[h] = p->prox;
	else
		ant->prox = p->prox;
	
	free(p);

}
void libera(Hash *tab, int m)
{
	int i;
	
	for(i = 0; i < m; i++)
	{
		if(tab[i])
		{
			ale *p = tab[i];
			ale *q;
			
			while(p)
			{
				q = p;
				p = p->prox;
				free(q);
			}
		}
	}				
}			
/* int main()
{
	int m = 5;
	int colisao;
	
	Hash *tab[m];
	inicializa(tab, m);
	
	insere(tab, m, 5, "KLA");
	insere(tab, m, 6, "ASD");
	insere(tab, m, 7, "AZX");
	insere(tab, m, 5, "CVB");
	insere(tab, m, 8, "FGB");
	insere(tab, m, 9, "QWE");
	insere(tab, m, 10, "CXZ");
	insere(tab, m, 11, "LKL");
	insere(tab, m, 16, "ASZ");
	insere(tab, m, 17, "GBV");
	insere(tab, m, 18, "PLM");
	insere(tab, m, 19, "MMF");
		
	imprime(tab, m, &colisao);
	
	ale *p = busca(tab, m, 11);
	if(!p)
		printf("Chave não encontrada\n");
	else
		printf("Chave:%d\tletras:%s\n", p->chave, p->let);
	
	printf("---------------------------\n");
		
	excluir(tab, m, 11);
	
	imprime(tab, m, &colisao);
	
	printf("número de colisões: %d\n", colisao); 
	
	libera(tab, m);
		
	return 0;
	
	
} */

#endif
