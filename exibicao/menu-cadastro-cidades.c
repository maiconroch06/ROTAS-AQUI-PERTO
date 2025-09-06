#include <stdio.h>
#include "../prototipos.h"

int CadastroCidades(DadosCidades *cidades) {
    int opcao_menu;

    do {
        limparTela();
        printf("\n ========== CADASTRO-DE-CIDADES ==========");
        printf("\n > [1] Adicionar Manualmente");
        printf("\n > [2] Carregar Arquivo");
        printf("\n > [0] Voltar");
        printf("\n =========================================");
        
        printf("\n -> Opcao: ");
        scanf("%i", &opcao_menu);

        switch (opcao_menu) {
            case 1: CadastroManual(cidades); return 1;
            case 2: CarregarArquivo(cidades); return 1;
            case 0: return 0;
            default:
                break;
        }

    } while(1);
}
