#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[5];
	int valor;
	
	FILE *arquivo;
	
	arquivo = fopen("escreverler.txt", "r+");
	
	if(arquivo == NULL)
	{
		printf("ERRO NA ABERTURA DE ARQUIVO\n");
		exit (0);
	}
	
	fprintf(arquivo, "ola 12");
		fscanf(arquivo, "%s %d", str, &valor);
	
	printf("%s %d", str, valor);

	fprintf(arquivo, "TESTE de Escrita...");
	
	fclose(arquivo);
	
	return 1;
}
