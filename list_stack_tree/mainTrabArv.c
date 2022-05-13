#include<stdio.h>
#include"trabArv.c"

int main(int argc, char *argv[])
{
	FILE *arquivo;
	tipoArv *arvore;
	char caracVet[10], letr;
	int i=0;
	
	arvore = NULL;
	
	arquivo = fopen ("morse.txt", "r");
	if( arquivo == NULL)
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
		return 0;
	}
	do
	{
		letr = getc( arquivo );
		if ( letr == '.' || letr == '-' )
		{
			caracVet[i] = letr;
			i++;
		}
		else
		{
			
			if( letr != ' ' && letr != '\n' && letr != EOF )
				insereNo(&arvore, caracVet, letr, i);
			i = 0;
		}
			
	}while ( letr != EOF );
	
	fclose(arquivo);
	
	imprimePreOrdem(arvore);
	
	arquivo = fopen ("frase.txt", "r");
	if( arquivo == NULL )
	{
		printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
		return 0;
	}
	do
	{
		letr = getc( arquivo );
		if ( letr == '.' || letr == '-' )
		{
			caracVet[i] = letr;
			i++;
		}

		else
		{
			
			if( (letr != ' ' || letr != EOF) && i > 0 )
			{
				traducao(arvore, caracVet, i);
				i = 0;
			}
			if( letr == '/' )
				printf(" ");
		}
			
	}while ( letr != EOF );
	printf("\n");	
	
	return 1;
}
