#include <stdio.h>
#include <stdlib.h>
#include "../prototipos.h"

void ExibirMatrizA(DadosCidades *cidades) {
    int n_cidades = cidades->num_cidades;

    limparTela();
    printf("\n > LISTA-DE-CIDADES:\n");
    for (int i = 0; i < n_cidades; i++) {
        printf(" %02d. %s\n", i + 1, cidades->nomes_cidades[i]);
    }

    printf("\n > MATRIZ-DE-ADJACENTES:\n\n");

    // Cabeçalho (colunas)
    printf("      "); // espaço inicial para alinhar
    for (int j = 0; j < n_cidades; j++) {
        printf("%8.02d ", j + 1);
    }
    printf("\n");

    // Linha separadora
    printf("     ");
    for (int j = 0; j < n_cidades; j++) {
        printf("---------");
    }
    printf("\n");

    // Linhas da matriz
    for (int i = 0; i < n_cidades; i++) {
        printf("%02d  | ", i + 1); // índice da linha
        for (int j = 0; j < n_cidades; j++) {
            printf("%8.2f ", cidades->matriz_adjacentes[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    pausar();
}

void ExibirMatrizD(DadosCidades *cidades) {
    int n_cidades = cidades->num_cidades;

    limparTela();
    printf("\n > LISTA-DE-CIDADES:\n");
    for (int i = 0; i < n_cidades; i++) {
        printf(" %02d. %s\n", i + 1, cidades->nomes_cidades[i]);
    }

    printf("\n > MATRIZ-DE-DISTANCIAS-MINIMAS:\n\n");

    // Cabeçalho
    printf("      ");
    for (int j = 0; j < n_cidades; j++) {
        printf("%8.02d ", j + 1);
    }
    printf("\n");

    printf("     ");
    for (int j = 0; j < n_cidades; j++) {
        printf("---------");
    }
    printf("\n");

    // Linhas
    for (int i = 0; i < n_cidades; i++) {
        printf("%02d  | ", i + 1);
        for (int j = 0; j < n_cidades; j++) {
            printf("%8.2f ", cidades->matriz_distancias[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    pausar();
}

void ExibirMatrizP(DadosCidades *cidades) {
    int n_cidades = cidades->num_cidades;

    limparTela();
    printf("\n > MATRIZ-DE-PREDECESSORES:\n\n");

    // Cabeçalho
    printf("       ");
    for (int j = 0; j < n_cidades; j++) {
        printf("%8.02d ", j + 1);
    }
    printf("\n");

    printf("      ");
    for (int j = 0; j < n_cidades; j++) {
        printf("---------");
    }
    printf("\n");

    // Linhas
    for (int i = 0; i < n_cidades; i++) {
        printf("%3.02d  | ", i + 1);
        for (int j = 0; j < n_cidades; j++) {
            printf("%8d ", cidades->matriz_predecessores[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    pausar();
}
