#include <string.h>
#include "matriz.h"
#include "salvar.h"

#define MAXCHAR 1000

// amazenar quantidade de cidades, os nomes e a matriz para o programa executar
int CadastroManual();
int CarregarArquivo();

int CadastroCidades(matrizAdj *matrizAdj){
    int escolha;
    do{
        system("cls");
        printf("\n ========== CADASTRO-DE-CIDADES ==========");
        printf("\n > [1] Adicionar Manualmente");
        printf("\n > [2] Carregar Arquivo");
        printf("\n > [0] Voltar");
        printf("\n =========================================");
        printf("\n -> Opcao: "); 
        scanf("%i",&escolha); 
        
        switch (escolha){
        case 1:
            CadastroManual(matrizAdj);
            return 0;
        case 2:
            CarregarArquivo(matrizAdj);
            return 0;
        case 0:
            return 0;
            
        default:
            break;
        }
    }while (1);
    
}

int CadastroManual(matrizAdj *matrizAdj){
    int n_cidades = matrizAdj->n;
    
    do{
        system("cls");
        printf("\n ============ CADASTRO-MANUAL ============");
        printf("\n > Informe o Numero dos Municipios: ");
        scanf("%i", &n_cidades);

// TEM QUE LIMPAR O BUFFER AQUI
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        // Inicio de cadastro de nomes das cidades
        printf(" > Nomes dos Municipios:\n");
        
        // Cadastro de nomes das cidades
        for(int i = 0; i < n_cidades; i++){
            printf("  %02d.", i + 1);
            fgets(matrizAdj->nomes[i], sizeof(matrizAdj->nomes), stdin);

            // Remove o '\n' se estiver presente
            matrizAdj->nomes[i][strcspn(matrizAdj->nomes[i], "\n")] = '\0';
        }

        printf(" > Distancia Entre dos Municipios:\n");

        // Cadastro das distâncias entre cidades
        for(int i = 0; i < n_cidades; i++){
            for(int j = i; j < n_cidades; j++){
                if(i==j){
                    matrizAdj->matriz[i][j] = 0;
                } else {
                    printf("  %02d.De '%s' para '%s': ", j + 1, matrizAdj->nomes[i], matrizAdj->nomes[j]);
                    scanf("%f", &matrizAdj->matriz[i][j]);
                    matrizAdj->matriz[j][i] = matrizAdj->matriz[i][j];
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
            printf("  %02d.%s\n",i+1,matrizAdj->nomes[i]);
        }

        // Exibição - Matriz de Adjacentes
        printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
        for(int i = 0; i < n_cidades; i++){
            printf(" |");
            for(int j = 0; j < n_cidades; j++){
                printf(" %7.2f ", matrizAdj->matriz[i][j]);
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
                SalvarDadosIniciais(&matrizADJ); // Passa dados para salvar
                //SalvarResultados(&matrizADJ)
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
        char origem[500];
        printf("\n - - - CADASTRO AUTOMATICO - - -\n");
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

