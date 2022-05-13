#include<stdlib.h>
#include<stdio.h>

// Definicao de constantes
#define N 10

// Definicao de Estrutura
struct estFila {
    int vetFila[N];
    int qtdDados;
};
typedef struct estFila tipoFila;

//*** Prototipo de funcoes ***
int filaVazia(tipoFila fl);
int filaCheia(tipoFila fl);
int insereFila(tipoFila *fl, int dado);
tipoFila insereFilaCP(tipoFila fl, int dado);
int removeFila(tipoFila *fl);
void imprimeFila(tipoFila fl);

//*** Funcao principal ***
int main() {
    tipoFila fila;
    fila.qtdDados = 0;

    //Insere um conjunto de valores
    insereFila ( &fila, 10 );
    insereFila ( &fila, 50 );
    insereFila ( &fila, 90 );
    insereFila ( &fila, 20 );
    fila = insereFilaCP ( fila, 7 );
    fila = insereFilaCP ( fila, 2 );
    fila = insereFilaCP ( fila, 1 );

    //Para verificacao, imprime a fila
    imprimeFila(fila);


    return 1;
}

//*** Implementacao das funcoes ***

// Verifica se fila vazia
// Parametro: Estrutura da fila (tipoFila)
// Retorno: Verdadeiro (caso fila vazia); Falso (caso fila com valor)
int filaVazia(tipoFila fl) {
    if ( fl.qtdDados == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

// Verifica se fila está cheia
// Parametro: Estrutura fila (tipofila)
// Retorno: Verdadeiro (se fila cheia); Falso (se fila com espaco)
int filaCheia(tipoFila fl) {
    if (fl.qtdDados < N) {
        return 0;
    } else {
        return 1;
    }
}

// Para debug, imprime a fila
// Parametro: estrutura fila (tipoFila)
// Retorno: "NADA" (Procedimento, tipo void)
void imprimeFila(tipoFila fl) {
    int i;
    printf("Fila = [");
    for ( i = 0; i < fl.qtdDados; i++ ){
        printf("%d,", fl.vetFila[i]);
    }
    printf("]\nqtdDados = %d\n", fl.qtdDados);
}

// Insere novo valor na fila, com passagem de parametro por referencia
// Parametro: Ponteiro tipoFila; valor inteiro a ser inserido
// Retorno: Verdadeiro (sucesso); Falso (caso de falha)
int insereFila(tipoFila *fl, int dado) {
    if ( ! filaCheia(*fl) ) {
        fl->vetFila[ fl->qtdDados++ ] = dado;
        //fl->qtdDados++;
        return 1;
    } else {
        return 0;
    }
}

// Insere novo valor na fila, usando parametro por copia, com retorno da nova configuracao da fila
tipoFila insereFilaCP(tipoFila fl, int dado) {
    if ( ! filaCheia(fl) ) {
        fl.vetFila[ fl.qtdDados++ ] = dado;
        return fl;
    } else {
        return fl;
    }

}
