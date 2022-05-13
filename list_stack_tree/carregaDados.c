#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//#include"listaestatica.c"
/*#include"numeros.c"*/


int main()
{
	
	int nume, j, chave, i;
	FILE *arq;
	char texto[100];
	
	printf("numeros por aquivo\n");
	scanf("%d", &nume);

	sprintf(texto, "semRes-arq.txt");
	arq = fopen (texto, "w");
		
	if(arq == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
		
	srand( (unsigned) i + j *time(NULL));
		
	for(j=0; j < nume; j++)
	{
		chave =  rand()%1023;
		
		if(chave <= 0)
			chave = chave * (-1);	
		fprintf(arq, "%d\n", chave);
	}
	
	fclose(arq);
}

