#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAXCHAR 100

// amazenar quantidade de cidades, os nomes e a matriz para o programa executar
void CarregarArquivo();
//void CadastroManual();

int main(){
    int escolha;
    printf("\n ========== CADASTRO-DE-CIDADES ==========");
    printf("\n > [1] Carregar Arquivo");
    printf("\n > [2] Adicionar Manualmente");
    printf("\n > [0] Voltar");
    printf("\n =========================================\n");
    print(" -> Opcao: %i"); 
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
        system("pause")
        break;
    }

    return 0;
}

void CarregarArquivo(){
    FILE *arquivo;

    char origem[500];
    printf(" > Qual a origem do arquivo: ");
    scanf("%s", origem);
    
    arquivo = fopen("cidades.txt", "r");
    
    int n_cidades;
    printf(" -> Quantas cidades ira cadastrar: ")

    char linha[MAXCHAR];

    if (arquivo != NULL) {
    
        if (fgets(linha, MAXCHAR, arquivo) != NULL) {
            n_cidades = atoi(linha);
        }
            
        char nomes_cidades[n_cidades][MAXCHAR];

        // Amazena nomes das cidades
        for (int i = 0; i < n_cidades; i++) {
            if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                //linha[strcspn(linha, "\n")] = 0;  // remove o \n
                for (int j = 0; j < n_cidades; j++) {
                    nomes_cidades[i][MAXCHAR] = linha;
                }
            }
        }

        for (int i = 0; i < n_cidades; i++){
            for (int j = 0; j < n_cidades; j++){
                printf(" %s ", nomes_cidades[i][j]);
            }

        }

        /*/ Lê nomes das cidades
        for (int i = 0; i < n_cidades; i++) {
            if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                //linha[strcspn(linha, "\n")] = 0;  // remove o \n
                printf(" > Cidade [%02d]: %s", i + 1, linha);
                }
                }//*/
                
            }
            
    fclose(arquivo);
    return 0;
}

/*void CadastroManual(){

    return 0;
}*/