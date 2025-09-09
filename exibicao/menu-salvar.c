#include <stdio.h>
#include "../prototipos.h"

void Salvar(DadosCidades *cidades) {
    int opcao_menu;
    do {
        limparTela();
        printf("\n ========= O QUE SALVAR? =========");
        printf("\n > [1] Dados Iniciais");
        printf("\n > [2] Dados Resultantes");
        printf("\n > [0] Voltar");
        printf("\n =================================");
        printf("\n -> Opcao: ");
        scanf("%i", &opcao_menu);

        switch (opcao_menu) {
            case 1: SalvarDadosIniciais(cidades); break;
            case 2: SalvarResultados(cidades); break;
            case 0:
                return;
            default:
                break;
        }

    } while (1);
}
