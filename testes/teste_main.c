#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../prototipos.h"

void carregar_dados_teste(DadosCidades *cidades, const char *caminho_arquivo) {
    FILE *arquivo_entrada = fopen(caminho_arquivo, "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de teste: %s\n", caminho_arquivo);
        exit(1);
    }

    char linha_arquivo[250];
    if (fgets(linha_arquivo, 250, arquivo_entrada) != NULL) {
        cidades->num_cidades = atoi(linha_arquivo);
        alocar_memoria(cidades);
    } else {
        printf("Erro ao ler o número de cidades do arquivo de teste.\n");
        exit(1);
    }

    for (int i = 0; i < cidades->num_cidades; i++) {
        if (fgets(linha_arquivo, 250, arquivo_entrada) != NULL) {
            linha_arquivo[strcspn(linha_arquivo, "\r\n")] = 0;
            strcpy(cidades->nomes_cidades[i], linha_arquivo);
        }
    }

    for (int i = 0; i < cidades->num_cidades; i++) {
        fgets(linha_arquivo, 250, arquivo_entrada);
        char *token = strtok(linha_arquivo, ";");
        for (int j = 0; j < cidades->num_cidades; j++) {
            cidades->matriz_adjacentes[i][j] = atof(token);
            token = strtok(NULL, ";");
        }
    }

    fclose(arquivo_entrada);
}

void teste_floyd_warshall() {
    DadosCidades cidades;
    carregar_dados_teste(&cidades, "testes/cidades_teste.txt");
    floydWarshall(&cidades);

    // Matriz de distâncias esperada
    double distancias_esperadas[4][4] = {
        {0, 5, 8, 9},
        {5, 0, 3, 4},
        {8, 3, 0, 1},
        {9, 4, 1, 0}
    };

    // Matriz de predecessores esperada
    int predecessores_esperados[4][4] = {
        {-1, 0, 1, 2},
        {0, -1, 1, 2},
        {1, 2, -1, 2},
        {1, 2, 3, -1}
    };

    int erros = 0;
    for (int i = 0; i < cidades.num_cidades; i++) {
        for (int j = 0; j < cidades.num_cidades; j++) {
            if (cidades.matriz_distancias[i][j] != distancias_esperadas[i][j]) {
                printf("Erro na matriz de distancias na posicao [%d][%d]: esperado %f, obtido %f\n",
                       i, j, distancias_esperadas[i][j], cidades.matriz_distancias[i][j]);
                erros++;
            }
            if (cidades.matriz_predecessores[i][j] != predecessores_esperados[i][j]) {
                printf("Erro na matriz de predecessores na posicao [%d][%d]: esperado %d, obtido %d\n",
                       i, j, predecessores_esperados[i][j], cidades.matriz_predecessores[i][j]);
                erros++;
            }
        }
    }

    if (erros == 0) {
        printf("Teste Floyd-Warshall: OK\n");
    } else {
        printf("Teste Floyd-Warshall: FALHOU (%d erros)\n", erros);
    }

    liberar_memoria(&cidades);
}

int main() {
    teste_floyd_warshall();
    return 0;
}
