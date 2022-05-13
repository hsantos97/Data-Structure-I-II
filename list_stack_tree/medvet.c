//escreva um algoritmo que leia e armazena 10 números inteiros, armazenar num vetor, calcular a média entre os valores e contabilizar quantos valores são maiores e quantos são menores que a média.
#include<stdio.h>
int main()
{
	int vet[10], maior=0, menor=0, i, soma=0;
	float med;
	for(i=0;i<10;i++)
	{
		printf("[%d]", i);
		scanf("%d", &vet[i]);
		soma=soma+vet[i];
	}
	med=soma/10;
	for(i=0;i<10;i++)
	{
		if(vet[i]<med)
			menor++;
		else if(vet[i]>med)
			maior++;
	}
	printf("média: %.2f\nmaiores: %d\nmenores: %d\n", med, maior, menor);
	return 1;
}
		
