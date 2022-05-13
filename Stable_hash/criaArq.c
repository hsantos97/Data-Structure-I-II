#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
	
	int nume, j, negativo, i;
	FILE *arq;
	char texto[100];
	char *validchars = "abcdefghijklmnopqrstuvwxyz";
	char v[3];
	int str_len;
	int flag; // par = 0, aleatorio = 1
	
	printf("numeros por aquivo\n");
	scanf("%d", &nume);
	
	sprintf(texto, "%d-arq10.txt", nume);
	arq = fopen (texto, "w");
		
	if(arq == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	
	srand(time(NULL));
	
	str_len = (rand() % 26 );
	
	flag = 0;

	if(flag == 1)
	{
		
		for(j=0; j < nume; j++)
		{
			negativo =  rand()%1024;
			
			if(negativo <= 0)
				negativo = negativo * (-1);	
			fprintf(arq, "%d ", negativo);
			
			for(i=0;i<3;i++)
			{
	    			v[i] = validchars[ rand() % strlen(validchars) ];
	       			fprintf(arq, "%c", v[i]);
	    		}
	    		fprintf(arq, "\n");
	    	}
	}
	if(flag == 0)
	{
		for(j=0; j < nume; j++)
		{
			negativo = 3;
			while(negativo % 2 != 0)
				negativo =  rand()%1024;
			
			if(negativo <= 0)
				negativo = negativo * (-1);
				
			fprintf(arq, "%d ", negativo);
			
			for(i=0;i<3;i++)
			{
	    			v[i] = validchars[ rand() % strlen(validchars) ];
	       			fprintf(arq, "%c", v[i]);
	    		}
	    		fprintf(arq, "\n");
	    	}
	}
	fgetc(stdin);	
	fclose(arq);
}

