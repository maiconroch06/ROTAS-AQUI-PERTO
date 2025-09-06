#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(void) {
    DadosCidades cidades;

    PrimeiroAcesso(&cidades);

    do {
        int opcao_menu = MenuPrincipal();

        switch (opcao_menu) {
            case 1: CadastroCidades(&cidades); break;
            case 2: ExibirMatrizes(&cidades); break;
            case 3: Salvar(&cidades); break;
            case 4: CalcularRota(&cidades); break;
            case 0: limparTela(); return 0;
            default: break;
        }

    } while (1);
}
