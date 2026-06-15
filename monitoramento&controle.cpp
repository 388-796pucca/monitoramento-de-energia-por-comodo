#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void monitorarComodo(int *estadoComodo, char nomeComodo[20], char nomeAparelho[20], float consumoEnergia) {
   int opcao;  
    printf("\n--- ALERTA DE ENERGIA ---\n");
    printf("\n--- menu ---\n");
    printf("1- verificar energia consumida\n");
    printf("2- desligar o aparelho\n");
    printf("3- ligar o aparelho\n")
    printf("0- sair\n");
    printf("escolha: ");

    if (scanf("%d", &opcao) != 1){
        printf("Entrada invalida. Encerrando o monitoramento.\n");
        while (getchar()!='\n');
        return;
    }
    if (opcao==1){
        if (*estadoComodo == 0){
            printf("O aparelho %s no(a) %s esta desligado e nao esta consumindo energia\n" , nomeAparelho, nomeComodo);
        }
        else {
            printf("\n O(a) %s no(a) %s esta ligado(a)!\n",nomeAparelho,nomeComodo);
            printf("Consumo atual: %2f kWh\n",consumoEnergia);
        }
    }
    else if (opcao==2){
        if (*estadoComodo == 1){
            *estadoComodo = 0;
            printf("sucesso !Aparelho %s no(a) foi desligado\n",nomeAparelho,nomeComodo);
        } 
        else {
            printf("O aparelho %s já está desligado\n", nomeAparelho);
        }
    } 
    else if (opcao==3){
        if (*estadoComodo == 0){
            *estadoComodo = 1;
            printf("sucesso !Aparelho %s no(a) foi ligado\n",nomeAparelho,nomeComodo);
        } 
        else {
            printf("O aparelho %s já está ligado\n", nomeAparelho);
        }
    } 
    else if (opcao==0){
        printf("Voltando ao menu principal...\n");
    } 
        else {
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