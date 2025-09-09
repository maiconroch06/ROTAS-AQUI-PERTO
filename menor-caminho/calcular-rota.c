#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../prototipos.h"

void CalcularRota(DadosCidades *cidades) {
    int n_cidades = cidades->num_cidades;

    do { // laço principal
        limparTela();
        printf("\n =========== CALCULAR-ROTA ===========\n");
        printf(" ** Escolha pelo numero da cidade:\n\n");
        
        for (int i = 0; i < n_cidades; i++) {
            printf(" %2d) %s\n", i + 1, cidades->nomes_cidades[i]);
        }

        int opcao_origem, opcao_destino;

        printf("\n > Origem (0 para sair, 1..%d): ", n_cidades);
        if (scanf("%d", &opcao_origem) != 1) {
            puts("Entrada invalida.");
            pausar();
            while (getchar() != '\n'); // limpa buffer
            continue; // volta ao início
        }

        if (opcao_origem == 0) break; // saída do loop

        printf(" > Destino (1..%d): ", n_cidades);
        if (scanf("%d", &opcao_destino) != 1) {
            puts("Entrada invalida.");
            pausar();
            while (getchar() != '\n');
            continue;
        }

        if (opcao_origem < 1 || opcao_origem > n_cidades || 
            opcao_destino < 1 || opcao_destino > n_cidades) {
            puts("\n !! Numero de cidade invalido !!");
            pausar();
            continue;
        }

        int indice_origem  = opcao_origem  - 1;
        int indice_destino = opcao_destino - 1;

        if (indice_origem != indice_destino && 
            cidades->matriz_predecessores[indice_origem][indice_destino] < 0) {
            printf("\n Nao existe caminho de '%s' para '%s'.\n",
                   cidades->nomes_cidades[indice_origem],
                   cidades->nomes_cidades[indice_destino]);
            pausar();
            continue;
        }

        int caminho[n_cidades];
        int tamanho_caminho = ReconstruirCaminho(cidades, indice_origem, indice_destino, caminho);

        if (tamanho_caminho < 0) {
            printf("\n Nao existe caminho de '%s' para '%s'.\n",
                   cidades->nomes_cidades[indice_origem],
                   cidades->nomes_cidades[indice_destino]);
            pausar();
            continue;
        }

        printf("\n > Rota: ");
        for (int indice = 0; indice < tamanho_caminho; indice++) {
            printf("%s", cidades->nomes_cidades[caminho[indice]]);
            if (indice < tamanho_caminho - 1){
                printf(" -> ");
            }
        }
        printf("\n\n > Distancia total: %.2f\n\n",
               cidades->matriz_distancias[indice_origem][indice_destino]);

        pausar();

    } while (1);
}
