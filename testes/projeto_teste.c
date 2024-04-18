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

const char *nomes_itens[] = { "RefeiÃ§Ã£o", "Quentinha", "Bebida" };
const char *nomes_meses[] = { "", "Janeiro", "Fevereiro", "MarÃ§o", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };

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
double total_vendas_anuais[12] = {0};


void registrar_venda() {
	int mes_num;
	
	setlocale(LC_ALL, "Portuguese"); // Acentuação Gráfica
	
    printf("Digite o número do mês da venda (1-12): ");
    scanf("%d", &mes_num);
    if(mes_num < 1 || mes_num > 12) {
        printf("Número do mÃªs invÃ¡lido. Por favor, insira um valor entre 1 e 12.\n");
        return;
    }
    char opcao;

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
        printf("VENDA REGISTRADA COM SUCESSO!\n");
        system("PAUSE");
        meses[mes_num-1].total_vendas += item.preco * item.quantidade;
        meses[mes_num-1].mes = mes_num;
        vendas[total_vendas].total_vendas += item.preco * item.quantidade;
    } while (opcao == 'S' || opcao == 's');
    vendas[total_vendas].mes = mes_num;
    total_vendas++;
}

void relatorio_diario() {
	
	setlocale(LC_ALL, "Portuguese"); // Acentuação Gráfica
	
	printf("+------------------------------+\n");
	printf("|     RETLATÓRIO DIÁRIO 2023  |\n");
	printf("*------------------------------*\n");
    double total_vendas_diarias = 0;
    for(int j = 0; j < total_vendas; j++) { 
        for(int i = 0; i < vendas[j].total_itens; i++) { 
            total_vendas_diarias += vendas[j].itens[i].preco * vendas[j].itens[i].quantidade;
            printf("| Item: %s\n", nomes_itens[vendas[j].itens[i].tipo]);
            printf("| Preço: %.2f\n", vendas[j].itens[i].preco);
            printf("| Peso: %.2f\n", vendas[j].itens[i].peso);
            printf("| Quantidade: %d\n", vendas[j].itens[i].quantidade);
            printf("| Total: %.2f\n", vendas[j].itens[i].preco * vendas[j].itens[i].quantidade);
            printf("*------------------------------*\n"); 
        }
    }
    printf("| Total de vendas diárias: R$ %.2f\n", total_vendas_diarias);
    printf("*\n");
    system("PAUSE");
    system("CLS");
}


void relatorio_mensal() {
    int mes_num;
    
    setlocale(LC_ALL, "Portuguese"); // Acentuação Gráfica
    
    printf("Digite o número do mês que deseja ver o relatório (1-12): ");
    scanf("%d", &mes_num);
    if(mes_num < 1 || mes_num > 12) {
        printf("Número do mês inválido. Por favor, insira um valor entre 1 e 12.\n");
        return;
    }
    printf("+------------------------------+\n");
	printf("|     RETLATÓRIO MENSAL 2023   |\n");
	printf("*------------------------------*\n");
    printf("| MÃªs: %s\n", nomes_meses[mes_num]);
    printf("| Total de vendas: R$ %.2f\n", meses[mes_num-1].total_vendas);
    int venda_encontrada = 0;
    for(int j = 0; j < total_vendas; j++) {
        if(vendas[j].mes == mes_num) {
            venda_encontrada = 1;
            for(int i = 0; i < vendas[j].total_itens; i++) {
                printf("| Item: %s\n", nomes_itens[vendas[j].itens[i].tipo]);
                printf("| Preço: %.2f\n", vendas[j].itens[i].preco);
                printf("| Peso: %.2f\n", vendas[j].itens[i].peso);
                printf("| Quantidade: %d\n", vendas[j].itens[i].quantidade);
                printf("| Total: %.2f\n", vendas[j].itens[i].preco * vendas[j].itens[i].quantidade);
                printf("*\n");
            }
        }
    }
    if(!venda_encontrada) {
        printf("| Item: --\n");
        printf("| Preço: --\n");
        printf("| Peso: --\n");
        printf("| Quantidade: --\n");
        printf("| Nenhuma venda foi registrada neste mês.\n");
        printf("| Total: --\n");
        printf("*\n");
    }
    system("PAUSE");
    system("CLS");
}
void ordenar_indices(double vendas[], int indices[], int esquerda, int direita) {
    int i = esquerda, j = direita;
    double pivo = vendas[(esquerda + direita) / 2];
    while (i <= j) {
        while (vendas[i] > pivo)
            i++;
        while (vendas[j] < pivo)
            j--;
        if (i <= j) {
            
            double temp_vendas = vendas[i];
            vendas[i] = vendas[j];
            vendas[j] = temp_vendas;
            
            
            int temp_indice = indices[i];
            indices[i] = indices[j];
            indices[j] = temp_indice;
            
            i++;
            j--;
        }
    }
    if (esquerda < j)
        ordenar_indices(vendas, indices, esquerda, j);
    if (i < direita)
        ordenar_indices(vendas, indices, i, direita);
}

