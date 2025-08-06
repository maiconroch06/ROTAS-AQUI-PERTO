#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000

int main(void){
    FILE *arquivo;

    char origem[500];
    printf(" > Qual a origem do arquivo: ");
    scanf(" %[^\n]", origem);
    
    arquivo = fopen(origem, "r");
    
    int n_cidades;
    char linha[MAXCHAR];

    if (arquivo != NULL) {
    
        if (fgets(linha, MAXCHAR, arquivo) != NULL) {
            n_cidades = atoi(linha);
        }// ignora o \n no atoi
            
        char nomes_cidades[n_cidades][MAXCHAR];
        float A[n_cidades][n_cidades];

        // Amazena nomes das cidades
        for (int i = 0; i < n_cidades; i++) {
            if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                strcpy(nomes_cidades[i],linha);
            }
        }
        //ler matriz
        for (int i = 0; i < n_cidades; i++){
            fgets(linha, MAXCHAR, arquivo);
            
            char *token = strtok(linha, ";");
            
            for (int j = 0; j < n_cidades; j++){
                A[i][j] = atof(token);
                token = strtok(NULL, ";");
            }
    
        }

        printf("\n N-Cidades: %i",n_cidades);

        for (int i = 0; i < n_cidades; i++){
            printf("%i. %s\n",i,nomes_cidades[i]);
        }

        printf("\n");

        for (int i = 0; i < n_cidades; i++)
        {
            for (int j = 0; j < n_cidades; j++)
            {
                printf(" %.2f ",A[i][j]);
            }
            printf("\n");
        }
        
            
    fclose(arquivo);
    } else {
        printf(" foi nao");
    }
    return 0;
}