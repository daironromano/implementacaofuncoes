///@file PSD_TELECOM_H
#ifndef PSD_TELECOM_H
#define PSD_TELECOM_H


    /// PROTÓTIPOS DAS FUNÇÕES

    int testeTodos(void);
    int* tx_data_read(const char* nome_arquivo, int* num_elementos);
    void rx_data_write(const int* vetor, int num_elementos, const char* nome_arquivo);


#endif
