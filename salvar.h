#ifndef _FLOYD_
#define _FLOYD_

#include <stdio.h>
#include <stdlib.h>

// Função para salvar dados em arquivo
int SalvarDadosIniciais(matrizAdj *matrizAdj){
    int escolhas;
    do{
        system("cls");
        printf("\n ==== SALVAR DADOS INICIAIS EM ARQUIVO? ====");
        printf("\n > [1] Sim > [0] Nao");
        printf("\n ===========================================");
        printf("\n Opcao: ");
        scanf("%i", &escolhas);

        if(escolhas == 1){
            // Arquivo de dados iniciais
            FILE *arquivo = fopen("cidades.txt", "w");

            if(arquivo != NULL){

                printf("\n** Arquivo 'cidades.txt' aberto com sucesso **\n");

                int n_cidades = matrizAdj->n;

                // Escreve no arquivo numero de cidades
                fprintf(arquivo, "%i\n", n_cidades);

                // Escreve no arquivo nomes de cidades
                for(int i = 0; i < n_cidades; i++){
                    fprintf(arquivo, "%s\n", matrizAdj->nomes[i]);
                }

                // Escreve no arquivo matriz adjacencias
                for(int i = 0; i < n_cidades; i++){
                    for(int j = 0; j < n_cidades; j++){
                        fprintf(arquivo, "%.2f",matrizAdj->matriz[i][j]);
                        if(j < n_cidades - 1){
                            fprintf(arquivo, ";");
                        }
                    }
                    if (i < n_cidades - 1){
                        fprintf(arquivo, "\n");
                    }
                }

                fclose(arquivo);
                printf("** Dados salvos com sucesso **\n");

            }else{
                printf(" #ERRO: ao abrir o arquivo 'cidades.txt'.\n");
            }
        } else {
            return 0;
        }
    }while(1);
}

/* Quando o algoritmo estiver pronto
int SalvarResultados(matrizAdj *matrizAdj){
    system("cls");
    do{
        int escolhas;
        printf("\n ====== SALVAR RESULTADOS EM ARQUIVO? =======");
        printf("\n > [1] Sim > [0] Nao");
        printf("\n ============================================");
        printf("\n Opcao: ");
        scanf("%i", &escolhas);

        if(escolhas == 1){
            // Arquivo de RESULTADOS
            FILE *arquivo = fopen("resultados.txt", "w");

            if(arquivo != NULL){

                printf("\n** Arquivo 'resultados.txt' aberto com sucesso **\n");

                int n_cidades = matrizAdj->n;

                // Escreve no arquivo numero de cidades
                fprintf(arquivo, "%i\n", n_cidades);

                // Escreve no arquivo distancias minimas
                for(int i = 0; i < n_cidades; i++){
                    for(int j = 0; j < n_cidades; j++){
                        fprintf(arquivo, "%.2f",matrizAdj->matriz[i][j]);
                        if(j < n_cidades - 1){
                            fprintf(arquivo, ";");
                        }
                    }
                    if (i < n_cidades - 1){
                        fprintf(arquivo, "\n");
                    }
                }
                
                // Escreve no arquivo prodecessores
                for(int i = 0; i < n_cidades; i++){
                    for(int j = 0; j < n_cidades; j++){
                        fprintf(arquivo, "%.2f",matrizAdj->matriz[i][j]);
                        if(j < n_cidades - 1){
                            fprintf(arquivo, ";");
                        }
                    }
                    if (i < n_cidades - 1){
                        fprintf(arquivo, "\n");
                    }
                }

                fclose(arquivo);
                printf("** Dados salvos com sucesso **\n");

                //SalvarResultados()
            }else{
                printf(" #ERRO: ao abrir o arquivo 'resultados.txt'.\n");
            }
        } else {
            return 0;
        }
    }while(1);
}*/

#endif