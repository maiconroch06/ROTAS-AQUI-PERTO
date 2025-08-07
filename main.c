#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "matriz.h"

int main(void) {
    int escolha;
    matrizAdj matrizADJ;

    do {
        system("cls");
        printf("\n ============= ROTAS-AQUI-PERTO =============");
        printf("\n > [1] Adicionar Cidades");
        printf("\n > [2] Exibir Matrizes");
        printf("\n > [3] Calcular Rota");
        printf("\n > [0] Sair do Programa");
        printf("\n ============================================\n");
        printf(" Opcao: ");
        scanf("%i",&escolha);
        switch (escolha){
        
        case 1:
            // (chamar aquivo cadastro)
            CadastroCidades(&matrizADJ);

            for(int i = 0; i < matrizADJ.n; i++){
                for (int j = 0; j < matrizADJ.n; j++) {
                    printf("|%.2lf|", matrizADJ.matriz[i][j]);
                }
                printf("\n");
            }
            break;
            
        //*/
        case 2:
            do {
                printf("\n =========== EXIBIR-MATRIZES ===========");
                printf("\n > [1] Matriz Adjacencias");
                printf("\n > [2] Matriz Distancias Minimas");
                printf("\n > [3] Matriz de Predecessores");
                printf("\n > [0] Voltar");
                printf("\n ================================");
                printf("\n Opcao: ");
                scanf("%d", &escolha);

            } while (1);

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
                
                } while (1);
                
                break;//*/
                
        case 0:
            // saindo
            return 0;
            
        default:
            printf(" ERRO: escolha fora do escopo");
            break;
        }
        
        system("cls");

    } while (1);

}