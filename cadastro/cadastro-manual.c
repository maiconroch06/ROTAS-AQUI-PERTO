#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../prototipos.h"

// =================== cadastro.c ===================
int CadastroManual(DadosCidades *cidades){
    do {
        limparTela();

        int n_cidades;
        printf("\n ============ CADASTRO-MANUAL ============\n");
        printf(" > Informe o Numero dos Municipios: ");
        scanf("%i", &n_cidades);
        cidades->num_cidades = n_cidades;

        printf(" > Nomes dos Municipios:\n");
        for (int i = 0; i < n_cidades; i++){
            printf("   %02d. ", i + 1);
            scanf(" %[^\n]", cidades->nomes_cidades[i]);
        }

        printf(" > Distancia Entre os Municipios:\n");
        for (int i = 0; i < n_cidades; i++) {
            for (int j = i; j < n_cidades; j++) {
                if (i == j) {
                    cidades->matriz_adjacentes[i][j] = 0.0;

                } else {
                    printf("\n > De %s para %s: ", cidades->nomes_cidades[i], cidades->nomes_cidades[j]);
                    scanf("%lf", &cidades->matriz_adjacentes[i][j]);
                    cidades->matriz_adjacentes[j][i] = cidades->matriz_adjacentes[i][j];
                }
            }
        }

        limparTela();
        printf("\n ==== MATRIZ CADASTRADA COM SUCESSO !! ====\n");

        ExibirMatrizA(cidades);

        printf("\n ======= CONFIRMAR VALORES? ========");
        printf("\n > [1] Confirmar");
        printf("\n > [2] Alterar");
        printf("\n > [0] Cancelar ");
        printf("\n ===================================");
        
        int opcao_confirmacao;
        printf("\n -> Opcao: ");
        scanf("%i", &opcao_confirmacao);

        limparTela();
        switch (opcao_confirmacao) {
            case 1:
                printf("\n * Valores Confirmados!\n");
                floydWarshall(cidades);
                SalvarDadosIniciais(cidades);
                SalvarResultados(cidades);
                return 1;
            case 2:
                printf("\n * Alterar Valores!\n");
                break; // volta ao loop e recadastra
            case 0:
                printf("\n * Valores Cancelados!\n");
                return 0;
            default:
                printf("\n * Opcao invalida. Tente novamente.\n");
                pausar();
                break;
        }

    } while (1);
}
