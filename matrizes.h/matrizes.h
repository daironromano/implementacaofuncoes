#include <stdio.h>
#include <stdlib.h>

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
    } matriz_complexo;

    //assinatura das funções matrizes.c

    void transposta();
    void conjugada();
    void hermitiana();
    void soma();
    void subtracao();
    void produtoEscalar();
    void produtoMatricial();

    return 0;
}
