#include <stdio.h>

void MenuAlgoritimo(Dadoscidades *cidades){
    int opcao_menu;

    do {
        limparTela();
        printf("\n ========== ALGORITIMOS DE EXECUCAO ==========");
        printf("\n > [1] Floyd Warshall");
        printf("\n > [2] Dijkstra");
        printf("\n =============================================================");
        printf("\n -> Opcao: ");
        scanf("%d", &opcao_menu);

        switch (opcao_menu) {
            case 1:
                floydWarshall(cidades);
                break;
            case 2:
                dijkstra(cidades);
                break;
            
            default:
                break;
        }

    } while(1);
}