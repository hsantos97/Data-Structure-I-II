#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <time.h>
#include <sys/times.h> //Times Funcao
#include <sys/types.h> //Bib que define o registro TMS
#include <unistd.h> //Biblioteca necessaria para descobrir os ciclos de clock


//inclusão de biblioteca proprias
#include"parte3.c"

int main(int argc, char *argv[])
{
    	
    	FILE *arquivo;
    	int m = 100, chave;
	int colisao;
	char ltr[5];
	
	Hash *tab[m];
	inicializa(tab, m);
    	
    	arquivo = fopen ("80-arq10.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &chave) && fgets(ltr, 5, arquivo))
	{
		for(int i = 0; i < 4; i++)
			ltr[i] = ltr[i+1];
		insere(tab, m, chave, ltr);
	}
	fclose(arquivo);
	
	imprime(tab, m, &colisao);
	printf("numero de colisões: %d\n", colisao);
	
	
	return 0;
}	
