#include<stdlib.h>
#include<stdio.h>

#define tam 20

struct pilha{
    int vetPilha[tam], qtdPilha;
};

struct pilha p;

int verifyPilha(struct pilha p){
    if(p.qtdPilha>0)
        return 0;
    else
        return 1;
}

void insertPilha(){
    if(p.qtdPilha<tam){
        printf("\nValor:\n");
        scanf("%d",&p.vetPilha[p.qtdPilha]);
        p.qtdPilha++;
    }
    else
        printf("\nNão é possível adicionar mais valores\n");
}

int removePilha(){
    if(verifyPilha(p)==0){
        p.qtdPilha-=1;
        return 1;
    }
    else
        return 0;
}

void printPilha(){
    int i;
    for(i=0;i<p.qtdPilha;i++){
        printf("\n%d",p.vetPilha[i]);
    }
    printf("\n");
}

int main(){
    p.qtdPilha=0;
    short op=1;
    while(op!=0){
        printf("1-Inserir \n2-Imprimir \n3-Remover\n");
        scanf("%hd",&op);
        switch(op){
            case 1: insertPilha();break;
            case 2: printPilha();break;
            case 3: removePilha();break;
        }
        printf("\n");
    }
    printf("Programa finalizado");


    return 1;
}

