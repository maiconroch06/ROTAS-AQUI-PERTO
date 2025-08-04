#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 100

// amazenar quantidade de cidades, os nomes e a matriz para o programa executar

int main() {
    FILE *arquivo;
    char linha[MAXCHAR];
    int n_cidades = 0;

    arquivo = fopen("cidades.txt", "r");
    if (arquivo != NULL) {

    // Lê a primeira linha
        if (fgets(linha, MAXCHAR, arquivo) != NULL) {
            n_cidades = atoi(linha);
            printf("\n - Quantidade de cidades: %i\n\n", n_cidades);
        }


        
    }

    char nomes_cidades[n_cidades][MAXCHAR];

    // Amazena nomes das cidades
    for (int i = 0; i < n_cidades; i++) {
        if (fgets(linha, MAXCHAR, arquivo) != NULL) {
            //linha[strcspn(linha, "\n")] = 0;  // remove o \n
            for (int j = 0; j < n_cidades; j++)
            {
                nomes_cidades[i] = linha;
            }
            
        }
    }//*/


    for (int i = 0; i < n_cidades; i++)
    {
        for (int j = 0; j < n_cidades; j++)
        {
            pitinf(" %s ", nomes_cidades[i][j]);
        }

        
    }
    

    /*/ Lê nomes das cidades
    for (int i = 0; i < n_cidades; i++) {
        if (fgets(linha, MAXCHAR, arquivo) != NULL) {
            //linha[strcspn(linha, "\n")] = 0;  // remove o \n
            printf(" > Cidade [%02d]: %s", i + 1, linha);
        }
    }//*/


    fclose(arquivo);
    return 0;
}
