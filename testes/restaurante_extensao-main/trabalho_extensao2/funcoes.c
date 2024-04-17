#include "header.h"
#include <stdio.h>

void registrarVendaDiaria(VendaDiaria vendas[], int *numVendas) {
    if (*numVendas < 100) {
        printf("\nDigite a data da venda (dia mes ano): ");
        scanf("%d %d %d", &vendas[*numVendas].dia, &vendas[*numVendas].mes, &vendas[*numVendas].ano);

        printf("Digite o peso do item refeição: ");
        scanf("%f", &vendas[*numVendas].pesoRefeicao);

        printf("Digite o preço do item refeição: ");
        scanf("%f", &vendas[*numVendas].precoRefeicao);

        printf("É uma quentinha? (1 para sim, 0 para não): ");
        scanf("%d", &vendas[*numVendas].quentinha);

        if (vendas[*numVendas].quentinha) {
            vendas[*numVendas].valorTotal += 20.50; // preço fixo da quentinha + embalagem
        }

        printf("Digite o valor da bebida: ");
        scanf("%f", &vendas[*numVendas].valorBebida);

        printf("Digite a quantidade de bebidas: ");
        scanf("%d", &vendas[*numVendas].quantidadeBebida);

        vendas[*numVendas].valorTotal += vendas[*numVendas].pesoRefeicao * vendas[*numVendas].precoRefeicao; // valor total da refeição
        vendas[*numVendas].valorTotal += vendas[*numVendas].valorBebida * vendas[*numVendas].quantidadeBebida; // valor total das bebidas

        (*numVendas)++;
        printf("Venda diária registrada com sucesso!\n");
    } else {
        printf("Limite de vendas diárias atingido!\n");
    }
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

void gerarRelatorioMensal(VendaDiaria vendas[], int numVendas, Meses mes, int ano) {
    float totalMensal = 0;

    for (int i = 0; i < numVendas; i++) {
        if (vendas[i].mes == mes && vendas[i].ano == ano) {
            totalMensal += vendas[i].valorTotal;
        }
    }

    printf("\nRelatório Mensal (%02d/%04d):\n", mes, ano);
    printf("Valor total das vendas: R$ %.2f\n", totalMensal);
}

void gerarRelatorioAnual(VendaDiaria vendas[], int numVendas, int ano) {
    float totalAnual[12] = {0}; // Array para armazenar o total de vendas de cada mês

    for (int i = 0; i < numVendas; i++) {
        if (vendas[i].ano == ano) {
            totalAnual[vendas[i].mes - 1] += vendas[i].valorTotal; // Subtrai 1 porque o array começa em 0
        }
    }

    // Ordena o array em ordem decrescente
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (totalAnual[i] < totalAnual[j]) {
                float temp = totalAnual[i];
                totalAnual[i] = totalAnual[j];
                totalAnual[j] = temp;
            }
        }
    }

    printf("\nRelatório Anual (%04d):\n", ano);
    for (int i = 0; i < 12; i++) {
        printf("Mês %02d: R$ %.2f\n", i + 1, totalAnual[i]); // Adiciona 1 porque o array começa em 0
    }
}