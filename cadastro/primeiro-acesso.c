#include <stdio.h>
#include "../prototipos.h"

void PrimeiroAcesso(DadosCidades *cidades) {
    int cadastro_ok = 0;

    do {
        cadastro_ok = CadastroCidades(cidades);
        if (cadastro_ok == 0) {
            printf("Cadastro cancelado. Encerrando programa.\n");
            exit(0);
        }
    } while (cadastro_ok != 1);

    limparTela();
    return;
}
