#ifndef matrizes_h
#define matrizes_h

int main()
{
    //estrutura de dados parte real e imaginaria
    typedef struct{

        float real;
        float imag;

    } complexo;

    //estrutura de dados vetores e matrizes
    typedef struct {

        int nlinhas;
        int mcolunas;
        complexo **dados;
    } matrizComplexo;

    //assinatura das funções matrizes.c

    void transposta();
    void conjugada();
    void hermitiana();
    void somaMatriz(int m1[3][3], int m2[3][3], int resultado[3][3], int linhas, int colunas);
    void subtracaoMatriz(int m1[3][3], int m2[3][3], int resultado[3][3], int linhas, int colunas);
    void produtoEscalar();
    void produtoMatricial();


    return 0;
}

#endif /* matrizes_h */
