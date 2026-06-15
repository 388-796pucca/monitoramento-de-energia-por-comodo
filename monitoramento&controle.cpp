#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void monitorarComodo(int *estadoComodo, char nomeComodo[20], char nomeAparelho[20], float consumoEnergiaTv, float consumoEnergiaLuz, float consumoEnergiaForno, float consumoEnergiaClimatizador) {
    printf("\n--- ALERTA DE ENERGIA ---\n");
    printf("\n--- menu ---\n");
    printf("1- verificar energia consumida\n");
    printf("2- desligar o aparelho\n");
    printf("0- sair\n");
    int opcao;
    printf("escolha: ");
    if (scanf("%d", &opcao) != 1){
        printf("Entrada invalida. Encerrando o monitoramento.\n");
        return;
    }
    if (opcao==1){
        if (*estadoComodo == 0){
            printf("o comodo não esta consumindo energia\n");
        } else {
            printf("\n A TV na sala esta ligado\n");
            printf("O aparelho esta consumindo %.2f kWh\n", consumoEnergiaTv);
            printf("\n a luz do comodo quarto esta acesa\n");
            printf("o objeto está está consumindo %.2f kWh\n", consumoEnergiaLuz);
            printf("\n o forno eletrico da cozinha esta ligado\n");
            printf(" o forno eletrico esta consumindo %.2f kWh\n", consumoEnergiaForno);
            printf("\n o climatizador da sala esta ligado\n");
            printf("o climatizador esta consumindo %.2f kWh\n", consumoEnergiaClimatizador);
        }
    } else if (opcao==2){
        if (*estadoComodo == 1){
            *estadoComodo = 0;
            printf("sucesso ao desligar o aparelho\n");
        } else {
            printf("O aparelho já está desligado\n");
        }
    } else if (opcao==0){
        printf("Encerrando o monitoramento...\n");
    } else {
        printf("Opcao invalida. Tente novamente.\n");
    }
}
int main() {
    int estadoComodo = 1; // 1 para ligado, 0 para desligado
    char nomesComodos[4][20] = {"Sala de Estar", "Cozinha", "Quarto", "Banheiro"};
    char nomeAparelho [4][20] = {"TV", "forno eletrico", "luz","climatizador"};
    float consumoEnergiaTv = 0.5; // consumo em kWh
    float consumoEnergiaLuz = 0.3; // consumo em kWh
    float consumoEnergiaForno = 1.0; // consumo em kWh
    float consumoEnergiaClimatizador = 0.8; // consumo em kWh
    int continuar =1;
    while (continuar==1) {
        monitorarComodo(&estadoComodo, nomesComodos[0], nomeAparelho[0], consumoEnergiaTv, consumoEnergiaLuz, consumoEnergiaForno, consumoEnergiaClimatizador);
        printf("deseja voltar ao menu de monitoramento? (1 - sim, 0 - nao): ");
        if (scanf("%d", &continuar) != 1){
            printf("Entrada invalida. Encerrando o programa.\n");
            break;
        }
    }
    return 0;
}