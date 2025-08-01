#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 100

int main() {
    FILE *arquivo;
    char linha[MAXCHAR];
    int n_cidades = 0;

    arquivo = fopen("cidades.txt", "r");
    if (arquivo != NULL) {

    // Lê a primeira linha
        if (fgets(linha, MAXCHAR, arquivo) != NULL) {
            n_cidades = atoi(linha);
            printf("Quantidade de cidades: %i\n\n", n_cidades);
        }
    }

    // Lê nomes das cidades
    for (int i = 0; i < n_cidades; i++) {
        if (fgets(linha, MAXCHAR, arquivo) != NULL) {
            linha[strcspn(linha, "\n")] = 0;  // remove o \n
            printf("Cidade %02d: %s\n", i + 1, linha);
        }
    }//*/

    fclose(arquivo);
    return 0;
}
