#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../prototipos.h"

void SalvarResultados(DadosCidades *cidades) {
    int opcao_menu;

    limparTela();
    printf("\n ====== SALVAR RESULTADOS EM ARQUIVO? =======");
    printf("\n > [1] Sim > [0] Nao");
    printf("\n ============================================");
    printf("\n -> Opcao: ");
    scanf("%i", &opcao_menu);

    if (opcao_menu == 1) {
        char nome_arq_resultado[500];
        printf("\n > Nomeie arquivo resultado (ex: resultado.txt): ");
        scanf(" %499[^\n]", nome_arq_resultado);

        // Define o caminho da pasta onde o arquivo será salvo
        char caminho_pasta[] = "./banco-de-dados/";

        // Cria o caminho completo do arquivo
        char caminho_completo[600];
        snprintf(caminho_completo, sizeof(caminho_completo), "%s%s", caminho_pasta, nome_arq_resultado);

        // Abre o arquivo para escrita
        FILE *arquivo_saida = fopen(caminho_completo, "w");

        if (arquivo_saida != NULL) {
            int n_cidades = cidades->num_cidades;

            printf("\n ** Arquivo '%s' aberto com sucesso **\n", nome_arq_resultado);
            fprintf(arquivo_saida, "%i\n", n_cidades);

            // distâncias (double)
            for (int i = 0; i < n_cidades; i++) {
                for (int j = 0; j < n_cidades; j++) {
                    fprintf(arquivo_saida, "%.2f", cidades->matriz_distancias[i][j]);

                    if (j < n_cidades - 1) {
                        fprintf(arquivo_saida, ";");
                    }
                }
                fprintf(arquivo_saida, "\n");
            }

            // predecessores (int)
            for (int i = 0; i < n_cidades; i++) {
                for (int j = 0; j < n_cidades; j++) {
                    fprintf(arquivo_saida, "%d", cidades->matriz_predecessores[i][j]);

                    if (j < n_cidades - 1) {
                        fprintf(arquivo_saida, ";");
                    }
                }
                fprintf(arquivo_saida, "\n");
            }

            fclose(arquivo_saida);
            printf(" ** Dados salvos com sucesso **\n");
            pausar();
            return;

        } else {
            printf(" #ERRO: ao abrir o arquivo '%s'.\n", nome_arq_resultado);
            pausar();
            return;
        }

    } else {
        return;
    }
}
