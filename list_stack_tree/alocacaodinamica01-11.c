#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a,i;
	int *x,*y;
	int *vetDin;
	
	printf("Valor de a: ");
	/*scanf("%d",&a);*/
	a=2;
	x=&a; //Aponta para o endereço de 'a'
	
	y = (int *)malloc(sizeof(int));
	
	*y = a*2;
	
	printf("Valor de y = %d\n",*y);
	
	if(a>0)
		vetDin = (int *) malloc(sizeof(int)*a);
	
	for(i = 0 ;i < a; i++){
		vetDin[i]=a-1;
	}
	
	
	
	
	return 1;
}
