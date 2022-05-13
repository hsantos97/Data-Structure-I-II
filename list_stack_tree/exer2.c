#include<stdio.h>
int main()
{
	int idade, soma=0, cont=0;
	float med;
	do
	{	
		printf("informe uma idade\n");
		scanf("%d", &idade);
		cont++;
		soma=soma+idade;
	}
	while(idade>0);
	med=soma/cont;
	printf("media = %.2f\n", med);
	return 0;
}
