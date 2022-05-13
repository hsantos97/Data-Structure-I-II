#include<stdio.h>
#include<stdlib.h>

#define N 10

struct heap
{
	int vetHeap[N];
	int qtd;
};

typedef struct heap tipoHeap;

int pai(int);
int filhoEsq(int);
int filhoDir(int);
void insereHeap(tipoHeap*, int);
int removeRaizHeap(tipoHeap*, int);
int removeValorHeap(tipoHeap*, int);
void sobeHeap(tipoHeap*, int);
void desceHeap(tipoHeap*, int);
void imprimeHeap(tipoHeap*);

int main()
{
	tipoHeap heap;
	heap.qtd = 0;
	
	insereHeap(&heap, 1);
	insereHeap(&heap, 2);
	insereHeap(&heap, 5);
	insereHeap(&heap, 3);
	insereHeap(&heap, 10);
	insereHeap(&heap, 7);
	
	
	
	imprimeHeap(&heap);
	
	return 1;
}

int pai(int var)
{
	return(int) (var-1)/2;
}
int filhoEsq(int var)
{
	return (var*2)+1;
}
int filhoDir(int var)
{
	return (var*2)+2;
}
void insereHeap(tipoHeap *heap, int valor)
{
	if( heap->qtd < N )
	{
		heap->vetHeap[heap->qtd++] = valor;
		sobeHeap(heap, heap->qtd-1);
	}
}
void imprimeHeap(tipoHeap *heap)
{
	int i;
	
	if (heap->qtd == 0)
		printf("VAZIOO\n");
	else
	{
		for(i=0; i < heap->qtd; i++)
			printf("%d\t", heap->vetHeap[i]);
		printf("\n");
	}
}
void sobeHeap(tipoHeap *heap, int var)
{
	int aux;
	
	if( heap->vetHeap[var] > heap->vetHeap[ pai(var) ] )
	{
		aux = heap->vetHeap[var];
		heap->vetHeap[var] = heap->vetHeap[ pai(var) ];
		heap->vetHeap[ pai(var) ] = aux;
		
		if( pai(var) != 0 )
			sobeHeap( heap, pai(var) );
	}
}
void desceHeap(tipoHeap *heap, int var)
{
	int aux, varFilho;
	
	if( ( filhoEsq(var) < heap->qtd ) || ( filhoDir(var) < heap->qtd) ) // VERIFICAR SE TEM AO MENOS UM FILHO
	{
		if( filhoDir(var) < heap->qtd )
		{
			if( heap->vetHeap[filhoEsq(var)] > heap->vetHeap[filhoDir(var)] )
				varFilho = heap->vetHeap[filhoEsq(var)];
			else
				varFilho = heap->vetHeap[filhoDir(var)];
		}
		else
			varFilho = filhoEsq(var);
		if( heap->vetHeap[var] < heap->vetHeap[varFilho] )
		{
			aux = heap->vetHeap[var];
			heap->vetHeap[var] = heap->vetHeap[varFilho];
			heap->vetHeap[varFilho] = aux;
		
			desceHeap(heap, varFilho);
		}
	}
} 
