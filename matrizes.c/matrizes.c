#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

///ESTRUTURA DE DADOS COMPLEXO
    typedef struct{
        float real;
        float imag;
    } Complexo;

/// PROTOTIPOS DAS FUNCOES
void imprimirMatriz(Complexo** matriz, int linhas, int colunas);
void imprimirVetor(Complexo* vetor, int linhas);
void somaMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSoma);
void subtracaoMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSub);
Complexo produtoEscalar(Complexo* v1, Complexo* v2, int tamanho);
void produtoMatricial(Complexo** mat1, Complexo** mat2, Complexo** resultado, int linhas1, int colunas1, int colunas2);
Complexo** matrizTransposta(Complexo** matriz, int linhas, int colunas);
Complexo** matrizHermitiana(Complexo** matriz, int linhas, int colunas);
Complexo** matrizConjugada(Complexo** matriz, int linhas, int colunas);


void produtoMatricial(Complexo** mat1, Complexo** mat2, Complexo** resultado, int linhas1, int colunas1, int colunas2);
/// FUNCAO PRINCIPAL
int main(){
    /// TESTE 1 MATRIZ SOMA E SUBTRACAO
        /// ALOCACAO DE MEMORIA
         int linhas = 3;
         int colunas =3;

        Complexo** m1 = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** m2 = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** resultadoSoma = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** resultadoSub = (Complexo**)malloc(sizeof(Complexo*) * linhas);

        for(int i=0;i<linhas;i++){
            m1[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
            m2[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
            resultadoSoma[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
            resultadoSub[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
        }

        /// ATRIBUINDO VALORES PARA O TESTE 1
        m1[0][0].real = +4; m1[0][0].imag = +4;
        m1[0][1].real = 3;  m1[0][1].imag = 4;
        m1[0][2].real = 2;  m1[0][2].imag = 6;
        m2[0][0].real = -5; m2[0][0].imag = 5;
        m2[0][1].real = 3;  m2[0][1].imag = 4;
        m2[0][2].real = 1;  m2[0][2].imag = 2;

        m1[1][0].real = 1;  m1[1][0].imag = 2;
        m1[1][1].real = 3;  m1[1][1].imag = 4;
        m1[1][2].real = 8; m1[1][2].imag = 6;
        m2[1][0].real = 2; m2[1][0].imag = 3;
        m2[1][1].real = 4; m2[1][1].imag = 5;
        m2[1][2].real = 6; m2[1][2].imag = 7;

        m1[2][0].real = 7; m1[2][0].imag = 18;
        m1[2][1].real = 9; m1[2][1].imag = 10;
        m1[2][2].real = 11; m1[2][2].imag = 12;
        m2[2][0].real = 8; m2[2][0].imag = 9;
        m2[2][1].real = 10; m2[2][1].imag = 11;
        m2[2][2].real = 12; m2[2][2].imag = 13;

        /// TESTE 1 MATRIZ SOMA
        printf("======TESTE 1 DA OPERACAO SOMA======\n");
        printf("Operando A: \n");
        imprimirMatriz(m1, linhas, colunas);
        printf("Operando B: \n");
        imprimirMatriz(m2, linhas, colunas);

        printf("Resultado: \n");
        somaMatriz(m1, m2, resultadoSoma);
        imprimirMatriz(resultadoSoma, linhas, colunas);
printf("\n");
        /// TESTE 1 MATRIZ SUBTRACAO
        printf("======TESTE 1 DA OPERACAO SUBTRACAO======\n");
        printf("Operando A: \n");
        imprimirMatriz(m1, linhas, colunas);
        printf("Operando B: \n");
        imprimirMatriz(m2, linhas, colunas);
        printf("Resultado\n");
        subtracaoMatriz(m1, m2, resultadoSub);
        imprimirMatriz(resultadoSub, linhas, colunas);
printf("\n");
        /// ALOCANDO MEMÓRIA TESTE 2
        Complexo** ma1 = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** ma2 = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** resultadoSoma2 = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** resultadoSub2 = (Complexo**)malloc(sizeof(Complexo*) * linhas);

        for(int i=0;i<linhas;i++){
            ma1[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
            ma2[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
            resultadoSoma2[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
            resultadoSub2[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
        }

        /// ATRIBUINDO VALORES PARA O TESTE 2
        ma1[0][0].real = +20; ma1[0][0].imag = +7;
        ma1[0][1].real = 9;   ma1[0][1].imag = 4;
        ma1[0][2].real = 6;   ma1[0][2].imag = 33;
        ma2[0][0].real = -5;  ma2[0][0].imag = 2;
        ma2[0][1].real = 3;   ma2[0][1].imag = 70;
        ma2[0][2].real = 1;   ma2[0][2].imag = 2;

        ma1[1][0].real = 1;  ma1[1][0].imag = 2;
        ma1[1][1].real = 86; ma1[1][1].imag = 8;
        ma1[1][2].real = 8;  ma1[1][2].imag = 6;
        ma2[1][0].real = 2;  ma2[1][0].imag = 3;
        ma2[1][1].real = 9;  ma2[1][1].imag = 5;
        ma2[1][2].real = 7;  ma2[1][2].imag = 7;

        ma1[2][0].real = 7;  ma1[2][0].imag = 8;
        ma1[2][1].real = 9;  ma1[2][1].imag = 10;
        ma1[2][2].real = 11; ma1[2][2].imag = 22;
        ma2[2][0].real = 8;  ma2[2][0].imag = 9;
        ma2[2][1].real = 90; ma2[2][1].imag = 11;
        ma2[2][2].real = 87; ma2[2][2].imag = 13;

        /// TESTE 2 MATRIZ SOMA
        printf("======TESTE 2 DA OPERACAO SOMA======\n");
        printf("Operando A: \n");
        imprimirMatriz(ma1, linhas, colunas);
        printf("Operando B: \n");
        imprimirMatriz(ma2, linhas, colunas);

        printf("Resultado: \n");
        somaMatriz(m1, m2, resultadoSoma);
        imprimirMatriz(resultadoSoma, linhas, colunas);
printf("\n");
        /// TESTE 2 MATRIZ SUBTRACAO
        printf("======TESTE 2 DA OPERACAO SUBTRACAO======\n");
        printf("Operando A: \n");
        imprimirMatriz(m1, linhas, colunas);
        printf("Operando B: \n");
        imprimirMatriz(m2, linhas, colunas);
        printf("Resultado\n");
        subtracaoMatriz(m1, m2, resultadoSub);
        imprimirMatriz(resultadoSub, linhas, colunas);
printf("\n");
        /// TESTE PRODUTO_ESCALAR
            /// ALOCACAO DE MEMORIA PRODUTO ESCALAR
        Complexo* v1 = (Complexo*)malloc(3*sizeof(Complexo));
        Complexo* v2 = (Complexo*)malloc(3*sizeof(Complexo));
        Complexo* ve1 = (Complexo*)malloc(3*sizeof(Complexo));
        Complexo* ve2 = (Complexo*)malloc(3*sizeof(Complexo));

        v1[0].real = 60;  v1[0].imag = 80;
        v1[1].real = 79;  v1[1].imag = 14;
        v1[2].real = 10;  v1[2].imag = 57;

        v2[0].real = 4;  v2[0].imag = 8;
        v2[1].real = 1;  v2[1].imag = 14;
        v2[2].real = 2;  v2[2].imag = 9;

        ve1[0].real = 4;  ve1[0].imag = 8;
        ve1[1].real = 3;  ve1[1].imag = 14;
        ve1[2].real = 2;  ve1[2].imag = 4;

        ve2[0].real = 9;  ve2[0].imag = 8;
        ve2[1].real = 7;  ve2[1].imag = 64;
        ve2[2].real = 01; ve2[2].imag = 4;

        printf("======TESTE 1 DA OPERACAO PRODUTO_ESCALAR======");
        printf("\nOperando A: \n");
        imprimirVetor(v1, linhas);
        printf("Operando B: \n");
        imprimirVetor(v2, linhas);
        Complexo vetoresultado = produtoEscalar(v1,v2,3);
        printf("Resultado:\n%.2f + %.2fi \n", vetoresultado.real, vetoresultado.imag);
printf("\n");
        printf("======TESTE 2 DA OPERACAO PRODUTO_ESCALAR======\n");
        printf("Operando A: \n");
        imprimirVetor(ve1, linhas);
        printf("Operando B: \n");
        imprimirVetor(ve2, linhas);
        Complexo vetorresultado = produtoEscalar(ve1, ve2,3);
        printf("Resultado:\n%.2f + %.2fi \n", vetorresultado.real, vetorresultado.imag);
printf("\n");
        /// TESTE PRODUTO_MATRICIAL
        printf("======TESTE DA OPERACAO PRODUTO_MATRICIAL======\n");
            /// ALOCACAO DE MEMORIA PRODUTO MATRICIAL
        Complexo** matriz1 = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** matriz2 = (Complexo**)malloc(sizeof(Complexo*) * linhas);
        Complexo** resultadoProduto = (Complexo**)malloc(sizeof(Complexo*) * linhas);

        for (int i = 0; i < linhas; i++) {
        matriz1[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
        matriz2[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
        resultadoProduto[i] = (Complexo*)malloc(sizeof(Complexo) * colunas);
        }

        matriz1[0][0].real = +4; matriz1[0][0].imag = +4;
        matriz1[0][1].real = 3;  matriz1[0][1].imag = 4;
        matriz1[0][2].real = 2;  matriz1[0][2].imag = 6;
        matriz2[0][0].real = -5; matriz2[0][0].imag = 5;
        matriz2[0][1].real = 3;  matriz2[0][1].imag = 4;
        matriz2[0][2].real = 1;  matriz2[0][2].imag = 2;

        matriz1[1][0].real = 1;  matriz1[1][0].imag = 2;
        matriz1[1][1].real = 3;  matriz1[1][1].imag = 4;
        matriz1[1][2].real = 8;  matriz1[1][2].imag = 6;

        matriz2[1][0].real = 2;  matriz2[1][0].imag = 3;
        matriz2[1][1].real = 4;  matriz2[1][1].imag = 5;
        matriz2[1][2].real = 6;  matriz2[1][2].imag = 7;

        matriz1[2][0].real = 7;  matriz1[2][0].imag = 18;
        matriz1[2][1].real = 9;  matriz1[2][1].imag = 10;
        matriz1[2][2].real = 11; matriz1[2][2].imag = 12;
        matriz2[2][0].real = 8;  matriz2[2][0].imag = 9;
        matriz2[2][1].real = 10; matriz2[2][1].imag = 11;
        matriz2[2][2].real = 12; matriz2[2][2].imag = 13;

        /// ATRIBUINDO VALORES PARA O TESTE DO PRODUTO_MATRICIAL
        printf("Operando A: \n");
        imprimirMatriz(matriz1, linhas, colunas);
        printf("Operando B: \n");
        imprimirMatriz(matriz2, linhas, colunas);

        printf("Resultado:\n");
        produtoMatricial(matriz1, matriz2, resultadoProduto, linhas, colunas, colunas);
        imprimirMatriz(resultadoProduto, linhas, colunas);
printf("\n");
        /// TESTE TRANSPOSTA
            /// ALOCACAO DE MEMORIA TRANSPOSTA
        Complexo** matriz = (Complexo**)malloc(sizeof(Complexo*)*linhas);
            for(int i=0; i<linhas;i++){
                matriz[i]=(Complexo*)malloc(colunas*sizeof(Complexo));
                for(int j=0; j<colunas;j++){
                    matriz[i][j].real = i+j;
                    matriz[i][j].imag = i-j;
                }
            }
        /// ATRIBUINDO VALORES PARA O TESTE 1 DA TRANSPOSTA
        matriz[0][0].real = -3; matriz[0][0].imag = +4;
        matriz[0][1].real = 3;  matriz[0][1].imag = 4;
        matriz[0][2].real = -2; matriz[0][2].imag = -6;
        matriz[1][0].real = +1; matriz[1][0].imag = 2;
        matriz[1][1].real = +3; matriz[1][1].imag = 4;
        matriz[1][2].real = 5;  matriz[1][2].imag = 6;
        matriz[2][0].real = 7;  matriz[2][0].imag = 8;
        matriz[2][1].real = 9;  matriz[2][1].imag = 10;
        matriz[2][2].real = 11; matriz[2][2].imag = 12;

        /// ATRIBUINDO VALORES PARA O TESTE 2 DA TRANSPOSTA
        matriz[0][0].real = +0; matriz[0][0].imag = +4;
        matriz[0][1].real = 6;  matriz[0][1].imag = 4;
        matriz[0][2].real = 18; matriz[0][2].imag = 9;
        matriz[1][0].real = +10;matriz[1][0].imag = 22;
        matriz[1][1].real = 03; matriz[1][1].imag = 47;
        matriz[1][2].real = -56;matriz[1][2].imag = 96;
        matriz[2][0].real = 80; matriz[2][0].imag = 8;
        matriz[2][1].real = 90; matriz[2][1].imag = 10;
        matriz[2][2].real = 11; matriz[2][2].imag = 12;


        printf("======TESTE DA OPERACAO 1 TRANSPOSTA======\n");
        printf("Matriz Original: \n");
        imprimirMatriz(matriz, linhas, colunas);
        printf("Matriz Transposta: \n");
        matriz = matrizTransposta(matriz, linhas, colunas);
        imprimirMatriz(matriz, linhas, colunas);
printf("\n");
        printf("======TESTE DA OPERACAO 2 TRANSPOSTA======\n");
        printf("Matriz Original: \n");
        imprimirMatriz(matriz, linhas, colunas);
        printf("Matriz Transposta: \n");
        matriz = matrizTransposta(matriz, linhas, colunas);
        imprimirMatriz(matriz, linhas, colunas);
printf("\n");
        printf("======TESTE DA OPERACAO_CONJUGADA======\n");

        Complexo** conjugada = (Complexo*)malloc(linhas * sizeof(Complexo));
        for (int i = 0; i < linhas; i++) {
        conjugada[i] = (Complexo*)malloc(colunas * sizeof(Complexo));
        for (int j = 0; j < colunas; j++) {
            conjugada[i][j].real = i + j;
            conjugada[i][j].imag = i - j;
        }
    }

        /// ATRIBUICAO DE VALORES CONJUGADA
        conjugada[0][0].real = 3;    conjugada[0][0].imag = -2;
        conjugada[0][1].real = -5;   conjugada[0][1].imag = 3;
        conjugada[0][2].real = 2;    conjugada[0][2].imag = 4;
        conjugada[1][0].real = 3;    conjugada[1][0].imag = 3;
        conjugada[1][1].real = -4;   conjugada[1][1].imag = 2;
        conjugada[1][2].real = 6;    conjugada[1][2].imag = 3;
        conjugada[2][0].real = -2;   conjugada[2][0].imag = 7;
        conjugada[2][1].real = -3;   conjugada[2][1].imag = -8;
        conjugada[2][2].real = 1;    conjugada[2][2].imag = 9;

        printf("Matriz original:\n");
        imprimirMatriz(conjugada, linhas, colunas);
        Complexo** matrizConjugadaResult = matrizConjugada(conjugada, linhas, colunas);

        printf("\nMatriz conjugada:\n");
        imprimirMatriz(matrizConjugadaResult, linhas, colunas);

        /// TESTE FUNCAO HERMITIANA
        printf("======TESTE DA OPERACAO_HERMITIANA======\n");
        Complexo** hermitiana = (Complexo*)malloc(linhas * sizeof(Complexo));
        for (int i = 0; i < linhas; i++) {
            hermitiana[i] = (Complexo*)malloc(colunas * sizeof(Complexo));
                for (int j = 0; j < colunas; j++) {
                    hermitiana[i][j].real = i + j;
                    hermitiana[i][j].imag = i - j;
            }
        }
        /// ATRIBUINDO VALORES PARA TESTE HERMITIANA
        hermitiana[0][0].real = 2;    hermitiana[0][0].imag = -3;
        hermitiana[0][1].real = -5;   hermitiana[0][1].imag = 6;
        hermitiana[0][2].real = 7;    hermitiana[0][2].imag = 4;
        hermitiana[1][0].real = 21;    hermitiana[1][0].imag = 7;
        hermitiana[1][1].real = -4;   hermitiana[1][1].imag = 2;
        hermitiana[1][2].real = -5;    hermitiana[1][2].imag = 9;
        hermitiana[2][0].real = -22;   hermitiana[2][0].imag = 7;
        hermitiana[2][1].real = -3;   hermitiana[2][1].imag = -11;
        hermitiana[2][2].real = 13;    hermitiana[2][2].imag = 9;

        printf("Matriz original:\n");
        imprimirMatriz(hermitiana, linhas, colunas);
        Complexo** matrizHermitianaResult = matrizHermitiana(hermitiana, linhas, colunas);

        printf("\nMatriz hermitiana:\n");
        imprimirMatriz(matrizHermitianaResult, linhas, colunas);

        /// LIBERAR MEMORIA SOMA E SUBTRACAO
        for(int i=0;i<3;i++){
        free(m1[i]);
        free(m2[i]);
        free(resultadoSoma[i]);
        free(resultadoSub[i]);
        }
        for(int i=0;i<3;i++){
        free(ma1[i]);
        free(ma2[i]);
        free(resultadoSoma2[i]);
        free(resultadoSub2[i]);
        }

        free(m1);
        free(m2);
        free(resultadoSoma);
        free(resultadoSub);
        free(ma1);
        free(ma2);
        free(resultadoSoma2);
        free(resultadoSub2);

        /// LIBERAR MEMORIA PRODUTO_ESCALAR
        free(v1);
        free(v2);
        free(ve1);
        free(ve2);

        /// LIBERAR MEMORIA TRANSPOSTA
        for(int i=0;i<linhas;i++){
            free(matriz[i]);
        }
        free(matriz);

        /// LIBERAR MEMORIA HERMITIANA
        for(int i=0;i<linhas;i++){
            free (hermitiana[i]);
        }
        free(hermitiana);
        /// LIBERAR MEMORIA CONJUGADA
        for(int i=0;i<linhas;i++){
            free (conjugada[i]);
        }
        free(conjugada);

        /// LIBERAR MEMORIA PRODUTO_MATRICIAL
        for (int i = 0; i < linhas; i++) {
            free(matriz1[i]);
        }
        free(matriz1);

        for (int i = 0; i < colunas; i++) {
            free(matriz2[i]);
        }
        free(matriz2);

        for (int i = 0; i < linhas; i++) {
            free(resultadoProduto[i]);
        }
        free(resultadoProduto);


    return 0;
}
    /// FUNCAO IMPRIMIR MATRIZES
void imprimirMatriz(Complexo** matriz, int linhas, int colunas){
    for(int i=0; i<linhas; i++) {
        for(int j=0;j<colunas;j++) {
            printf("%.2f + %2.fi\t", matriz[i][j].real, matriz[i][j].imag);
        }
        printf("\n");
    }
}
    /// FUNCAO IMPRIMIR VETOR
void imprimirVetor(Complexo* vetor, int linhas){
    for(int i=0;i<linhas;i++){
        printf("%.2f + %.2fi\t", vetor[i].real,vetor[i].imag);
    }
    printf("\n");
}

    /// FUNCOES IMPLEMENTADAS

        /// FUNCAO SOMA
void somaMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSoma){
    for (int linhas=0;linhas<3; linhas++) {
        for (int colunas = 0; colunas< 3;colunas++) {
            resultadoSoma[linhas][colunas].real = m1[linhas][colunas].real + m2[linhas][colunas].real;
            resultadoSoma[linhas][colunas].imag = m1[linhas][colunas].imag + m2[linhas][colunas].imag;
        }
    }
}
        /// FUNCAO SUBTRACAO
void subtracaoMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSub){
    for (int linhas=0;linhas<3; linhas++) {
        for (int colunas = 0; colunas< 3;colunas++) {
            resultadoSub[linhas][colunas].real = m1[linhas][colunas].real - m2[linhas][colunas].real;
            resultadoSub[linhas][colunas].imag = m1[linhas][colunas].imag - m2[linhas][colunas].imag;
        }
    }
}
        /// FUNCAO PRODUTO_ESCALAR
Complexo produtoEscalar(Complexo* v1, Complexo* v2, int tamanho){
    Complexo vetoresultado;
    vetoresultado.real = 0;
    vetoresultado.imag = 0;
        for(int i=0;i<tamanho; i++){
            vetoresultado.real += v1[i].real * v2[i].real - v1[i].imag * v2[i].imag;
            vetoresultado.imag += v1[i].real * v2[i].imag - v1[i].imag * v2[i].real;
        }
    return vetoresultado;
}

Complexo** matrizTransposta(Complexo** matriz, int linhas, int colunas){
    Complexo** transposta = (Complexo**)malloc(colunas*sizeof(Complexo*));
    for(int i=0;i<colunas;i++){
        transposta[i]=(Complexo*)malloc(linhas*sizeof(Complexo));
            for(int j=0;j<linhas;j++){
                transposta[i][j].real = matriz[j][i].real;
                transposta[i][j].imag = matriz[j][i].imag;
        }
    }
    return transposta;
}

        /// FUNCAO HERMITIANA
Complexo** matrizHermitiana(Complexo** matriz, int linhas, int colunas) {
    Complexo** hermitiana = (Complexo*)malloc(linhas * sizeof(Complexo));
    for (int i = 0; i < linhas; i++) {
        hermitiana[i] = (Complexo*)malloc(colunas * sizeof(Complexo));
        for (int j = 0; j < colunas; j++) {
            hermitiana[i][j].real = matriz[j][i].real;
            hermitiana[i][j].imag = -matriz[j][i].imag;
        }
    }
    return hermitiana;
}
        /// FUNCAO CONJUGADA
Complexo** matrizConjugada(Complexo** matriz, int linhas, int colunas) {
    Complexo** conjugada = (Complexo*)malloc(linhas * sizeof(Complexo));
    for (int i = 0; i < linhas; i++) {
        conjugada[i] = (Complexo*)malloc(colunas * sizeof(Complexo));
        for (int j = 0; j < colunas; j++) {
            conjugada[i][j].real = matriz[i][j].real;
            conjugada[i][j].imag = -matriz[i][j].imag;
        }
    }
    return conjugada;
}

        /// FUNCAO PRODUT_MATRICIAL
void produtoMatricial(Complexo** mat1, Complexo** mat2, Complexo** resultado, int linhas1, int colunas1, int colunas2){
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j].real = 0;
            resultado[i][j].imag = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j].real += (mat1[i][k].real * mat2[k][j].real) - (mat1[i][k].imag * mat2[k][j].imag);
                resultado[i][j].imag += (mat1[i][k].real * mat2[k][j].imag) + (mat1[i][k].imag * mat2[k][j].real);
            }
        }
    }
}





