//escreva um algoritmo que leia 5 números e conte quantos são pares.
#include<stdio.h>
int main()
{
	int n, i, par=0;
	for(i=0;i<5;i++)
	{
		printf("informe um número\n");
		scanf("%d", &n);
		if(n%2==0)
			par++;
	}
	printf("quantidade de pares = %d\n", par);
	return 0;
}
