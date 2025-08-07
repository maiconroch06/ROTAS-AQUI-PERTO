#include <stdio.h>
#include <stdlib.h>
#include "cadastro.c"

int main(void) {
    int escolha;

    do {
        printf("\n ============= ROTAS-AQUI-PERTO =============");
        printf("\n > [1] Adicionar Cidades");
        printf("\n > [2] Exibir Matrizes");
        printf("\n > [3] Calcular Rota");
        printf("\n > [0] Sair do Programa");
        printf("\n ============================================\n");
        scanf(" Opcao: %i",&escolha);

        system("cls");

        switch (escolha){
        case 1:
            // (chamar aquivo cadastro)
            CadastroCidades();
            break;

        /*case 2:
            do {
                printf("\n =========== EXIBIR-MATRIZES ===========");
                printf("\n > [1] Matriz Adjacencias");
                printf("\n > [2] Matriz Distancias Minimas");
                printf("\n > [3] Matriz de Predecessores");
                printf("\n > [0] Voltar");
                printf("\n ================================");
                printf("\n Opcao: ");
                scanf("%d", &escolha);

            } while (escolha != 0 && escolha != 1 && escolha != 2 && escolha != 3);

            break;

        case 3: 
            do {
                printf("\n =========== CALCULAR-ROTA ===========");
                printf("\n > Seu Ponto de Partida: ");
                scanf("%i", &escolha);

                printf("\n > Seu Destino: ");
                scanf("%i", &escolha);

                printf("\n > [0] Cancelar");
                printf("\n ================================");
                printf("\n Opcao: ");
                scanf("%i", &escolha);

            } while (escolha != 0 && escolha != 1 && escolha != 2 && escolha != 3);

            break;*/

        default:
            break;
        }
        
        system("cls");

    } while (1);

    return 0;
}