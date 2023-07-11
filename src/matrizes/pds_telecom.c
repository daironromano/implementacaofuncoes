#include <stdio.h>
#include <stdlib.h>

int* tx_data_read(const char* nome_arquivo, int* num_elementos);
void rx_data_write(const int* vetor, int num_elementos, const char* nome_arquivo);

int main() {
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

        // Escrever os bytes originais em um arquivo binário
        rx_data_write(vetor, num_elementos, nome_arquivo_saida);

        // Liberar memória alocada
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

    // Calcular o número de elementos do vetor
    *num_elementos = tamanho * 4;

    // Alocar memória para o vetor
    int* vetor_inteiros = (int*)malloc(*num_elementos * sizeof(int));
    if (vetor_inteiros == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return NULL;
    }

    // Ler o conteúdo do arquivo
    char* conteudo = (char*)malloc((tamanho + 1) * sizeof(char));
    if (conteudo == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        free(vetor_inteiros);
        return NULL;
    }

    fread(conteudo, sizeof(char), tamanho, arquivo);
    conteudo[tamanho] = '\0';
    fclose(arquivo);

    // Converter cada byte em 4 números inteiros entre 0 e 3
    int posicao_vetor = 0;
    for (int i = 0; i < tamanho; i++) {
        unsigned char byte = conteudo[i];
        vetor_inteiros[posicao_vetor++] = (byte >> 6) & 3;
        vetor_inteiros[posicao_vetor++] = (byte >> 4) & 3;
        vetor_inteiros[posicao_vetor++] = (byte >> 2) & 3;
        vetor_inteiros[posicao_vetor++] = byte & 3;
    }

    // Liberar memória alocada
    free(conteudo);

    return vetor_inteiros;
}

void rx_data_write(const int* vetor, int num_elementos, const char* nome_arquivo) {
    FILE* arquivo_saida = fopen(nome_arquivo, "wb");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    unsigned char byte = 0;
    int contador_bits = 0;

    for (int i = 0; i < num_elementos; i++) {
        int valor = vetor[i];

        if (valor < 0 || valor > 3) {
            printf("Valor inválido encontrado no vetor de entrada.\n");
            fclose(arquivo_saida);
            return;
        }

        byte |= valor << ((3 - contador_bits) * 2);
        contador_bits++;

        if (contador_bits == 4) {
            fputc(byte, arquivo_saida);
            byte = 0;
            contador_bits = 0;
        }
    }

    // Se ainda houver bits restantes no último byte
    if (contador_bits > 0) {
        fputc(byte, arquivo_saida);
    }

    fclose(arquivo_saida);
}
