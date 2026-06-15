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
            printf("sucesso! Aparelho %s no(a) foi desligado\n",nomeAparelho,nomeComodo);
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
    int estadosAparelhos = {1,1,1,1} // 1 para ligado, 0 para desligado //
    char nomesComodos[4][20] = {"Sala de Estar", "Cozinha", "Quarto", "Banheiro"};
    char nomeAparelho [4][20] = {"TV", "forno eletrico", "climatizador","luz"};
    float consumoEnergia[4]={0.5, 1.0, 0.8, 0.3};
    int continuar =1;
    int i;
    float consumoTotalCasa = 0.0;

    while (continuar==1) {
        int escolhaAparelho;
        char status [10];
        
        printf ("\n========DISPOSITIVOS DISPONIVEIS========\n");
        for (i=0; i<4; i++);
            strcpy(status,estadosAparelhos[i]== 1? "LIGADO" : "DESLIGADO");
            printf("%d - %s (%s) [%s]\n",i,nomeAparelho[i], nomeComodos[i],status)
    }
    printf("\n Escolha o numero do aparelho para monitorar (ou digite -1 para encerrar e ver o relatorio): ");
    
    if (scanf("%d",&escolhaAparelho)!= 1){
       printf("Entrada invalida ! \n");
       while(getchar()!='\n');
       continue;
    }
    if (escolhaAparelho ==-1){
        break;
    }
    if (escolhaAparelho < 0 || escolhaAparelho > 3){
        printf("Aparelho invalido\n");
        continue;
    }
    return 0;
}