#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <time.h>
#include <sys/times.h> //Times Funcao
#include <sys/types.h> //Bib que define o registro TMS
#include <unistd.h> //Biblioteca necessaria para descobrir os ciclos de clock


//inclusão de biblioteca proprias
#include"listaestatica.c"
#include"listaEncadeada.c"
#include"listaDuplamente_encadeada.c"

int main(int argc, char *argv[])
{
	clock_t tt;
	//Variaveis para contagem do tempo
	struct tms time; //Estrutura que ira guardar os dados a respeito do tempo de execucao do programa
  	//clock_t clock;
    	int tics_per_second; //Variavel que irah guardar os ciclos de clock por segundo do sistema
    	//Pergunta ao SO sobre os ciclos de clock
    	tics_per_second = sysconf(_SC_CLK_TCK);
    	
    	int num;
    	tipoLista lista;
	tipoNo *no;
	tipoNoo *noo;
    	FILE *arquivo;

	no = NULL;
	noo = NULL;
    	
    /*	inicializaLista(&lista, 10000);
		
	arquivo = fopen ("3333-arq2.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		insereInicio(&lista, num);
	
	arquivo = fopen ("3333-arq5.txt", "r");
	if( arquivo == NULL)
	{	
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		inserePosicao(&lista, num, 3332);
	
	arquivo = fopen ("3333-arq4.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		insereFim(&lista, num);
    	
	
    	imprime(&lista);  */ 
    	
    /*	arquivo = fopen ("3333-arq4.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		insereInicioEn(&no, num);
		
	arquivo = fopen ("3333-arq3.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		insereFimEn(&no, num);
		
	arquivo = fopen ("3333-arq5.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		inserePosicaoEn(&no, num, 3330);
		
	imprimeEn(no); */
	
	arquivo = fopen ("3333-arq2.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		insereInicioDu(&noo, num);
		
	arquivo = fopen ("3333-arq5.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		insereFimDu(&noo, num);
		
	arquivo = fopen ("3333-arq2.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO");
		return 0;
	}
	while(EOF != fscanf(arquivo, "%d", &num) )
		inserePosicaoDu(&noo, num, 3202);	
		
	//imprimeDu(noo); 
	
		
    	tt = times(&time);	
    	printf("\nTempo de uso do processador pelo processo: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );
    	
    	
    	return 1;
}
