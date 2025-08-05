#include <stdio.h>
#include <windows.h>

int main(void) {
    int escolha, verificador;

/* 
[1] Adicionar Cidades
 > Carregar Arquivo
 | *Ler quantidade de cidades e amazenar*
 | | *Ler nomes de cidades e amazenar*
 | | | *Ler matriz de adjacentes e amazenar*
 | | | | > Salvar Resultado em um Arquivo [- - - Expecifique local? - - -]
 > Manualmente
 | | > Quantas Cidades?
 | | | > Adicionar valores da distancia de uma cidades para outra
 | | | | - - *Exibir Tabela que o Usuario adicionou os valores* - -
 | | | | > Deseja Confirmar Valores? (Alterar[2] ou Confirmar[1] ou Cancelar[0])?
 | | | | Se [1] : (Exibi tabela para editar)
 | | | | Se [2] : (Voltar para menu principal)
 | | | | Se [0] : (Voltar para o menu no estado inicial)

 = = = *verificador* = = =

[2] Exibir Matrizes
 | > Matriz Adjacentes
 | > Matriz Distancias Minimas
 | > Matriz de Prodecessores
 | > Salvar Resultado em um Arquivo [- - - Expecifique local? - - -]
 | > Voltar
[3] Calcular Rota
 | > Inicio e
 | | > Destino
 - - - - [Exibir Menor Rota] - - - -
*/

    do {
        printf("\n ============= ROTAS-AQUI-PERTO =============");
        printf("\n > [1] Adicionar Arquivo");
        printf("\n > [2] Exibir Matrizes");
        printf("\n > [3] Calcular Rota");
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