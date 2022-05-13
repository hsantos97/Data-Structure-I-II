#ifndef NUMEROS_C
#define NUMEROS_C

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

void GeraAleatorios(int numeros[], int quantNumeros, int limite)
{
    srand(time(NULL));
    int i, v, j;
    bool Existe;
    for(i=0; i<quantNumeros;i++)
    {
        v = rand()%limite;

        Existe=false;
        for(j=0;j<i;j++)
        {
            if(numeros[j]==v)
                Existe = true;
        }

        if(!Existe)
            numeros[i] = v;
        else
            i--;
    }
}
#endif
