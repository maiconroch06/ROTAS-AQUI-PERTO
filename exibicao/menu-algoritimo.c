#include <stdio.h>
#include "../prototipos.h"

void MenuAlgoritimo(DadosCidades *cidades){
    int opcao_menu;

    do {
        limparTela();
        printf("\n ========== ALGORITIMOS DE EXECUCAO ==========");
        printf("\n > [1] Floyd Warshall");
        printf("\n > [0] Voltar");
        printf("\n =============================================================");
        printf("\n -> Opcao: ");
        scanf("%d", &opcao_menu);

        switch (opcao_menu) {
            case 1:
                floydWarshall(cidades);
                printf("\n * Algoritmo de Floyd-Warshall executado com sucesso!\n");
                pausar();
                break;
            case 0:
                return;
            default:
                printf("\n * Opcao invalida. Tente novamente.\n");
                pausar();
                break;
        }

    } while(1);
}