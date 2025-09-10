#include "../prototipos.h"

// Function to allocate memory for the matrices and city names
void alocar_memoria(DadosCidades *cidades) {
    int n = cidades->num_cidades;

    cidades->nomes_cidades = malloc(n * sizeof(char *));
    if (cidades->nomes_cidades == NULL) {
        printf("Erro ao alocar memoria para nomes_cidades.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        cidades->nomes_cidades[i] = malloc(255 * sizeof(char));
        if (cidades->nomes_cidades[i] == NULL) {
            printf("Erro ao alocar memoria para nomes_cidades[%d].\n", i);
            exit(1);
        }
    }

    cidades->matriz_adjacentes = malloc(n * sizeof(double *));
    if (cidades->matriz_adjacentes == NULL) {
        printf("Erro ao alocar memoria para matriz_adjacentes.\n");
        exit(1);
    }
    cidades->matriz_distancias = malloc(n * sizeof(double *));
    if (cidades->matriz_distancias == NULL) {
        printf("Erro ao alocar memoria para matriz_distancias.\n");
        exit(1);
    }
    cidades->matriz_predecessores = malloc(n * sizeof(int *));
    if (cidades->matriz_predecessores == NULL) {
        printf("Erro ao alocar memoria para matriz_predecessores.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        cidades->matriz_adjacentes[i] = malloc(n * sizeof(double));
        if (cidades->matriz_adjacentes[i] == NULL) {
            printf("Erro ao alocar memoria para matriz_adjacentes[%d].\n", i);
            exit(1);
        }
        cidades->matriz_distancias[i] = malloc(n * sizeof(double));
        if (cidades->matriz_distancias[i] == NULL) {
            printf("Erro ao alocar memoria para matriz_distancias[%d].\n", i);
            exit(1);
        }
        cidades->matriz_predecessores[i] = malloc(n * sizeof(int));
        if (cidades->matriz_predecessores[i] == NULL) {
            printf("Erro ao alocar memoria para matriz_predecessores[%d].\n", i);
            exit(1);
        }
    }
}

// Function to free the allocated memory
void liberar_memoria(DadosCidades *cidades) {
    if (cidades->num_cidades == 0) {
        return;
    }
    int n = cidades->num_cidades;

    for (int i = 0; i < n; i++) {
        free(cidades->nomes_cidades[i]);
    }
    free(cidades->nomes_cidades);

    for (int i = 0; i < n; i++) {
        free(cidades->matriz_adjacentes[i]);
        free(cidades->matriz_distancias[i]);
        free(cidades->matriz_predecessores[i]);
    }
    free(cidades->matriz_adjacentes);
    free(cidades->matriz_distancias);
    free(cidades->matriz_predecessores);
}
