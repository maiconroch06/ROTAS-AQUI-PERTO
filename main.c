#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

matrizAdj matrizADJ;

int main(void) {
    int escolha;

    do{
        escolha = CadastroCidades(&matrizADJ);
    } while (escolha != 1);

    int N = matrizADJ.n;
    double d[N][N];
    int p[N][N];

    floydWarshall(&matrizADJ, N, d, p);

    do {
        system("cls");
        printf("\n ============= ROTAS-AQUI-PERTO =============");
        printf("\n > [1] Alterar Cadastro de Cidades");
        printf("\n > [2] Exibir Matrizes");
        printf("\n > [3] Salvar Dados");
        printf("\n > [4] Calcular Rota");
        printf("\n > [0] Sair do Programa");
        printf("\n ============================================\n");
        printf(" Opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                CadastroCidades(&matrizADJ);
                N = matrizADJ.n;
                floydWarshall(&matrizADJ, N, d, p);
                break;

            case 2:
                ExibirMatrizes(&matrizADJ, N, d, p);
                break;

            case 3:
                Salvar(&matrizADJ, N, d, p);
                break;

            case 4:
                CalcularRota(&matrizADJ, N, d, p);
                break;

            case 0:
                return 0;

            default:
                break;
        }
    } while (1);
}