#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100
#define PRECO_QUENTINHA 20.00
#define PRECO_EMBALAGEM 0.50
#define PESO_REFEICAO 0.5
#define PRECO_REFEICAO 10.00
#define PRECO_BEBIDA 5.00

typedef enum { REFEICAO, QUENTINHA, BEBIDA } TipoItem;
typedef enum { JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO } Meses;

const char *nomes_itens[] = { "Refeição", "Quentinha", "Bebida" };
const char *nomes_meses[] = { "", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };

typedef struct {
    TipoItem tipo;
    double peso;
    double preco;
    int quantidade;
} Item;

typedef struct {
    Item itens[MAX];
    int total_itens;
    double total_vendas;
    Meses mes;
} Venda;

typedef struct {
    double total_vendas;
    Meses mes;
} Mes;

Venda vendas[MAX];
Mes meses[12];
int total_vendas = 0;

void registrar_venda() {
    char opcao;
    char mes[20];
    printf("Digite o mês da venda (Janeiro-Dezembro): ");
    scanf("%s", mes);
    int mes_num = -1;
    for(int i = 1; i <= 12; i++) {
        if(strcmp(mes, nomes_meses[i]) == 0) {
            mes_num = i;
            break;
        }
    }
    if(mes_num == -1) {
        printf("Mês inválido. Por favor, insira um valor entre Janeiro e Dezembro.\n");
        return;
    }
    do {
        Item item;
        printf("Digite o tipo do item (0 - Refeição, 1 - Quentinha, 2 - Bebida): ");
        scanf("%d", &item.tipo);
        switch(item.tipo) {
            case REFEICAO:
                item.peso = PESO_REFEICAO;
                item.preco = PRECO_REFEICAO;
                break;
            case QUENTINHA:
                item.peso = 1;
                item.preco = PRECO_QUENTINHA + PRECO_EMBALAGEM;
                break;
            case BEBIDA:
                item.peso = 1;
                item.preco = PRECO_BEBIDA;
                break;
        }
        printf("Digite a quantidade do item: ");
        scanf("%d", &item.quantidade);
        vendas[total_vendas].itens[vendas[total_vendas].total_itens++] = item;
        printf("Item: %s\n", nomes_itens[item.tipo]);
        printf("Preço: %.2f\n", item.preco);
        printf("Peso: %.2f\n", item.peso);
        printf("Quantidade: %d\n", item.quantidade);
        printf("Total: %.2f\n", item.preco * item.quantidade);
        printf("Deseja adicionar mais itens? (S/N): ");
        scanf(" %c", &opcao);
        system("CLS");
        meses[mes_num-1].total_vendas += item.preco * item.quantidade;
        meses[mes_num-1].mes = mes_num;
    } while (opcao == 'S' || opcao == 's');
    vendas[total_vendas].mes = mes_num;
    total_vendas++;
}

void ordenar_vendas() {
    for(int i = 0; i < total_vendas - 1; i++) {
        int max_idx = i;
        double max_total = 0;
        for(int j = i; j < total_vendas; j++) {
            double total = 0;
            for(int k = 0; k < vendas[j].total_itens; k++) {
                total += vendas[j].itens[k].preco * vendas[j].itens[k].quantidade;
            }
            if(total > max_total) {
                max_total = total;
                max_idx = j;
            }
        }
        
        Venda temp = vendas[i];
        vendas[i] = vendas[max_idx];
        vendas[max_idx] = temp;
    }
}

void relatorio_diario() {
    double total_vendas_diarias = 0;
    for(int j = 0; j < total_vendas; j++) { 
        for(int i = 0; i < vendas[j].total_itens; i++) { 
            total_vendas_diarias += vendas[j].itens[i].preco * vendas[j].itens[i].quantidade;
            printf("Item: %s\n", nomes_itens[vendas[j].itens[i].tipo]);
            printf("Preço: %.2f\n", vendas[j].itens[i].preco);
            printf("Peso: %.2f\n", vendas[j].itens[i].peso);
            printf("Quantidade: %d\n", vendas[j].itens[i].quantidade);
            printf("Total: %.2f\n", vendas[j].itens[i].preco * vendas[j].itens[i].quantidade);
        }
    }
    printf("Total de vendas diárias: R$ %.2f\n", total_vendas_diarias);
    
}

