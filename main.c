#include <stdio.h>
#include <windows.h>

int main(void) {
    int escolha, verificador;

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
            int repetir;
            do{
                printf("\n ========== CADASTRO-DE-CIDADES ==========");
                printf("\n > [1] Carregar Arquivo");
                printf("\n > [2] Adicionar Manualmente");
                printf("\n > [0] Voltar");
                printf("\n =========================================\n");
                scanf(" Opcao: %i",&repetir); 

            }while(repetir != 0 && repetir != 1 && repetir != 2);
            
            break;

        case 2:
            int repetir;
            do {
                printf("\n =========== EXIBIR-MATRIZES ===========");
                printf("\n > [1] Matriz Adjacencias");
                printf("\n > [2] Matriz Distancias Minimas");
                printf("\n > [3] Matriz de Predecessores");
                printf("\n > [0] Voltar");
                printf("\n ================================");
                printf("\n Opcao: ");
                scanf("%d", &repetir);

            } while (repetir != 0 && repetir != 1 && repetir != 2 && repetir != 3);

            break;

        case 3: 
            int repetir;
            do {
                printf("\n =========== CALCULAR-ROTA ===========");
                printf("\n > Seu Ponto de Partida: ");
                scanf("%i", &repetir);

                printf("\n > Seu Destino: ");
                scanf("%i", &repetir);

                printf("\n > [0] Cancelar");
                printf("\n ================================");
                printf("\n Opcao: ");
                scanf("%i", &repetir);

            } while (repetir != 0 && repetir != 1 && repetir != 2 && repetir != 3);

            break;

        default:
            break;
        }
        
        system("cls");

    } while (escolha != 0);

    return 0;
}