# Sistema de Monitoramento Residencial em C

Este projeto consiste em um sistema de gerenciamento e monitoramento de consumo de energia residencial desenvolvido em linguagem C. O software permite controlar o estado (ligado/desligado) de diferentes aparelhos eletrônicos em seus respectivos cômodos e, ao final, gera um relatório consolidado com o consumo total da residência com base nos aparelhos que permaneceram ativos.

 **Link do Repositório:** :https://github.com/388-796pucca/monitoramento-de-energia-por-comodo.git

---

##  Estrutura e Arquitetura do Código

O programa foi desenhado com foco em modularização, boas práticas de tratamento de dados e controle de fluxo, dividindo-se em dois pilares principais:

### 1. Função `monitorarComodo`
Funciona como um sub-menu dedicado para gerenciar um único aparelho por vez. 

* **Passagem por Referência (`int *estadoAparelho`):** Utiliza ponteiros (`*`) para receber o endereço de memória do estado do aparelho. Isso garante que qualquer alteração (ligar/desligar) feita dentro do sub-menu modifique diretamente a array original presente na função `main`.
* **Passagem por Valor (`nomeComodo`, `nomeAparelho`, `consumoEnergia`):** Dados utilizados apenas para exibição. São passados por valor (ou como arrays de caracteres, que se comportam como ponteiros nativos em C), protegendo a integridade das variáveis originais.
* **Tratamento de Entrada de Dados:** Implementação da validação `if (scanf("%d", &opcao) != 1)`. Essa abordagem evita loops infinitos caso o usuário digite um caractere inválido (letras/símbolos), limpando o buffer de entrada logo em seguida com o comando `while (getchar() != '\n');`.
* **Lógica de Estados:** Avalia o valor contido no ponteiro (0 para desligado, 1 para ligado) para alternar o status do aparelho e exibir feedbacks em tempo real para o usuário.

### 2. Função `main`

* **Paralelismo de Arrays (Estrutura de Dados):** O sistema utiliza 4 arrays distintas (`estadosAparelhos`, `nomesComodos`, `nomeAparelho`, `consumosEnergia`), onde o índice `i` correlaciona todas as informações de um mesmo cômodo/aparelho. *(Nota de arquitetura: Uma abordagem funcional para C básico que simula o comportamento de um banco de dados relacional simples).*
* **Loop Principal (`while (continuar == 1)`):** Mantém a interface de linha de comando  rodando continuamente, permitindo ao usuário alternar entre os cômodos livremente até decidir encerrar.
* **Validação de Limites de Memória:** Garante a segurança da aplicação validando se a escolha do usuário está estritamente entre os índices válidos (0 a 3). Isso previne erros graves e comportamentos indefinidos.
* **Relatório Final Dinâmico:** Ao encerrar o programa (digitando `-1`), o loop é interrompido. O sistema limpa a tela e renderiza uma tabela formatada utilizando alinhamentos precisos (`%-15s`). Durante essa varredura, o consumo acumulado (`consumoTotalCasa`) é calculado dinamicamente, somando apenas o gasto dos aparelhos que terminaram com o status **1 (Ligado)**.

---
Funcionalidades do Sistema

A aplicação foi projetada para ser intuitiva, segura e resiliente a falhas de operação. Suas principais funcionalidades são:

* **Painel de Navegação:** Um menu interativo que centraliza o acesso aos cômodos da residência.
* **Gerenciamento de Estado Individual (Sub-menus):** Interface isolada para cada aparelho, permitindo ligar ou desligar o dispositivo e visualizar seu status atual em tempo real.
* **Tratamento de Entradas Inválidas :** O sistema possui um mecanismo de defesa contra entradas incorretas. Se o usuário digitar letras ou símbolos onde um número é esperado, o programa não entra em loop e não quebra; ele limpa o canal de entrada e solicita o dado novamente.
* **Filtro Condicional de Consumo:** O cálculo da energia consumida ignora aparelhos desligados, computando estritamente a carga daqueles que terminaram o ciclo de execução como "Ligados".
* **Relatório Tabular Consolidado:** Ao encerrar o programa, a tela é limpa e uma tabela formatada é gerada, exibindo o status final de cada cômodo, o aparelho correspondente, o consumo individual e o consumo total acumulado da casa.

---

## PROJETO DESENVOLVIDO POR:
Queren Hapuque S.R.M dos Reis e Amanda Quezya Viera Farias.
