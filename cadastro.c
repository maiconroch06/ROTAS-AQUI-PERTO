#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 1000

// amazenar quantidade de cidades, os nomes e a matriz para o programa executar
int CarregarArquivo();
//void CadastroManual();

int CadastroCidades(){
    int escolha;
    printf("\n ========== CADASTRO-DE-CIDADES ==========");
    printf("\n > [1] Carregar Arquivo");
    printf("\n > [2] Adicionar Manualmente");
    printf("\n > [0] Voltar");
    printf("\n =========================================\n");
    printf(" -> Opcao: "); 
    scanf("%i",&escolha); 

    switch (escolha){
    case 1:
        CarregarArquivo();
        break;
    case 2:
        //CadastroManual();
        break;

    default:
        printf("\n #ERRO: sua escolha é invalida, tente novamente...");
        system("pause");
        break;
    }

    return 0;
}

int CarregarArquivo(){
    FILE *arquivo;
    
    do{
        system("cls");
        char origem[500];
        printf("\n > Origem do arquivo: ");
        scanf(" %[^\n]", origem);
        
        arquivo = fopen(origem, "r");
        
        int n_cidades;
        char linha[MAXCHAR];
        
        if (arquivo != NULL) {
            
            // Amazena - Numero de cidades
            if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                n_cidades = atoi(linha);
            }
                
            char nomes_cidades[n_cidades][MAXCHAR];
            float A[n_cidades][n_cidades];

            // Amazena - Nomes das cidades
            for (int i = 0; i < n_cidades; i++) {
                if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                    strcpy(nomes_cidades[i],linha);
                }
            }
            
            // Amazena - Matriz de adjacentes
            for (int i = 0; i < n_cidades; i++){
                fgets(linha, MAXCHAR, arquivo);
                
                char *token = strtok(linha, ";");
                
                for (int j = 0; j < n_cidades; j++){
                    A[i][j] = atof(token);
                    token = strtok(NULL, ";");
                }
            }
//====================================================================================================
            // Exibição - Numero de cidades
            system("cls");
            printf("\n -> Aquivo acessado: %s\n",origem);


            //printf("\n -> Numero de Cidades: %i\n",n_cidades);
            
            // Exibição - Lista de noomes de cidades
            printf("\n LISTA-DE-CIDADES:\n"); 
            for (int i = 0; i < n_cidades; i++){
                printf(" %i. %s",i+1,nomes_cidades[i]);
            }
            
            // Exibição - Matriz de Adjacentes
            printf("\n MATRIZ-DE-ADJACENTES:\n\n");
            for (int i = 0; i < n_cidades; i++){
                printf(" | ");
                for (int j = 0; j < n_cidades; j++){
                    printf(" %7.2f ",A[i][j]);
                    if(j < n_cidades - 1){
                        printf("|");
                    }
                }
                printf(" |\n");
            }
            printf("\n");
            
            fclose(arquivo);
            
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

/*void CadastroManual(){

    return 0;

}*/