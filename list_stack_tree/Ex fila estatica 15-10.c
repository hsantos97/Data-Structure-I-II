#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define tam 20

struct fila{
    int vetFila[tam],qtdFila;

};

struct fila f;

bool verifyFila(struct fila f){
    if(f.qtdFila>0)
        return 0;
    else
        return 1;
}

bool insertFila(){
    if(f.qtdFila<tam){
        printf("\nValor:\n");
        scanf("%d",&f.vetFila[f.qtdFila]);
        f.qtdFila++;
        return true;
    }
    else{
        printf("\nNão é possível adicionar mais valores\n");
        return false;
    }

}

int removeFila(){
    if(verifyFila(f)==0){
        int i,aux;
        aux=f.vetFila[0];
        f.qtdFila-=1;
        for(i=0;i<f.qtdFila-1;i++){
            f.vetFila[i]=f.vetFila[i+1];
        }
        return 1;
    }
    else
        return 0;
}

void printFila(){
    int i;
    for(i=0;i<f.qtdFila;i++){
        printf("\n%d",f.vetFila[i]);
        }
    printf("\n");
}

int main(){
    f.qtdFila=0;
    short op=1;
    while(op!=0){
        printf("1-Inserir \n2-Imprimir \n3-Remover\n");
        scanf("%hd",&op);
        switch(op){
            case 1: insertFila();break;
            case 2: printFila();break;
            case 3: removeFila();break;
        }
        printf("\n");
    }
    printf("Programa finalizado");



    return 1;
}
