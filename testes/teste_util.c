#include <stdio.h>
#include "../prototipos.h"

void print_matrix_d(DadosCidades *cidades) {
    printf("Matriz de distancias:\n");
    for (int i = 0; i < cidades->num_cidades; i++) {
        for (int j = 0; j < cidades->num_cidades; j++) {
            printf("%f ", cidades->matriz_distancias[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_p(DadosCidades *cidades) {
    printf("Matriz de predecessores:\n");
    for (int i = 0; i < cidades->num_cidades; i++) {
        for (int j = 0; j < cidades->num_cidades; j++) {
            printf("%d ", cidades->matriz_predecessores[i][j]);
        }
        printf("\n");
    }
}
