# Sistema de Monitoramento Residencial em C

Este projeto consiste em um sistema de gerenciamento e monitoramento de consumo de energia residencial desenvolvido em linguagem C. O software permite controlar o estado (ligado/desligado) de diferentes aparelhos eletrônicos em seus respectivos cômodos e, ao final, gera um relatório consolidado com o consumo total da residência com base nos aparelhos que permaneceram ativos.

 **Link do Repositório:** [Acesse os commits e histórico do projeto aqui]()

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
A espinha dorsal do programa. Responsável por inicializar os dados, gerenciar o loop principal de navegação e consolidar os resultados.

* **Paralelismo de Arrays (Estrutura de Dados):** O sistema utiliza 4 arrays distintas (`estadosAparelhos`, `nomesComodos`, `nomeAparelho`, `consumosEnergia`), onde o índice `i` correlaciona todas as informações de um mesmo cômodo/aparelho. *(Nota de arquitetura: Uma abordagem funcional para C básico que simula o comportamento de um banco de dados relacional simples).*
* **Loop Principal (`while (continuar == 1)`):** Mantém a interface de linha de comando (CLI) rodando continuamente, permitindo ao usuário alternar entre os cômodos livremente até decidir encerrar.
* **Validação de Limites de Memória:** Garante a segurança da aplicação validando se a escolha do usuário está estritamente entre os índices válidos (0 a 3). Isso previne erros graves de *segmentation fault* ou comportamentos indefinidos.
* **Relatório Final Dinâmico:** Ao encerrar o programa (digitando `-1`), o loop é interrompido. O sistema limpa a tela e renderiza uma tabela formatada utilizando alinhamentos precisos (`%-15s`). Durante essa varredura, o consumo acumulado (`consumoTotalCasa`) é calculado dinamicamente, somando apenas o gasto dos aparelhos que terminaram com o status **1 (Ligado)**.

---
