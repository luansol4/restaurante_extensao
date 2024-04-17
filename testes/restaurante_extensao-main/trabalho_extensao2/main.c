#include "header.h"
#include <stdio.h>

int main() {
    VendaDiaria vendas[100];
    int numVendas = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Registrar venda diária\n");
        printf("2. Gerar relatório diário\n");
        printf("3. Gerar relatório mensal\n");
        printf("4. Gerar relatório anual\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarVendaDiaria(vendas, &numVendas);
                break;
            case 2:
                int dia, mes, ano;
                printf("Digite a data (dia mes ano): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                gerarRelatorioDiario(vendas, numVendas, dia, (Meses)mes, ano);
                break;
            case 3:
                printf("Digite o mês e o ano (mes ano): ");
                scanf("%d %d", &mes, &ano);
                gerarRelatorioMensal(vendas, numVendas, (Meses)mes, ano);
                break;
            case 4:
                printf("Digite o ano: ");
                scanf("%d", &ano);
                gerarRelatorioAnual(vendas, numVendas, ano);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}