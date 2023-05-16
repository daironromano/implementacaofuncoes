#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

// PROTOTIPOS DAS FUNCOES
void somaMatriz(int m1[3][3], int m2[3][3], int resultado[3][3]);
void subtracaoMatriz(int m1[3][3], int m2[3][3], int resultado[3][3]);
void imprimirMatriz(int matriz[3][3]);

// FUNCAO PRINCIPAL
int main()
{
    // TESTE MATRIZ SOMA
        int m1[3][3] = {1,2,3,4,5,6,7,8,9};
        int m2[3][3] = {1,2,3,4,5,6,7,8,9};
        int resultado [3][3];

        printf("Matriz Soma 1 \n");
        imprimirMatriz(m1);
        printf("Matriz Soma 2 \n");
        imprimirMatriz(m2);

        printf("Resultado \n");
        somaMatriz(m1, m2, resultado);
        imprimirMatriz(resultado);

    // TESTE MATRIZ SUBTRACAO
        printf("Matriz Subtracao 1\n");
        imprimirMatriz(m1);
        printf("Matriz Subtracao 2\n");
        imprimirMatriz(m2);
        printf("Resultado\n");
        subtracaoMatriz(m1, m2, resultado);
        imprimirMatriz(resultado);


}

//FUNCAO IMPRIMIR MATRIZES
void imprimirMatriz(int matriz[3][3]){
    for(int linhas=0; linhas<3; linhas++) {
        for(int colunas=0;colunas<3;colunas++) {
            printf("%i ", matriz[linhas][colunas]);
        }
        printf("\n");
    }
}

//FUNCOES IMPLEMENTADAS
    //FUNCAO SOMA
void somaMatriz(int m1[3][3], int m2[3][3], int resultado[3][3]) {
    for (int linhas=0;linhas<3; linhas++) {
        for (int colunas = 0; colunas< 3;colunas++) {
            resultado[linhas][colunas] = m1[linhas][colunas] + m2[linhas][colunas];
        }
    }

}

//FUNCAO SUBTRACAO
void subtracaoMatriz(int m1[3][3], int m2[3][3], int resultado[3][3]) {
    for (int linhas=0;linhas<3; linhas++) {
        for (int colunas = 0; colunas< 3;colunas++) {
            resultado[linhas][colunas] = m1[linhas][colunas] - m2[linhas][colunas];
        }
    }

}
