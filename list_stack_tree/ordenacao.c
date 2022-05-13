#ifndef ORDENACAO_C
#define ORDENACAO_C

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"listaestatica.c"

int bubbleSort(tipoLista *lst);
int shellSort(tipoLista *lst, int tamanho);
int mergeSort(tipoLista *lst, int inicio, int fim);
int merge(tipoLista *lst, int inicio, int meio, int fim);
int insertSort(tipoLista *lst);
int dividir(tipoLista *lst, int esq, int dir);
void quickSort(tipoLista *lst, int esq, int dir);
int selectionSort(tipoLista *ls);

int bubbleSort(tipoLista *lst)
{
	int troca, i, contador, aux;
	unsigned long long int cont;
	cont = 0;
	
	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		troca = 1;
		while (troca) {
			troca = 0;
		
		//for(contador=1; contador <= lst->tras; contador++)
		//{
			for(i=0; i <= lst->tras-1; i++)
			{
				if(lst->vet[i] > lst->vet[i+1])
				{
					aux=lst->vet[i];
					lst->vet[i]=lst->vet[i+1];
					lst->vet[i+1]=aux;
					cont++;
					troca=1;
				}
			}
		}	
	}
	return cont;
}
int shellSort(tipoLista *lst, int tam)
{
	int i, salto, frente, tras, aux, cont=0;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		salto = tam/2;
	
		while(salto > 0 )
		{
			for(i=salto; i < lst->tam; i++)
			{
				tras= i-salto;
				
				while( tras >= 0)
				{
					frente= tras+salto;
					
					if(lst->vet[tras] < lst->vet[frente])
						tras= -1;
					else
					{
						aux = lst->vet[tras];
						lst->vet[tras] = lst->vet[frente];
						lst->vet[frente] = aux;
						tras = tras - salto;
						cont++;
 					}
 				}
 			}
 			salto = salto/2;
 		}
	}
	return cont;
}
int mergeSort(tipoLista *lst, int inicio, int fim)
{
	int meio, troca = 0;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		if(inicio < fim)
		{
			meio = floor( (inicio+fim)/2 );
			mergeSort(lst, inicio, meio);
			mergeSort(lst, meio+1, fim);
			troca = troca + merge(lst, inicio, meio, fim);
		}
	}
	return troca;
}
int merge(tipoLista *lst, int inicio, int meio, int fim)
{
	int *temp, p1, p2, tamanho, i , j, k;
	int fim1=0, fim2=0, cont=0, chaveamento;
	
	tamanho = fim-inicio+1;
	
	p1 = inicio;
	p2 = meio+1;
	
	temp = (int*) malloc(tamanho*sizeof(int));
	
	if(temp != NULL)
	{
		chaveamento = 1;
		for(i=0; i < tamanho; i++)
		{
			if(!fim1 && !fim2)
			{
				if(lst->vet[p1] < lst->vet[p2])
				{
					temp[i] = lst->vet[p1++];
					if(chaveamento == 2)
						cont++;
					chaveamento = 1;
				}
				else
				{
					temp[i] = lst->vet[p2++];
					if(chaveamento == 1)
						cont++;
					chaveamento = 2;
					
				}
				if(p1 > meio)
					fim1 = 1;
				if(p2 > fim)
					fim2 = 1;
			}
			else
			{
				if(!fim1)
				{
					temp[i] = lst->vet[p1++];
					
				}
				else
				{
					temp[i] = lst->vet[p2++];
					
				}
			}

		}		
		for(j=0, k = inicio; j < tamanho; j++, k++)
			lst->vet[k] = temp[j];
	}
	free(temp);
	return cont;
}		
int insertSort(tipoLista *lst)
{
	int i, j, aux;
	unsigned long long int cont;
	
	cont = 0;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(i=1; i < lst->tam; i++)
		{
			aux = lst->vet[i];
			j = i-1;
			
			while ( (j>= 0) && (aux < lst->vet[j]) )
			{
				lst->vet[j+1] = lst->vet[j];
				j--;
				cont++;
			}
			
			lst->vet[j+1] = aux;
		}
	}
	
	return cont;
}
int dividir(tipoLista *lst, int esq, int dir)
{
	int aux, i, cont=esq;
		
	for(i=esq+1; i <= dir; i++)
	{
		if(lst->vet[i] < lst->vet[esq])
		{
			cont++;
			aux = lst->vet[i];
			lst->vet[i] = lst->vet[cont];
			lst->vet[cont] = aux;
			lst->contador++;
		}
		
	}
	
	aux = lst->vet[esq];
	lst->vet[esq] = lst->vet[cont];
	lst->vet[cont] = aux;
	
	return cont;
}			
void quickSort(tipoLista *lst, int esq, int dir)
{
	int pos;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		if(esq < dir)
		{
			pos = dividir(lst, esq, dir);
			quickSort(lst, esq, pos-1);
			quickSort(lst, pos+1, dir);
		}
	}
			
}
int selectionSort(tipoLista *lst)
{
	int menor,aux, i, j, cont = 0;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(i=0; i < lst->tam ;i++)
		{
			menor = i;
			for(j=i+1; j < lst->tam;j++)
			{
				if(lst->vet[menor] > lst->vet[j])
					menor=j;
			}
			if(i!=menor)
			{
				aux=lst->vet[i];
				lst->vet[i]=lst->vet[menor];
				lst->vet[menor]=aux;
				lst->contador++;
			}
		}
	}
	
	return cont;
}
#endif
