#include<stdio.h>
int main()
{
	int i, v[6], cont=0, soma;
	float med;
	for(i=0;i<=6;i++)
	{
		printf("v[%d]:", i);
		scanf("%d", &v[i]);
	}
	for(i=0;i<5;i++)
	{
		if(v[i]>0)
		{	
			cont=cont+1;
			soma=soma+v[i];
		}
	}
	med=soma/6;
	printf("%d numeros de positivos\nmedia=%.2f\n", cont, med);
	return 0;
}
