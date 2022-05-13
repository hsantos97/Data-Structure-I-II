#include <stdio.h>
#include<stdlib.h>
int main()
{
	float inicio, fim, duracao;
	printf("informe o inicio e o fim\n");
	scanf("%f %f", &inicio, &fim);
	duracao = inicio + fim;
	printf("dracao = %.2f", duracao);
} 
