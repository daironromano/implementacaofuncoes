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
    void somaMatriz(int m1[3][3], int m2[3][3], int resultado[3][3]);
    void subtracaoMatriz(int m1[3][3], int m2[3][3], int resultado[3][3]);
    void produtoEscalar();
    void produtoMatricial();


    return 0;
}

#endif
