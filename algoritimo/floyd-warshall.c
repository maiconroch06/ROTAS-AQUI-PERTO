#include <stdio.h>
#include "../prototipos.h"

void floydWarshall(DadosCidades *cidades) {
    int n_cidades = cidades->num_cidades;

    for (int i = 0; i < n_cidades; i++) {
        for (int j = 0; j < n_cidades; j++) {
            cidades->matriz_distancias[i][j] = cidades->matriz_adjacentes[i][j];

            if (i == j){
                cidades->matriz_predecessores[i][j] = -1;

            } else if (cidades->matriz_adjacentes[i][j] < 1000.0) {
                cidades->matriz_predecessores[i][j] = i;

            } else {
                cidades->matriz_predecessores[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < n_cidades; k++) {
        for (int i = 0; i < n_cidades; i++) {
            for (int j = 0; j < n_cidades; j++) {
                if ((cidades->matriz_distancias[i][k] + cidades->matriz_distancias[k][j]) < cidades->matriz_distancias[i][j]) {
                    cidades->matriz_distancias[i][j] = cidades->matriz_distancias[i][k] + cidades->matriz_distancias[k][j];
                    cidades->matriz_predecessores[i][j] = cidades->matriz_predecessores[k][j];
                }
            }
        }
    }
}
