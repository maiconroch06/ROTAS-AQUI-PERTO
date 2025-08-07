#include <string.h>
#include "matriz.h"

#define MAXCHAR 1000

// amazenar quantidade de cidades, os nomes e a matriz para o programa executar
//void CadastroManual();
int CarregarArquivo();

int CadastroCidades(matrizAdj *matrizAdj){
    int escolha;

    system("cls");
    printf("\n ========== CADASTRO-DE-CIDADES ==========");
    printf("\n > [1] Adicionar Manualmente");
    printf("\n > [2] Carregar Arquivo");
    printf("\n > [0] Voltar");
    printf("\n =========================================\n");
    printf(" -> Opcao: "); 
    scanf("%i",&escolha); 

    switch (escolha){
    case 1:
        //CadastroManual();
        break;
    case 2:
        CarregarArquivo(matrizAdj);
        break;
    case 0:
        break;

    default:
        printf("\n #ERRO: sua escolha é invalida, tente novamente...\n");
        system("pause");
        break;
    }

    return 0;
}

/*void CadastroManual(){

    return 0;

}*/

int CarregarArquivo(matrizAdj *matrizAdj){
    FILE *arquivo = NULL;
    
    do{
        system("cls");
        printf("\n - - - CADASTRO AUTOMATICO - - -\n");
        char origem[500];
        printf("\n > Origem do arquivo: ");
        scanf(" %[^\n]", origem);
        
        arquivo = fopen(origem, "r");
        
        char linha[MAXCHAR];
        
        if (arquivo != NULL) {
            
            // Amazena - Numero de cidades
            if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                matrizAdj->n = atoi(linha);
            }
            
            int n_cidades = matrizAdj->n;

            // Amazena - Nomes das cidades
            for (int i = 0; i < n_cidades; i++) {
                if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                    strcpy(matrizAdj->nomes[i],linha);
                }
            }
            
            // Amazena - Matriz de adjacentes
            for (int i = 0; i < n_cidades; i++){
                fgets(linha, MAXCHAR, arquivo);
                
                char *token = strtok(linha, ";");
                
                for (int j = 0; j < n_cidades; j++){
                    matrizAdj->matriz[i][j] = atof(token);
                    token = strtok(NULL, ";");
                }
            }
//===================================================== EXIBIÇÃO =====================================================
            // Exibição - Numero de cidades
            system("cls");
            printf("\n -> Aquivo acessado: %s\n",origem);

            // Exibição - Lista de noomes de cidades
            printf("\n > LISTA-DE-CIDADES:\n"); 
            for (int i = 0; i < n_cidades; i++){
                printf(" %02d. %s",i+1,matrizAdj->nomes[i]);
            }
            
            // Exibição - Matriz de Adjacentes
            printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
            for (int i = 0; i < n_cidades; i++){
                printf(" |");
                for (int j = 0; j < n_cidades; j++){
                    printf("%7.2f",matrizAdj->matriz[i][j]);
                    if(j < n_cidades - 1){
                        printf("|");
                    }
                }
                printf(" |\n");
            }
            printf("\n");
            
            fclose(arquivo);
            system("pause");
            system("cls");
            
            // vai executar o algoritimo?

            return 0;

        } else {
            int escolhas;
            printf("\n ====== ARQUIVO INDISPONIVEL ======");
            printf("\n > [1] Tentar novamente");
            printf("\n > [0] Cancelar");
            printf("\n =================================");
            printf("\n > Escolha: ");
            scanf("%i",&escolhas);
            
            switch(escolhas){
            case 1:
                system("cls");
                break;

            case 0:
                system("cls");
                printf("\n* Saindo...\n");
                return 1;
            }
        }
    }while (1);
}
