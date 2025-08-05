#include <stdio.h>
#include <windows.h>

int main(void) {
    int escolha;

/*
[1] Cadastro cidade:
 > Exibir listas das cidades
 | > Exibir Matrizes:
 | | > Matriz Adjacentes
 | | > Matriz Distancias Minimas
 | | > Matriz de Prodecessores
 | | > Voltar
 > Adicionar Cidades
 | > Manualmente
 | > Carregar Arquivo
 |  > ?Quantas?
 |   > Usuário adicionar valores na matriz adjacentes. (de alguma forma tem que ter as 3 matrizes)

[2] :

 3.Salvar matriz adjacentes.
 4.Exibir as matrizes (distância ou predecessores).
 5.Executar o algoritimo?
 6.Salvar os resultados em arquivo .txt (distância e predecessores).
 7.Mostrar menor caminho entre dois municípios, após execução do algoritimo
*/
    do {
        printf("\n ============= ROTAS-AQUI-PERTO =============");
        printf("\n > [1] Cadastrar cidades");
        printf("\n > [2] ");
        printf("\n > [3] ");
        printf("\n > [0] Sair");
        printf("\n ============================================\n");
        scanf(" Opcao: %i",&escolha);

        system("cls");

        switch (escolha){
        case 1:
            int repetir;
            do{
                printf("\n ========== CADASTRO-DE-CIDADES ==========");
                printf("\n > [1] Exibir cidades disponiveis");
                printf("\n > [2] Cadastrar cidades");
                printf("\n > [0] Voltar");
                printf("\n =========================================\n");
                scanf(" Opcao: %i",&repetir);

                    switch (repetir){
                    case 1:
                        /* code */
                        break;
                    
                    default:
                        continue;
                        break;
                    }
                break;

            }while(repetir != 0 && repetir != 1 && repetir != 2);
        
        case 2: 
            int voltar = -1;
            do {
                printf("\n =========== MATRIZES ===========");
                printf("\n > [1] Matriz Adjacencias");
                printf("\n > [2] Matriz Distancias Minimas");
                printf("\n > [3] Matriz de Predecessores");
                printf("\n > [0] Voltar");
                printf("\n ================================");
                printf("\n Escolha: ");
                scanf("%d", &voltar);

                switch (voltar) {
                    case 1:
                        // função exibir matriz adjacencias
                        break;
                    case 2:
                        // função exibir matriz distancias minimas
                        break;
                    case 3:
                        // função exibir matriz de predecessores
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida.\n");
                }

            } while (voltar != 0);

            break;

        case 3:
                    /* code */
                    break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        default:
            break;
        }
        
        system("cls");

    } while (escolha != 0);

    return 0;
}