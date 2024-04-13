#ifndef HEADER_H
#define HEADER_H

// Inclua aqui as bibliotecas necessárias, se houver

// Enumeração dos meses do ano
typedef enum {
    JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
} Meses;

// Struct para representar uma venda diária
typedef struct {
    int dia;
    Meses mes;
    int ano;
    float valorTotal;
    // Aqui você pode adicionar mais campos, se necessário, como os itens vendidos
} VendaDiaria;

// Protótipos das funções
void registrarVendaDiaria(VendaDiaria vendas[], int *numVendas);
void gerarRelatorioDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano);

#endif /* HEADER_H */
