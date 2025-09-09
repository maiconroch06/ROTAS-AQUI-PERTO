#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../prototipos.h"

int CarregarArquivo(DadosCidades *cidades) {
    FILE *arquivo_entrada = NULL;

    do {
        limparTela();
        
        char origem[400]; //nome do arquivo_entrada de origem
        printf("\n ============ CARREGAR-ARQUIVO ============");
        printf("\n > Origem do arquivo: ");
        scanf(" %399[^\n]", origem);

        arquivo_entrada = fopen(origem, "r");
        
        if (arquivo_entrada != NULL) {
            // Ler o número de cidades
            char linha_arquivo[250];
            int n_cidades = cidades->num_cidades;

            if (fgets(linha_arquivo, 250, arquivo_entrada) != NULL) {
                n_cidades = atoi(linha_arquivo);
                cidades->num_cidades = n_cidades;
            }

            // Ler os nomes das cidades
            for (int i = 0; i < n_cidades; i++) {

                if (fgets(linha_arquivo, 250, arquivo_entrada) != NULL) {
                    size_t L = strlen(linha_arquivo);
                    
                    if (L && (linha_arquivo[L-1] == '\n' || linha_arquivo[L-1] == '\r'))
                        linha_arquivo[--L] = '\0';
                        strcpy(cidades->nomes_cidades[i], linha_arquivo);
                }
            }

            // Ler a matriz de adjacencias
            for (int i = 0; i < n_cidades; i++) {
                if (!fgets(linha_arquivo, sizeof(linha_arquivo), arquivo_entrada)) {
                    printf("\n ** ERRO: matriz incompleta no arquivo.\n");
                    fclose(arquivo_entrada);
                    return 0;
                }

                char *token = strtok(linha_arquivo, ";");
                for (int j = 0; j < n_cidades; j++) {
                    if (token) {
                        cidades->matriz_adjacentes[i][j] = atof(token);
                        token = strtok(NULL, ";");
                    } else {
                        cidades->matriz_adjacentes[i][j] = 1000.0; // sem conexão
                    }
                }
            }

            fclose(arquivo_entrada);
            ExibirMatrizA(cidades);
            floydWarshall(cidades);

            return 1;

        } else {
            int opcao_menu;
            int sair_menu = 0;
            while (!sair_menu) {
                limparTela();
                printf("\n ========== ARQUIVO-INDISPONIVEL ==========");
                printf("\n > [1] Tentar novamente");
                printf("\n > [0] Cancelar");
                printf("\n ==========================================");
                printf("\n > Escolha: ");
                scanf("%i", &opcao_menu);

                switch (opcao_menu) {
                    case 1: 
                        sair_menu = 1; // volta para tentar carregar outro arquivo
                        break;
                    case 0: 
                        printf("\n * Saindo...\n"); 
                        return 0;
                    default: 
                        break;
                }
            }
        }


    } while (1);
}
