#ifndef matrizes_h
#define matrizes_h

int main()
{
    //ESTRUTURA DE DADOS
    typedef struct{
        float real;
        float imag;
    } Complexo;

    //ASSINATURAS
    Complexo** matrizTransposta(Complexo** matriz, int linhas, int colunas);
    Complexo** matrizConjugada(Complexo** matriz, int linhas, int colunas);
    Complexo** matrizHermitiana(Complexo** matriz, int linhas, int colunas);
    void somaMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSoma);
    void subtracaoMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSub);
    Complexo produtoEscalar(Complexo* v1, Complexo* v2, int tamanho);
    void produtoMatricial(Complexo** mat1, Complexo** mat2, Complexo** resultado, int linhas1, int colunas1, int colunas2);



    return 0;
}

#endif
