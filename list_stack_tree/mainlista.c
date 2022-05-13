#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <time.h>
#include <sys/times.h> //Times Funcao
#include <sys/types.h> //Bib que define o registro TMS
#include <unistd.h> //Biblioteca necessaria para descobrir os ciclos de clock


//inclusão de biblioteca proprias
#include"listaestatica.c"
#include"ordenacao.c"

	
int main(int argc, char *argv[])
{
	clock_t tt;
	//Variaveis para contagem do tempo
	struct tms time; //Estrutura que irah guardar os dados a respeito do tempo de execucao do programa
  	//clock_t clock;
    	int tics_per_second; //Variavel que irah guardar os ciclos de clock por segundo do sistema
    	//Pergunta ao SO sobre os ciclos de clock
    	tics_per_second = sysconf(_SC_CLK_TCK);
	

	tipoLista lista;
	FILE *arquivo;
	int num; 
	unsigned long long int qtdTroca = 0;
	
	lista.contador = 0;
	
	/*if( argc !=2 )
	{
		printf("FALHA NA QUANTIDADE DE ARGUMENTOS\n");
		return 0;
	}
	else
	{*/
		inicializaLista(&lista, 10);
		
		arquivo = fopen ("10-arq1.txt", "r");
		//arquivo = fopen (argv[1], "r");
		if( arquivo == NULL)
		{
			printf("IMPOSSIVEL ABRIR O ARQUIVO");
			return 0;
		}
		while(EOF != fscanf(arquivo, "%d", &num) )
			insereFim(&lista, num);
	//}
			
	
	//printf("\nimprimindo a lista\n");	
	
	//imprime(&lista);
	
	//printf("\n");

	/*qtdTroca = bubbleSort(&lista); // contador funcionando
	tt = times(&time);
	printf("Clock = %f\n", (float)tt);	
    	printf("\nTempo de uso do processador pelo processo: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );*/
	
	/*qtdTroca = shellSort(&lista, 100000); // contador funcionando

    	tt = times(&time);
	printf("Clock = %f\n", (float)tt);	
    	printf("\nTempo de uso do processador pelo processo: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );*/
	
	
	qtdTroca = mergeSort(&lista, 0, 10); 
	tt = times(&time);
	printf("Clock = %f\n", (float)tt);	
    	printf("\nTempo de uso do processador pelo processo: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );
	
	/*qtdTroca = insertSort(&lista); // contador funcionando
	tt = times(&time);
	printf("Clock = %f\n", (float)tt);	
    	printf("\nTempo de uso do processador pelo processo: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );*/
	
	/*quickSort(&lista, 0, 100000); // contador funcionou
	tt = times(&time);
	printf("Clock = %f\n", (float)tt);	
    	printf("\nTempo de uso do processador pelo processo: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );*/
	
	/*qtdTroca = selectionSort(&lista); // contador funcionou
	tt = times(&time);
	printf("Clock = %f\n", (float)tt);	
    	printf("\nTempo de uso do processador pelo processo: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );*/
	
	/*printf("\nIMPRIMINDO LISTA ORDENADA\n");
	
	imprime(&lista);	
	
	printf("\n");*/
	
	printf("QUANTIDADE DE TROCA: %llu\n", qtdTroca );
	
	//printf("QUANTIDADE DE TROCA: %d\n", lista.contador ); // MOSTRAR NÚMERO DE TROCAS DO QUICKSORT 
	
	return 1;
}	
