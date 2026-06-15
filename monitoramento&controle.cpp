#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void monitorarComodo(int *estadoAparelho, char nomeComodo[20], char nomeAparelho[20], float consumoEnergia) {
    int opcao;
    
    printf("\n--- MENU DE CONTROLE ---\n");
    printf("1- Verificar energia consumida\n");
    printf("2- Desligar o aparelho\n");
    printf("3- Ligar o aparelho\n"); 
    printf("0- Voltar\n");
    
    printf("Escolha: ");
    if (scanf("%d", &opcao) != 1){
        printf("Entrada invalida.\n");
        while (getchar() != '\n');
        return;
    }
    
    if (opcao == 1) {
        if (*estadoAparelho == 0) { 
            printf("O aparelho %s no(a) %s esta desligado e nao consome energia.\n", nomeAparelho, nomeComodo);
        } else {
            printf("\nO(a) %s no(a) %s esta ligado(a)!\n", nomeAparelho, nomeComodo);
            printf("Consumo atual: %.2f kWh\n", consumoEnergia);
        }
    } 
    else if (opcao == 2) {
        if (*estadoAparelho == 1) {
            *estadoAparelho = 0; 
            printf("Sucesso! Aparelho %s no(a) %s foi DESLIGADO.\n", nomeAparelho, nomeComodo);
        } else {
            printf("O aparelho %s ja esta desligado.\n", nomeAparelho);
        }
    }
    else if (opcao == 3) {
        if (*estadoAparelho == 0) {
            *estadoAparelho = 1; 
            printf("Sucesso! Aparelho %s no(a) %s foi LIGADO.\n", nomeAparelho, nomeComodo);
        } else {
            printf("O aparelho %s ja esta ligado.\n", nomeAparelho);
        }
    }
    else if (opcao == 0) {
        printf("Voltando ao menu principal...\n");
    } 
    else {
        printf("Opcao invalida. Tente novamente.\n");
    }
}

int main() {
    int estadosAparelhos[4] = {1, 1, 1, 1}; 
    char nomesComodos[4][20] = {"Sala de Estar", "Cozinha", "Quarto", "Banheiro"};
    char nomeAparelho[4][20] = {"TV", "Forno eletrico", "Climatizador", "luz"};
    float consumosEnergia[4] = {0.5, 1.0, 0.8, 0.3}; 
    int continuar = 1;
    int i; 
    float consumoTotalCasa = 0.0;
    
    while (continuar == 1) {
        int escolhaAparelho;
        char status[10];
        
        printf("\n======= DISPOSITIVOS DISPONIVEIS =======\n");
        for(i = 0; i < 4; i++) {
            strcpy(status, estadosAparelhos[i] == 1 ? "LIGADO" : "DESLIGADO"); 
            printf("%d - %s (%s) [%s]\n", i, nomeAparelho[i], nomesComodos[i], status);
        }
        
        printf("\nEscolha o numero do aparelho para monitorar (ou digite -1 para encerrar e ver o relatorio): ");
        if (scanf("%d", &escolhaAparelho) != 1) {
            printf("Entrada invalida!\n"); 
            while (getchar() != '\n');
            continue;
        }

        if (escolhaAparelho == -1) {
            break; 
        }

        if (escolhaAparelho < 0 || escolhaAparelho > 3) {
            printf("Aparelho invalido!\n");
            continue;
        }

        monitorarComodo(&estadosAparelhos[escolhaAparelho], nomesComodos[escolhaAparelho], nomeAparelho[escolhaAparelho], consumosEnergia[escolhaAparelho]);
    }

    printf("\n\n========================= RELATORIO FINAL DE CONSUMO =========================\n");
    printf("%-15s | %-15s | %-10s | %-15s\n", "COMODO", "APARELHO", "STATUS", "CONSUMO ATUAL");
    printf("------------------------------------------------------------------------------\n");
    
    for (i = 0; i < 4; i++) {
        float consumoAtualComodo;
        char statusFinal[10];
        
        consumoAtualComodo = (estadosAparelhos[i] == 1) ? consumosEnergia[i] : 0.0;
        consumoTotalCasa += consumoAtualComodo;
        
        strcpy(statusFinal, estadosAparelhos[i] == 1 ? "Ligado" : "Desligado");

        printf("%-15s | %-15s | %-10s | %.2f kWh\n", 
               nomesComodos[i], 
               nomeAparelho[i], 
               statusFinal, 
               consumoAtualComodo);
    }
    
    printf("------------------------------------------------------------------------------\n");
    printf("CONSUMO TOTAL DA CASA NESTE MOMENTO: %.2f kWh\n", consumoTotalCasa);
    printf("==============================================================================\n");

    return 0;
}