#include <stdio.h>
#include "../prototipos.h"

int MenuPrincipal() {
    int opcao_menu;
    limparTela();
    printf("\n ============= ROTAS-AQUI-PERTO =============");
    printf("\n > [1] Alterar Cadastro de Cidades");
    printf("\n > [2] Exibir Matrizes");
    printf("\n > [3] Salvar Dados");
    printf("\n > [4] Calcular Rota");
    printf("\n > [0] Sair do Programa");
    printf("\n ============================================");
    printf("\n -> Opcao: ");

    scanf("%d", &opcao_menu);
    return opcao_menu;
}
