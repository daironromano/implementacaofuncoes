#include <stdio.h>
#include <stdlib.h>

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
/// FUNCAO PRINCIPAL
int main(){
    /// TESTE MATRIZ SOMA E SUBTRACAO
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
        /// ATRIBUINDO VALORES PARA O TESTE
        m1[0][0].real = +4; m1[0][0].imag = +4;
        m1[0][1].real = 3;  m1[0][1].imag = 4;
        m1[0][2].real = 2;  m1[0][2].imag = 6;
        m2[0][0].real = -5; m2[0][0].imag = 2;
        m2[0][1].real = 3;  m2[0][1].imag = 4;
        m2[0][2].real = 1;  m2[0][2].imag = 2;

        m1[1][0].real = 1; m1[1][0].imag = 2;
        m1[1][1].real = 3; m1[1][1].imag = 4;
        m1[1][2].real = 5; m1[1][2].imag = 6;

        m2[1][0].real = 2; m2[1][0].imag = 3;
        m2[1][1].real = 4; m2[1][1].imag = 5;
        m2[1][2].real = 6; m2[1][2].imag = 7;

        m1[2][0].real = 7; m1[2][0].imag = 8;
        m1[2][1].real = 9; m1[2][1].imag = 10;
        m1[2][2].real = 11; m1[2][2].imag = 12;

        m2[2][0].real = 8; m2[2][0].imag = 9;
        m2[2][1].real = 10; m2[2][1].imag = 11;
        m2[2][2].real = 12; m2[2][2].imag = 13;

        printf("======TESTE DA OPERACAO SOMA======\n");
        printf("Operando A: \n");
        imprimirMatriz(m1, linhas, colunas);
        printf("Operando B: \n");
        imprimirMatriz(m2, linhas, colunas);

        printf("Resultado: \n");
        somaMatriz(m1, m2, resultadoSoma);
        imprimirMatriz(resultadoSoma, linhas, colunas);
printf("\n");
    /// TESTE MATRIZ SUBTRACAO
        printf("======TESTE DA OPERACAO SUBTRACAO======\n");
        printf("Operando A: \n");
        imprimirMatriz(m1, linhas, colunas);
        printf("Operando B: \n");
        imprimirMatriz(m2, linhas, colunas);
        printf("Resultado\n");
        subtracaoMatriz(m1, m2, resultadoSub);
        imprimirMatriz(resultadoSub, linhas, colunas);
printf("\n");
    /// TESTE PRODUTO_ESCALAR
        /// /// ALOCACAO DE MEMORIA
        Complexo* v1 = (Complexo*)malloc(3*sizeof(Complexo));
        Complexo* v2 = (Complexo*)malloc(3*sizeof(Complexo));

        printf("======TESTE DA OPERACAO PRODUTO_ESCALAR======\n");
        v1[0].real = 4;  v1[0].imag = 8;
        v1[1].real = 7;  v1[1].imag = 14;
        v1[2].real = 2;  v1[2].imag = 4;

        v2[0].real = 4;  v2[0].imag = 8;
        v2[1].real = 7;  v2[1].imag = 14;
        v2[2].real = 2;  v2[2].imag = 4;

        printf("Operando A: \n");
        imprimirVetor(v1, linhas);
        printf("Operando B: \n");
        imprimirVetor(v2, linhas);
        Complexo vetoresultado = produtoEscalar(v1,v2,3);
        printf("Resultado:\n%.2f + %.2fi \n", vetoresultado.real, vetoresultado.imag);


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
