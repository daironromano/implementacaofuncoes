#include <stdio.h>
#include <stdlib.h>

// FUN플O PRINCIPAL

int main()
{
    // TESTE MATRIZ SOMA
    void somaMatriz(int m1[3][3], int m2[3][3], int resultado[3][3], int linhas, int colunas);
    int m1[3][3] = {1,2,3,4,5,6,7,8,9};
    int m2[3][3] = {1,2,3,4,5,6,7,8,9};
    int resultado [3][3];
    somaMatriz(m1, m2, resultado, 3, 3);

    // TESTE MATRIZ SUBTRACAO
    void subtracaoMatriz(int ma1[3][3], int ma2[3][3], int resul[3][3], int linhas, int colunas);
    int ma1[3][3] = {1,2,3,4,5,6,7,8,9};
    int ma2[3][3] = {1,2,3,4,5,6,7,8,9};
    int resul [3][3];
    subtracaoMatriz(m1, m2, resul, 3, 3);

}

//FUN합ES IMPLEMENTADAS

    //FUN플O SOMA
void somaMatriz(int m1[3][3], int m2[3][3], int resultado[3][3], int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            resultado[i][j] = m1[i][j] + m2[i][j];
        }
    }

}

 //FUN플O SUBTRACAO
void subtracaoMatriz(int ma1[3][3], int ma2[3][3], int resul[3][3], int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            resul[i][j] = ma1[i][j] - ma2[i][j];
        }
    }

}




