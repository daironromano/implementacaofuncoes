#ifndef matrizes_h
#define matrizes_h

int main()
{
    //ESTRUTURA DE DADOS
    typedef struct{
        float real;
        float imag;
    } MatrizComplexo;

    //ASSINATURAS
    void transposta();
    void conjugada();
    void hermitiana();
    void somaMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSoma);
    void subtracaoMatriz(Complexo** m1, Complexo** m2, Complexo** resultadoSub);
    Complexo produtoEscalar(Complexo* v1, Complexo* v2, int tamanho);
    void produtoMatricial();


    return 0;
}

#endif
