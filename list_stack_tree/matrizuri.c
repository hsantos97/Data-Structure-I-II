#include<stdio.h>
#define TAM 3
int main()
{
	char x;
	int m[TAM][TAM], l, c, soma=0, cont=0;
	float media;
	for(l=0;l<TAM;l++)
	{
		for(c=0;c<TAM;c++)
		{
			printf("[%d][%d]:", l, c);
			scanf("%d", &m[l][c]);
		}
	}
	printf("Matriz M :\n");
	for(l=0;l<TAM;l++)
	{	
		for(c=0;c<TAM;c++)
			printf("%d\t", m[l][c]);
		printf("\n");
	}
	for(l=0;l<TAM;l++)
	{
		for(c=0;c<TAM;c++)
		{
			if(l < c) //  para triangular superiot               (( l > c) para triangular inferior))
			{
				soma = soma + m[l][c];
				cont++;
			}
		}
	}
	media=(float)soma/cont;
	fgetc(stdin);
	printf("escolha a operação soma ou média\n");
	scanf("%c", &x);
	if(x == 's')
		printf("soma = %d\n", soma);
	else if(x == 'm')
		printf("média = %.2f\n", media);
	else
		printf("opção inválida\n");
	return 1;
}
