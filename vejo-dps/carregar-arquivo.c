#include <windows.h>
#include <commdlg.h>
#include <stdio.h>
#include <stlib.h>

int main() {
    char filename[MAX_PATH] = "";

    OPENFILENAME ofn = {0};
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0";
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    ofn.lpstrTitle = "Selecione um arquivo";

    if (GetOpenFileName(&ofn)) {
        printf("Arquivo selecionado: %s\n", filename);
        FILE * arquivo = NULL;

        arquivo = fopen("C:/Users/20251134040027/Documents/MyProjects/IFRN-TADS-Material-C/3-avaliacoes/avaliacao-02/cidades-cadastradas/test-escrita.txt","w");

        if (arquivo != NULL){
            printf("\n * Arquivo aberto com sucesso!");
            
            fprintf(arquivo,"%s","Meu primeiro arquivo");
            
            fclose(arquivo);
        }

    } else {
        printf("Nenhum arquivo selecionado.\n");
    }

    return 0;
}
