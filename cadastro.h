#include <string.h>
#include "matriz.h"
#include "salvar.h"

#define MAXCHAR 1000

// amazenar quantidade de cidades, os nomes e a matriz para o programa executar
int CadastroManual();
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
        CadastroManual();
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

int CadastroManual(){
    int n_cidades;

    do{
        system("cls");
        printf("\n ============ CADASTRO MANUAL ============");
        printf("\n > Informe o Numero dos Municipios: ");
        scanf("%i", &n_cidades);

        float A[100][100];
        char cidades[100][1000];

// TEM QUE LIMPAR O BUFFER AQUI
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        // Inicio de cadastro de nomes das cidades
        printf(" > Nomes dos Municipios:\n");
        
        // Cadastro de nomes das cidades
        for(int i = 0; i < n_cidades; i++){
            printf("  %02d.", i + 1);
            fgets(cidades[i], sizeof(cidades), stdin);

            // Remove o '\n' se estiver presente
            cidades[i][strcspn(cidades[i], "\n")] = '\0';
        }

        printf(" > Distancia Entre dos Municipios:\n");

        // Cadastro das distâncias entre cidades
        for(int i = 0; i < n_cidades; i++){
            for(int j = i; j < n_cidades; j++){
                if(i==j){
                    A[i][j] = 0;
                } else {
                    printf(" %02d. De %s para %s: ", i + 1, cidades[i], cidades[j]);
                    scanf("%f", &A[i][j]);
                    A[j][i] = A[i][j];
                }
            }
        }

        system("cls");
        printf("\n");

        //================================ GERAR RESULTADO =======================================
        //                TALVEZ AQUI TENHA QUE TER A EXECUÇÃO DO ALGORITMO
        //=================================== EXIBIÇÃO ===========================================

        // Exibição - Lista de nomes de cidades
        printf("\n > LISTAS-DE-CIDADES:\n"); 
        for (int i = 0; i < n_cidades; i++){
            printf(" %02d. %s\n",i+1,cidades[i]);
        }

        // Exibição - Matriz de Adjacentes
        printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
        for(int i = 0; i < n_cidades; i++){
            printf(" |");
            for(int j = 0; j < n_cidades; j++){
                printf(" %7.2f ", A[i][j]);
                if(j < (n_cidades - 1)){
                    printf("|");
                }
            }
            printf(" |\n");
        }
        printf("\n");

        //Confirmação
        int escolhas;
        printf("\n ====== DESEJA CONFIRMAR ESSES VALORES? ======");
        printf("\n > [1] Confirmar > [2] Alterar > [0] Cancelar");
        printf("\n =============================================");
        printf("\n -> Opcao: ");
        scanf("%i", &escolhas);

        switch(escolhas){
            case 1:
                salvar(n_cidades, cidades, A); // Passa dados para salvar
                return 0; //?????????? n sei se tem mais coisa

                break;
            case 2:
                printf("\n* Alterar Valores!");
                break;
            case 0:
                printf("\n* Valores Cancelados!");
                return 0;
        }
    }while(1);
}

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

