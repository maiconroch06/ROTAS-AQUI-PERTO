#ifndef _FLOYD_
#define _FLOYD_

#include <stdio.h>
#include <stdlib.h>

// Função para salvar dados em arquivo
void salvar(int n_cidades, char cidades[][1000], float A[][100]){
    int escolhas;
    system("cls");
    printf("\n === SALVAR DADOS INICIAIS EM ARQUIVO? ====");
    printf("\n > [1] Sim > [0] Nao");
    printf("\n ===========================================");
    printf("\n Opcao: ");
    scanf("%i", &escolhas);

    if(escolhas == 1){
        // Arquivo de dados iniciais
        FILE *arquivo = fopen("cidades.txt", "w");

        if(arquivo != NULL){

            printf("\n** Arquivo 'cidades.txt' aberto com sucesso **\n");

            // Escreve no arquivo numero de cidades
            fprintf(arquivo, "%i\n", n_cidades);

            // Escreve no arquivo nomes de cidades
            for(int i = 0; i < n_cidades; i++){
                fprintf(arquivo, "%s\n", cidades[i]);
            }

            // Escreve no arquivo matriz adjacencias
            for(int i = 0; i < n_cidades; i++){
                for(int j = 0; j < n_cidades; j++){
                    fprintf(arquivo, "%.2f",A[i][j]);
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

            //SalvarResultados() Quando o algoritmo estiver pronto
        }else{
            printf(" #ERRO: ao abrir o arquivo 'cidades.txt'.\n");
        }
    } else {
        printf("Seus dados nao foram salvos em arquivo.");
    }
}
/* Quando o algoritmo estiver pronto
void SalvarResultados(){
    system("cls");

    int escolhas;
    printf("\n ====== SALVAR RESULTADOS EM ARQUIVO? =======");
    printf("\n > [1] Sim");
    printf("\n > [0] Nao");
    printf("\n ============================================");
    printf("\n Opcao: ");
    scanf("%i", &escolhas);

    if(escolhas == 1){
        // Arquivo de RESULTADOS
        FILE *arquivo = fopen("resultados.txt", "w");

        if(arquivo != NULL){

            printf("\n** Arquivo 'resultados.txt' aberto com sucesso **\n");

            // Escreve no arquivo numero de cidades
            fprintf(arquivo, "%i\n", n_cidades);

            // Escreve no arquivo distancias minimas
            for(int i = 0; i < n_cidades; i++){
                for(int j = 0; j < n_cidades; j++){
                    fprintf(arquivo, "%.2f",A[i][j]);
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
                    fprintf(arquivo, "%.2f",A[i][j]);
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
        printf("Seus dados nao foram salvos em arquivo.");
    }
}*/

#endif