void ordenar_meses() {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 11 - i; j++) {
            if(meses[j].total_vendas < meses[j + 1].total_vendas) {
                Mes temp = meses[j];
                meses[j] = meses[j + 1];
                meses[j + 1] = temp;
            }
        }
    }
}

void relatorio_mensal() {
    char mes[20];
    printf("Digite o mês que deseja ver o relatório (Janeiro-Dezembro): ");
    scanf("%s", mes);
    int mes_num = -1;
    for(int i = 1; i <= 12; i++) {
        if(strcmp(mes, nomes_meses[i]) == 0) {
            mes_num = i;
            break;
            printf("\nPressione qualquer tecla para voltar ao menu...");
    	
        }
    }
    if(mes_num == -1) {
        printf("Mês inválido. Por favor, insira um valor entre Janeiro e Dezembro.\n");
        return;
    }
    printf("Mês: %s\n", nomes_meses[mes_num]);
    printf("Total de vendas: R$ %.2f\n", meses[mes_num-1].total_vendas);
    for(int j = 0; j < total_vendas; j++) {
        if(vendas[j].mes == mes_num) {
            for(int i = 0; i < vendas[j].total_itens; i++) {
                printf("Item: %s\n", nomes_itens[vendas[j].itens[i].tipo]);
                printf("Preço: %.2f\n", vendas[j].itens[i].preco);
                printf("Peso: %.2f\n", vendas[j].itens[i].peso);
                printf("Quantidade: %d\n", vendas[j].itens[i].quantidade);
                printf("Total: %.2f\n", vendas[j].itens[i].preco * vendas[j].itens[i].quantidade);
                printf("\nPressione qualquer tecla para voltar ao menu...");
		    
            }
        }
    }
}


void relatorio_anual() {
    ordenar_meses();
    for(int i = 0; i < 12; i++) {
        if(meses[i].total_vendas > 0) {
            printf("Mês: %s\n", nomes_meses[meses[i].mes]);
            printf("Total de vendas: R$ %.2f\n", meses[i].total_vendas);
            for(int j = 0; j < total_vendas; j++) {
                if(vendas[j].mes == meses[i].mes) {
                    for(int k = 0; k < vendas[j].total_itens; k++) {
                        printf("Item: %s\n", nomes_itens[vendas[j].itens[k].tipo]);
                        printf("Preço: %.2f\n", vendas[j].itens[k].preco);
                        printf("Peso: %.2f\n", vendas[j].itens[k].peso);
                        printf("Quantidade: %d\n", vendas[j].itens[k].quantidade);
                        printf("Total: %.2f\n", vendas[j].itens[k].preco * vendas[j].itens[k].quantidade);
                        printf("\nPressione qualquer tecla para voltar ao menu...");
    					
                    }
                }
            }
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    for(int i = 0; i < 12; i++) {
        meses[i].total_vendas = 0;
        meses[i].mes = i + 1;
    }

    do {
        printf("1. Registrar venda\n");
        printf("2. Gerar relatório diário\n");
        printf("3. Gerar relatório mensal\n");
        printf("4. Gerar relatório anual\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            	
                registrar_venda();
                break;
            case 2:
            	ordenar_vendas();
                relatorio_diario();
                break;
            case 3:
            	ordenar_vendas();
                relatorio_mensal();
                break;
            case 4:
            	ordenar_meses();
                relatorio_anual();
                break;
        }
    } while (opcao != 5);
    system("PAUSE");
    return 0;
}




