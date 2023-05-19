#ifndef MATRIZES_H
#define MATRIZES_H

    ///ESTRUTURA DE DADOS COMPLEXO
    typedef struct{
        float real;
        float imag;
    } Complexo;


    ///ASSINATURAS
    void imprimirMatriz(Complexo** matriz, int linhas, int colunas);
    void imprimirVetor(Complexo* vetor, int linhas);
    Complexo** matrizTransposta(Complexo** matriz, int linhas, int colunas);
    Complexo** matrizConjugada(Complexo** matriz, int linhas, int colunas);
    Complexo** matrizHermitiana(Complexo** matriz, int linhas, int colunas);
    void somaMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSoma);
    void subtracaoMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSub);
    Complexo produtoEscalar(Complexo* v1, Complexo* v2, int tamanho);
    void produtoMatricial(Complexo** mat1, Complexo** mat2, Complexo** resultado, int linhas1, int colunas1, int colunas2);

#endif
