#include "header.h"
#include <stdio.h>


// Definição das estruturas
typedef enum {
    JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
} Meses;

typedef struct {
    int dia;
    Meses mes;
    int ano;
    float valorTotal;
} VendaDiaria;

// Funções
void registrarVendaDiaria(VendaDiaria vendas[], int *numVendas);
void calcularTotalDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano);
void gerarRelatorioDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano);

int main() {
    // Array para armazenar as vendas diárias
    VendaDiaria vendas[100];
    int numVendas = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Registrar venda diária\n");
        printf("2. Gerar relatório diário\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarVendaDiaria(vendas, &numVendas);
                break;
            case 2:
                gerarRelatorioDiario(vendas, numVendas);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

void registrarVendaDiaria(VendaDiaria vendas[], int *numVendas) {
    // Implementação da função para registrar uma venda diária
}

void calcularTotalDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano) {
    // Implementação da função para calcular o valor total das vendas diárias
}

void gerarRelatorioDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano) {
    // Implementação da função para gerar o relatório diário
}
