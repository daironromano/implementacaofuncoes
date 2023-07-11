#include <stdio.h>
#include <stdlib.h>
#include "pds_telecom.h"


int testeTodos(void) {
    const char* nome_arquivo_entrada = "arquivo_entrada.txt";
    const char* nome_arquivo_saida = "arquivo_saida.bin";
    int num_elementos;
    int* vetor = tx_data_read(nome_arquivo_entrada, &num_elementos);

    if (vetor != NULL) {
        // Imprimir os valores separados
        for (int i = 0; i < num_elementos; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");

        // Escrever os bytes originais em um arquivo bin�rio
        rx_data_write(vetor, num_elementos, nome_arquivo_saida);

        // Liberar mem�ria alocada
        free(vetor);
    }

    return 0;
}

int* tx_data_read(const char* nome_arquivo, int* num_elementos) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    // Calcular o n�mero de elementos do vetor
    *num_elementos = tamanho * 4;

    // Alocar mem�ria para o vetor
    int* vetor_inteiros = (int*)malloc(*num_elementos * sizeof(int));
    if (vetor_inteiros == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        fclose(arquivo);
        return NULL;
    }

    // Ler o conte�do do arquivo
    char* conteudo = (char*)malloc((tamanho + 1) * sizeof(char));
    if (conteudo == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        fclose(arquivo);
        free(vetor_inteiros);
        return NULL;
    }

    fread(conteudo, sizeof(char), tamanho, arquivo);
    conteudo[tamanho] = '\0';
    fclose(arquivo);

    // Converter cada byte em 4 n�meros inteiros entre 0 e 3
    int posicao_vetor = 0;
    for (int i = 0; i < tamanho; i++) {
        unsigned char byte = conteudo[i];
        vetor_inteiros[posicao_vetor++] = (byte >> 6) & 3;
        vetor_inteiros[posicao_vetor++] = (byte >> 4) & 3;
        vetor_inteiros[posicao_vetor++] = (byte >> 2) & 3;
        vetor_inteiros[posicao_vetor++] = byte & 3;
    }

    // Liberar mem�ria alocada
    free(conteudo);

    return vetor_inteiros;
}

void rx_data_write(const int* vetor, int num_elementos, const char* nome_arquivo) {
    FILE* arquivo_saida = fopen(nome_arquivo, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de sa�da.\n");
        return;
    }

    // Converter os n�meros inteiros em bytes
    for (int i = 0; i < num_elementos; i += 4) {
        unsigned char byte = (vetor[i] << 6) | (vetor[i + 1] << 4) | (vetor[i + 2] << 2) | vetor[i + 3];
        fputc(byte, arquivo_saida);
    }

    fclose(arquivo_saida);
}
