//crie um registro que armazena uma letra, 2 numeros reais e uma média. Escreva o algoritmo que leia 5 conjunto de dados para este registro, calcule A.
#include<stdio.h>
#include<stdlib.h>
#define TAM 4	
struct aluno
{
	float n1, n2, med;
	char nome;
	int falta;
};
int main()
{
	struct aluno ed1[TAM];
	int i;
	char a;
	for(i=0;i<TAM;i++)
	{
		printf("\ninfomre uma letra\n");
		scanf("%c", &ed1[i].nome);
		printf("informe n1\n");
		scanf("%f", &ed1[i].n1);
		printf("informe n2\n");
		scanf("%f", &ed1[i].n2);
		printf("informe quantidade de faltas\n");
		scanf("%d", &ed1[i].falta);
		ed1[i].med=(ed1[i].n1+ed1[i].n2)/2;
		fgetc(stdin);
	}
	for(i=0;i<TAM;i++)
	{
		printf("nome: %c\n", ed1[i].nome);
		printf("n1: %.2f\n", ed1[i].n1);
		printf("n2: %.2f\n", ed1[i].n2);
		printf("média: %.2f\n", ed1[i].med);
		printf("número de faltas: %d\n", ed1[i].falta);
		if(ed1[i].med >= 5.0 && ed1[i].falta < 10)
		{
			printf("Aprovado !! \n\n");
		}
		if(ed1[i].med < 5.0 && ed1[i].falta >= 10)
		{
			printf("Reprovado por média e falta \n\n");
		}
		if(ed1[i].med < 5.0 && ed1[i].falta < 10)
		{
			printf("Reprovado por média \n\n");
		}
		if(ed1[i].med >= 5.0 && ed1[i].falta > 10)
		{
			printf("Reprovado por falta \n\n");
		}
	}
	return 1;
}
