#include <stdio.h>
#include <stdlib.h>

/// PROTOTIPOS DAS FUNCOES
void imprimirMatriz(int** matriz);
void imprimirVetor(int* vetor);
void somaMatriz(int** m1, int** m2, int** resultadoSoma);
void subtracaoMatriz(int** m1, int** m2, int** resultadoSub);
int produtoEscalar(int* v1, int* v2, int tamanho);

///ESTRUTURA DE DADOS COMPLEXO
    typedef struct{
        float real;
        float imag;
    } MatrizComplexo;

/// FUNCAO PRINCIPAL
int main(){
    /// TESTE MATRIZ SOMA E SUBTRACAO
        /// ALOCACAO DE MEMORIA
         int linhas = 3;
         int colunas =3;

        int** m1 = (int**)malloc(sizeof(int*) * linhas);
        int** m2 = (int**)malloc(sizeof(int*) * linhas);
        int** resultadoSoma = (int**)malloc(sizeof(int*) * linhas);
        int** resultadoSub = (int**)malloc(sizeof(int*) * linhas);

        for(int i=0;i<linhas;i++){
            m1[i] = (int*)malloc(sizeof(int) * colunas);
            m2[i] = (int*)malloc(sizeof(int) * colunas);
            resultadoSoma[i] = (int*)malloc(sizeof(int) * colunas);
            resultadoSub[i] = (int*)malloc(sizeof(int) * colunas);
        }

        m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
        m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
        m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

        m2[0][0] = 1; m2[0][1] = 2; m2[0][2] = 3;
        m2[1][0] = 4; m2[1][1] = 5; m2[1][2] = 6;
        m2[2][0] = 7; m2[2][1] = 8; m2[2][2] = 9;

        printf("======TESTE DA OPERACAO SOMA======\n");
        printf("Operando A: \n");
        imprimirMatriz(m1);
        printf("Operando B: \n");
        imprimirMatriz(m2);

        printf("Resultado: \n");
        somaMatriz(m1, m2, resultadoSoma);
        imprimirMatriz(resultadoSoma);
printf("\n");
    /// TESTE MATRIZ SUBTRACAO
        printf("======TESTE DA OPERACAO SUBTRACAO======\n");
        printf("Operando A: \n");
        imprimirMatriz(m1);
        printf("Operando B: \n");
        imprimirMatriz(m2);
        printf("Resultado\n");
        subtracaoMatriz(m1, m2, resultadoSub);
        imprimirMatriz(resultadoSub);
printf("\n");
    /// TESTE PRODUTO_ESCALAR
        printf("======TESTE DA OPERACAO PRODUTO_ESCALAR======\n");
        int* v1 = (int*)malloc(3*sizeof(int));
        int* v2 = (int*)malloc(3*sizeof(int));

        v1[0] = 4;  v2[0] = 8;
        v1[1] = 7;  v2[1] = 14;
        v1[2] = 2;  v2[2] = 4;

        printf("Operando A: \n");
        imprimirVetor(v1);
        printf("Operando B: \n");
        imprimirVetor(v2);
        int vetoresultado = produtoEscalar(v1,v2,3);
        printf("Resultado:\n%i", vetoresultado);

    /// LIBERAR MEMORIA
    for(int i=0;i<3;i++){
        free(m1[i]);
        free(m2[i]);
        free(resultadoSoma[i]);
        free(resultadoSub[i]);
    }
    free(m1);
    free(m2);
    free(resultadoSoma);
    free(resultadoSub);
    free(v1);
    free(v2);

    return 0;
}
/// FUNCAO IMPRIMIR MATRIZES
void imprimirMatriz(int** matriz){
    for(int linhas=0; linhas<3; linhas++) {
        for(int colunas=0;colunas<3;colunas++) {
            printf("%2i ", matriz[linhas][colunas]);
        }
        printf("\n");
    }
}
    /// FUNCAO IMPRIMIR VETOR
void imprimirVetor(int* vetor){
    for(int i=0;i<3;i++){
        printf("%2i ", vetor[i]);
    }
    printf("\n");
}

/// FUNCOES IMPLEMENTADAS
    /// FUNCAO SOMA
void somaMatriz(int** m1, int** m2, int** resultadoSoma){
    for (int linhas=0;linhas<3; linhas++) {
        for (int colunas = 0; colunas< 3;colunas++) {
            resultadoSoma[linhas][colunas] = m1[linhas][colunas] + m2[linhas][colunas];
        }
    }

}
    /// FUNCAO SUBTRACAO
void subtracaoMatriz(int** m1, int** m2, int** resultadoSub){
    for (int linhas=0;linhas<3; linhas++) {
        for (int colunas = 0; colunas< 3;colunas++) {
            resultadoSub[linhas][colunas] = m1[linhas][colunas] - m2[linhas][colunas];
        }
    }
}
    /// FUNCAO PRODUTO_ESCALAR
int produtoEscalar(int* v1, int* v2, int tamanho){
    int vetoresultado = 0;
        for(int i=0;i<tamanho; i++){
            vetoresultado += v1[i] * v2[i];
        }
    return vetoresultado;
}