void ordenar_meses(int indices[], Mes meses[]) {
    
    for (int i = 0; i < 11; i++) {
        int max_index = i;
        for (int j = i + 1; j < 12; j++) {
            if (meses[indices[j]].total_vendas > meses[indices[max_index]].total_vendas) {
                max_index = j;
            }
        }
        
        int temp = indices[i];
        indices[i] = indices[max_index];
        indices[max_index] = temp;
    }
}


void relatorio_anual() {
    int indices_ordenados[12];
    for (int i = 0; i < 12; i++) {
        indices_ordenados[i] = i;
    }
    
    setlocale(LC_ALL, "Portuguese"); // Acentuação Gráfica
    
    ordenar_meses(indices_ordenados, meses);

    printf("+-----------------------------+\n");
    printf("|     RELATÓRIO ANUAL 2023    |\n");
    for(int i = 0; i < 12; i++) {
        int mes_index = indices_ordenados[i]; // Obter o Ã­ndice do mÃªs ordenado
        int mes_num = meses[mes_index].mes;
        printf("*-----------------------------*\n");
        printf("| Mês: %s\n", nomes_meses[mes_num]);
        printf("| Total de vendas: R$ %.2f\n", meses[mes_index].total_vendas); 
        int venda_encontrada = 0;
        for(int j = 0; j < total_vendas; j++) {
            if(vendas[j].mes == mes_num) {
                venda_encontrada = 1;
                for(int k = 0; k < vendas[j].total_itens; k++) {
                    printf("| Item: %s\n", nomes_itens[vendas[j].itens[k].tipo]);
                    printf("| Preço: %.2f\n", vendas[j].itens[k].preco);
                    printf("| Peso: %.2f\n", vendas[j].itens[k].peso);
                    printf("| Quantidade: %d\n", vendas[j].itens[k].quantidade);
                    printf("| Total: %.2f\n", vendas[j].itens[k].preco * vendas[j].itens[k].quantidade);
                    printf("*\n");
                }
            }
        }
        if(!venda_encontrada) {
            printf("| Item: --\n");
            printf("| Preço: --\n");
            printf("| Peso: --\n");
            printf("| Quantidade: --\n");
            printf("| Nenhuma venda foi registrada neste mês.\n");
            printf("| Total: --\n");
            printf("*\n");
        }
    }
    system("PAUSE");
    system("CLS");
}



int main(void) {
	
    system("CLS");
    setlocale(LC_ALL, "Portuguese"); // Acentuação Gráfica
    int opcao;

    for(int i = 0; i < 12; i++) {
        meses[i].total_vendas = 0;
        meses[i].mes = i + 1;
    }

    do {
    	
        system("CLS");
        printf("+-----------------------------+\n");
        printf("|           BEM-VINDO         |\n");
        printf("+-----------------------------+\n");
        printf("|  [1]Registrar Venda         |\n");
        printf("|  [2]Gerar Relatório Diário  |\n");
        printf("|  [3]Gerar Relatório Mensal  |\n");
        printf("|  [4]Gerar Relatório Anual   |\n");
        printf("|  [5]Sair                    |\n");
        printf("+-----------------------------+\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            	
                registrar_venda();
                break;
            case 2:
                relatorio_diario();
                break;
            case 3:
                relatorio_mensal();
                break;
            case 4:
            	
                relatorio_anual();
                break;
        }
    } while (opcao != 5);
    system("PAUSE");
    return 0;
}

