#include <stdio.h>
#include "../prototipos.h"

void ExibirMatrizes(DadosCidades *cidades) {
    int opcao_menu;
    do {
        limparTela();
        printf("\n =========== EXIBIR-MATRIZES ===========");
        printf("\n > [1] Matriz Adjacencias");
        printf("\n > [2] Matriz Distancias Minimas");
        printf("\n > [3] Matriz de Predecessores");
        printf("\n > [0] Voltar");
        printf("\n =======================================");
        printf("\n -> Opcao: ");
        scanf("%d", &opcao_menu);

        switch (opcao_menu){
            case 1: ExibirMatrizA(cidades); break;
            case 2: ExibirMatrizD(cidades); break;
            case 3: ExibirMatrizP(cidades); break;
            case 0: return;
            default: break;
        }

    } while (1);
}