#include <stdio.h>
#include <malloc.h>

typedef struct tempNo 
{
    float valor;
    int coluna;
    struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct 
{
    PONT* A;
    int linhas;
    int colunas;
} MATRIZ;

typedef struct MATRIZ* MAT;

void inicializarMatriz(MATRIZ* m, int lin, int col) 
{
    printf("test1\n");
    int i;
    m->linhas = lin;
    m->colunas = col;
    m->A = (PONT*) malloc(lin*sizeof(PONT));
    for (i=0;i<lin;i++) 
    {   
        m->A[i] = NULL;
        printf("test2\n");
    }

}

void AtribuiMatriz(MATRIZ* m,int lin, int col, float val) 
{
    printf("test3\n");
    if (lin<0 || lin >= m->linhas || col<0 || col >= m->colunas) 
        printf("Erro na Atribuição\n");
    
    PONT ant = NULL;
    PONT atual = m->A[lin];

    while (atual != NULL && atual->coluna<col) 
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->coluna == col) 
    {
        if (val == 0) 
        {
            if (ant==NULL) 
                m->A[lin] = atual->prox;
            else 
                ant->prox = atual->prox;

            free(atual);
        }   
        else if (val != 0) 
        {
            PONT novo = (PONT) malloc(sizeof(NO));
            novo->coluna = col;
            novo->valor = val;
            novo->prox = atual;

            if (ant == NULL) 
                m->A[lin] = novo;
            else 
                ant->prox = novo;
        }
        else 
            atual->valor = val;
    }
}

float ValorMatriz(MATRIZ* m, int lin, int col) 
{
    if (lin<0 || lin>=m->linhas || col<0 ||col >= m->colunas) 
    {
        printf("Linha ou coluna não existe\n");
        return 0;
    }    

    PONT atual = m->A[lin];
    
    while (atual != NULL && atual->coluna < col)
        atual = atual->prox;
    if (atual !=NULL && atual->coluna == col)
    {
        printf("valor encontrado\n");
        return atual->valor;
    }    

    return 0;
}

int main()
{
   // PONT *no;
   // no = NULL; 

    MAT *m;
    m = NULL;

    printf("Inicializando a Matriz\n");
    inicializarMatriz(&m, 5, 5);

    printf("Inserindo na Matriz\n");
    AtribuiMatriz(&m, 3, 3, 3.2);
   /* AtribuiMatriz(m, 0, 0, 4.1);
    AtribuiMatriz(m, 2, 2, 7.3); */

  /*  float encontra = ValorMatriz(m, 4, 4);
    encontra = ValorMatriz(m, 0, 0);
    encontra = ValorMatriz(m, 2, 2);
    encontra = ValorMatriz(m, 1, 1);  */
}