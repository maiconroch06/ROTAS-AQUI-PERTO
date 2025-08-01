/*

Interface 1: MENU

========= ROTAS-AQUI-PERTO =========
> [1] Cadastrar cidades
> [2] Exibir cidades cadastradas -
> [3]
*/

/*
========= ROTAS-AQUI-PERTO =========
> Nome cidade:
> Distancia:
> 

*/

#include <stdio.h>
#include <windows.h>

int main(void) {
    int escolha;

    printf("\n ========= ROTAS-AQUI-PERTO =========");
    printf("\n > [1] Cadastrar cidades");
    printf("\n > [2] Exibir cidades cadastradas");
    printf("\n > [3] Exibir Matrizes");
    printf("\n > [0] Sair");
    printf("\n ====================================\n");
    scanf("%i",&escolha);

    system("cls");

    switch (escolha)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        printf("\n ========= MATRIZES =========");
        printf("\n [1] Matriz Adjacencias");
        printf("\n [2] Matriz Distancias Minimas");
        printf("\n [3] Matriz de Procedentes");
        
        printf("\n ============================");
        scanf("%i");

        // função que exibe matriz de escolha 
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

    return 0;
}