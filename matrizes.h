#ifndef MATRIZES_H
#define MATRIZES_H

    ///ESTRUTURA DE DADOS COMPLEXO
    /** Na estrutura, e' declarado quatros variaveis, sendo duas do tipo float(para os numeros complexos),
    e duas do tipo int, para matrizes e vetores, tal qual solicitado em documento pelos professores.**/

    typedef struct{
        float real;
        float imag;
        int linhas;
        int colunas;
    } Complexo;

    ///ASSINATURAS

    /** Aqui estão as assinaturas de todas as funções criadas, tanto as solicitadas pelos professores,
    quanto as que achamos necessário criar fora a parte, para conseguir concluir a tarefa com exito.**/

    void imprimirMatriz(Complexo** matriz, int linhas, int colunas);
    void imprimirVetor(Complexo* vetor, int linhas);
    Complexo** matrizTransposta(Complexo** matriz, int linhas, int colunas);
    Complexo** matrizConjugada(Complexo** matriz, int linhas, int colunas);
    Complexo** matrizHermitiana(Complexo** matriz, int linhas, int colunas);
    void somaMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSoma);
    void subtracaoMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSub);
    Complexo produtoEscalar(Complexo* v1, Complexo* v2, int tamanho);
    void produtoMatricial(Complexo** mat1, Complexo** mat2, Complexo** resultado, int linhas1, int colunas1, int colunas2);
    void testeTodos(void);

#endif

