#ifndef HEADER_H
#define HEADER_H

typedef enum {
    JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
} Meses;

typedef struct {
    int dia;
    Meses mes;
    int ano;
    float valorTotal;
    float pesoRefeicao; // peso do item refeição
    float precoRefeicao; // preço do item refeição
    int quentinha; // 1 se for quentinha, 0 caso contrário
    float valorBebida; // valor da bebida
    int quantidadeBebida; // quantidade de bebidas
} VendaDiaria;

void registrarVendaDiaria(VendaDiaria vendas[], int *numVendas);
void gerarRelatorioDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano);
void gerarRelatorioMensal(VendaDiaria vendas[], int numVendas, Meses mes, int ano);
void gerarRelatorioAnual(VendaDiaria vendas[], int numVendas, int ano);

#endif /* HEADER_H */