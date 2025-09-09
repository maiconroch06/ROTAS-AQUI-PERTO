#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../prototipos.h"

void SalvarDadosIniciais(DadosCidades *cidades) {
    int opcao_menu;

    limparTela();
    printf("\n ==== SALVAR DADOS INICIAIS EM ARQUIVO? ====");
    printf("\n > [1] Sim > [0] Nao");
    printf("\n ===========================================");
    printf("\n -> Opcao: ");

    if (scanf("%d", &opcao_menu) != 1) {
        puts(" Entrada invalida.");
        pausar();
        return;
    }

    if (opcao_menu != 1) {
        return; // usuário escolheu não salvar
    }

    char nome_arq_inicial[500];
    printf("\n > Nomeie arquivo dados iniciais (ex: dados.txt): ");
    scanf(" %499[^\n]", nome_arq_inicial); // previne buffer overflow

    // Define o caminho da pasta onde o arquivo será salvo
    char caminho_pasta[] = "./banco-de-dados/";

    // Cria o caminho completo do arquivo
    char caminho_completo[600];
    snprintf(caminho_completo, sizeof(caminho_completo), "%s%s", caminho_pasta, nome_arq_inicial);

    // Abre o arquivo para escrita
    FILE *arquivo_entrada = fopen(caminho_completo, "w");
    if (arquivo_entrada == NULL) {
        perror(" Erro ao abrir arquivo");
        pausar();
        return;
    }

    int n_cidades = cidades->num_cidades;

    printf("\n ** Arquivo '%s' aberto com sucesso **\n", nome_arq_inicial);

    // Escreve o número de cidades no arquivo
    fprintf(arquivo_entrada, "%d\n", n_cidades);

    // Escreve os nomes das cidades
    for (int i = 0; i < n_cidades; i++) {
        fprintf(arquivo_entrada, "%s\n", cidades->nomes_cidades[i]);
    }

    // Escreve a matriz de adjacentes
    for (int i = 0; i < n_cidades; i++) {
        for (int j = 0; j < n_cidades; j++) {
            fprintf(arquivo_entrada, "%.2f", cidades->matriz_adjacentes[i][j]);
            if (j < n_cidades - 1) {
                fprintf(arquivo_entrada, ";");
            }
        }
        fprintf(arquivo_entrada, "\n");
    }

    fclose(arquivo_entrada);

    printf(" ** Dados salvos com sucesso **\n");
    pausar();
}
