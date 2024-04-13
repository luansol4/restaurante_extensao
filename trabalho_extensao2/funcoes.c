#include "header.h"
#include <stdio.h>

void registrarVendaDiaria(VendaDiaria vendas[], int *numVendas) {
    if (*numVendas < 100) {
        printf("\nDigite a data da venda (dia mes ano): ");
        scanf("%d %d %d", &vendas[*numVendas].dia, &vendas[*numVendas].mes, &vendas[*numVendas].ano);

        // Aqui você iria registrar os itens vendidos, mas como é um esboço, vamos pular essa parte

        (*numVendas)++;
        printf("Venda diária registrada com sucesso!\n");
    } else {
        printf("Limite de vendas diárias atingido!\n");
    }
}

void calcularTotalDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano) {
    float totalDiario = 0;

    for (int i = 0; i < numVendas; i++) {
        if (vendas[i].dia == dia && vendas[i].mes == mes && vendas[i].ano == ano) {
            totalDiario += vendas[i].valorTotal;
        }
    }

    printf("\nRelatório Diário (%02d/%02d/%04d):\n", dia, mes, ano);
    printf("Valor total das vendas: R$ %.2f\n", totalDiario);
}

void gerarRelatorioDiario(VendaDiaria vendas[], int numVendas, int dia, Meses mes, int ano) {
    float totalDiario = 0;

    for (int i = 0; i < numVendas; i++) {
        if (vendas[i].dia == dia && vendas[i].mes == mes && vendas[i].ano == ano) {
            totalDiario += vendas[i].valorTotal;
        }
    }

    printf("\nRelatório Diário (%02d/%02d/%04d):\n", dia, mes, ano);
    printf("Valor total das vendas: R$ %.2f\n", totalDiario);
}
