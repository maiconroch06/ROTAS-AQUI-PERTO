#include <stdio.h>
#include "../prototipos.h"

int ReconstruirCaminho( DadosCidades *cidades, int indice_origem, int indice_destino, int caminho_saida[]) {
    int n_cidades = cidades->num_cidades;
    
    if (indice_origem < 0 || indice_origem >= n_cidades || indice_destino < 0 || indice_destino >= n_cidades) {
        return -1;
    }

    if (indice_origem == indice_destino) {
        caminho_saida[0] = indice_origem;
        return 1;
    }

    int pilha_caminho[n_cidades];
    int topo_pilha = 0;

    int cidade_atual = indice_destino;
    pilha_caminho[topo_pilha++] = indice_destino;

    while (cidade_atual != indice_origem) {
        int pred = cidades->matriz_predecessores[indice_origem][cidade_atual];
        
        if (pred < 0) {
            return -1; // sem caminho
        }

        cidade_atual = pred;

        if (topo_pilha >= n_cidades) {
            return -1; // proteção
        }

        pilha_caminho[topo_pilha++] = cidade_atual;
    }

    int tamanho_caminho = 0;
    for (int indice = topo_pilha - 1; indice >= 0; indice--) {
        caminho_saida[tamanho_caminho++] = pilha_caminho[indice];
    }
    return tamanho_caminho;
}
