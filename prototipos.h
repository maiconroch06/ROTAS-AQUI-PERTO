#ifndef _PROTOTIPOS_H
#define _PROTOTIPOS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXCHAR 1000

// ===================== Tipos =====================
typedef struct {
    int n; // Número de cidades
    char nomes[100][255];
    double matriz[100][100];
} matrizAdj;

// ============== Assinaturas (static) =============
static int  CadastroCidades(matrizAdj *matrizAdj);
static int  CadastroManual(matrizAdj *m);
static int  CarregarArquivo(matrizAdj *matrizAdj);

static void ExibirMatrizes(matrizAdj *matrizADJ, int N, double d[][N], int p[][N]);
static void ExibirMatrizAdj(matrizAdj *m);
static void ExibirMatrizD(int n, double matriz[n][n]);
static void ExibirMatrizP(int n, int matriz[n][n]);

static void Salvar(matrizAdj *matrizAdj, int N, double d[][N], int p[][N]);
static int  SalvarDadosIniciais(matrizAdj *matrizAdj);
static int  SalvarResultados(int N, double d[][N], int p[][N]);

static void floydWarshall(matrizAdj *m, int N, double d[][N], int p[][N]);

static void CalcularRota(const matrizAdj *m, int N, const double d[][N], const int p[][N]);
static int  ReconstruirCaminho(int N, int origem, int destino, const int p[][N], int path_out[]);

// ================= Implementações =================

// =================== cadastro.c ===================
static int CadastroManual(matrizAdj *m){
    int n_cidades = m->n;
    do{
        system("cls");
        printf("\n ============ CADASTRO-MANUAL ============");
        printf("\n > Informe o Numero dos Municipios: ");
        scanf("%i", &n_cidades);
        m->n = n_cidades;

        printf(" > Nomes dos Municipios:\n");
        for (int i = 0; i < n_cidades; i++){
            printf("  %02d. ", i + 1);
            scanf(" %[^\n]", m->nomes[i]);
        }

        printf(" > Distancia Entre os Municipios:\n");
        for (int i = 0; i < n_cidades; i++){
            for (int j = i; j < n_cidades; j++){
                if (i == j){
                    m->matriz[i][j] = 0.0;
                } else {
                    printf("\n> De %s para %s: ", m->nomes[i], m->nomes[j]);
                    scanf("%lf", &m->matriz[i][j]);
                    m->matriz[j][i] = m->matriz[i][j];
                }
            }
        }

        system("cls");
        printf("\n -> ==== MATRIZ CADASTRADA COM SUCESSO !! ====\n");
        ExibirMatrizAdj(m);

        int escolhas;
        printf("\n ==== Deseja Confirmar Valores? ====");
        printf("\n > [1] Confirmar");
        printf("\n > [2] Alterar");
        printf("\n > [0] Cancelar ");
        printf("\n ===================================");
        printf("\n -> Opcao: ");
        scanf("%i", &escolhas);

        system("cls");
        switch (escolhas){
            case 1:
                printf("\n* Valores Confirmados!\n");
                SalvarDadosIniciais(m);
                return 1;
            case 2:
                printf("\n* Alterar Valores!\n");
                break; // volta ao loop e recadastra
            case 0:
                printf("\n* Valores Cancelados!\n");
                return 0;
            default:
                break;
        }
    } while (1);
}

static int CarregarArquivo(matrizAdj *m){
    FILE *arquivo = NULL;
    do{
        system("cls");
        char origem[500];
        printf("\n ============ CARREGAR-ARQUIVO ============");
        printf("\n > Origem do arquivo: ");
        scanf(" %[^\n]", origem);

        arquivo = fopen(origem, "r");
        char linha[MAXCHAR];

        if (arquivo != NULL){
            // Número de cidades
            if (fgets(linha, MAXCHAR, arquivo) != NULL){
                m->n = atoi(linha);
            }
            int n_cidades = m->n;

            // Nomes
            for (int i = 0; i < n_cidades; i++){
                if (fgets(linha, MAXCHAR, arquivo) != NULL){
                    size_t L = strlen(linha);
                    if (L && linha[L-1] == '\n') linha[L-1] = '\0';
                    strcpy(m->nomes[i], linha);
                }
            }

            // Matriz
            for (int i = 0; i < n_cidades; i++){
                if (!fgets(linha, MAXCHAR, arquivo)) break;
                char *token = strtok(linha, ";");
                for (int j = 0; j < n_cidades; j++){
                    m->matriz[i][j] = token ? atof(token) : 10000.0;
                    token = strtok(NULL, ";");
                }
            }

            ExibirMatrizAdj(m);
            fclose(arquivo);
            system("pause");
            return 1;
        } else {
            int escolhas;
            printf("\n ====== ARQUIVO INDISPONIVEL ======");
            printf("\n > [1] Tentar novamente");
            printf("\n > [0] Cancelar");
            printf("\n =================================");
            printf("\n > Escolha: ");
            scanf("%i", &escolhas);

            switch (escolhas){
                case 1: system("cls"); break;
                case 0:
                    system("cls");
                    printf("\n* Saindo...\n");
                    return 0;
                default:
                    break;
            }
        }
    } while (1);
}

static int CadastroCidades(matrizAdj *m){
    int escolha;
    system("cls");
    printf("\n ========== CADASTRO-DE-CIDADES ==========");
    printf("\n > [1] Adicionar Manualmente");
    printf("\n > [2] Carregar Arquivo");
    printf("\n > [0] Voltar");
    printf("\n =========================================\n");
    printf(" -> Opcao: ");
    scanf("%i", &escolha);

    switch (escolha){
        case 1:
            return CadastroManual(m);
        case 2:
            return CarregarArquivo(m);
        case 0:
            return 0;
        default:
            return 0;
    }
}

// ==================== exibir.c ====================
static void ExibirMatrizes(matrizAdj *m, int N, double d[][N], int p[][N]) {
    int escolha;
    do {
        system("cls");
        printf("\n =========== EXIBIR-MATRIZES ===========");
        printf("\n > [1] Matriz Adjacencias");
        printf("\n > [2] Matriz Distancias Minimas");
        printf("\n > [3] Matriz de Predecessores");
        printf("\n > [0] Voltar");
        printf("\n =======================================");
        printf("\n -> Opcao: ");
        scanf("%d", &escolha);

        switch (escolha){
            case 1: 
                ExibirMatrizAdj(m); 
                break;
                case 2: 
                ExibirMatrizD(N, d);
                break;
                case 3:
                ExibirMatrizP(N, p); 
                break;
            case 0: 
                return;
            default: 
                break;
        }
    } while (1);
}

static void ExibirMatrizAdj(matrizAdj *m){
    int n_cidades = m->n;
    system("cls");
    printf("\n > LISTA-DE-CIDADES:\n");
    for (int i = 0; i < n_cidades; i++){
        printf(" %.02d. %s\n", i + 1, m->nomes[i]);
    }

    printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
    for (int i = 0; i < n_cidades; i++){
        printf(" | ");
        for (int j = 0; j < n_cidades; j++){
            printf(" %7.2f ", m->matriz[i][j]);
            if (j < n_cidades - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
    system("pause");
}

static void ExibirMatrizD(int n, double matriz[n][n]){
    system("cls");
    printf("\n > MATRIZ-DE-DISTANCIAS-MINIMAS:\n\n");
    for (int i = 0; i < n; i++){
        printf(" | ");
        for (int j = 0; j < n; j++){
            printf(" %.2f ", matriz[i][j]);
            if (j < n - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
    system("pause");
}

static void ExibirMatrizP(int n, int matriz[n][n]){
    system("cls");
    printf("\n > MATRIZ-DE-PREDECESSORES:\n\n");
    for (int i = 0; i < n; i++){
        printf(" | ");
        for (int j = 0; j < n; j++){
            printf(" %d ", matriz[i][j]);
            if (j < n - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
    system("pause");
}

// ==================== salvar.c ====================
static void Salvar(matrizAdj *m, int N, double d[][N], int p[][N]) {
    int escolhas;
    do{
        system("cls");
        printf("\n ========= O QUE SALVAR? =========");
        printf("\n [1] Dados Iniciais");
        printf("\n [2] Dados Resultantes");
        printf("\n [0] Voltar");
        printf("\n =================================");
        printf("\n Opcao: ");
        scanf("%i", &escolhas);

        switch (escolhas){
            case 1:
                (void)SalvarDadosIniciais(m);
                break;
            case 2:
                (void)SalvarResultados(N, d, p);
                break;
            case 0:
                return;
            default:
                break;
        }
    } while (1);
}

static int SalvarDadosIniciais(matrizAdj *m){
    int escolhas;
    do{
        system("cls");
        printf("\n ==== SALVAR DADOS INICIAIS EM ARQUIVO? ====");
        printf("\n > [1] Sim > [0] Nao");
        printf("\n ===========================================");
        printf("\n Opcao: ");
        scanf("%i", &escolhas);

        if (escolhas == 1){
            FILE *arquivo = fopen("cidades.txt", "w");
            
            if (arquivo != NULL){
                printf("\n** Arquivo 'cidades.txt' aberto com sucesso **\n");
                int n_cidades = m->n;
                fprintf(arquivo, "%i\n", n_cidades);
                for (int i = 0; i < n_cidades; i++){
                    fprintf(arquivo, "%s\n", m->nomes[i]);
                }
                for (int i = 0; i < n_cidades; i++){
                    for (int j = 0; j < n_cidades; j++){
                        fprintf(arquivo, "%.2f", m->matriz[i][j]);
                        if (j < n_cidades - 1){
                            fprintf(arquivo, ";");
                        }
                    }
                    if (i < n_cidades - 1){
                        fprintf(arquivo, "\n");
                    }
                }
                fclose(arquivo);
                printf("** Dados salvos com sucesso **\n");
                system("pause");
                return 1;
            } else {
                printf(" #ERRO: ao abrir o arquivo 'cidades.txt'.\n");
                system("pause");
                return 0;
            }
        } else {
            return 0;
        }
    } while (1);
}

static int SalvarResultados(int N, double d[][N], int p[][N]){
    int escolhas;
    do{
        system("cls");
        printf("\n ====== SALVAR RESULTADOS EM ARQUIVO? =======");
        printf("\n > [1] Sim > [0] Nao");
        printf("\n ============================================");
        printf("\n Opcao: ");
        scanf("%i", &escolhas);
        
        if (escolhas == 1){
            FILE *arquivo = fopen("resultados.txt", "w");
            
            if (arquivo != NULL){
                printf("\n** Arquivo 'resultados.txt' aberto com sucesso **\n");
                fprintf(arquivo, "%i\n", N);

                // distâncias (double)
                for (int i = 0; i < N; i++){
                    for (int j = 0; j < N; j++){
                        fprintf(arquivo, "%.2f", d[i][j]);
                        if (j < N - 1){
                            fprintf(arquivo, ";");
                        }
                    }
                    if (i < N - 1){
                        fprintf(arquivo, "\n");
                    }
                }

                // predecessores (int)
                fprintf(arquivo, "\n");
                for (int i = 0; i < N; i++){
                    for (int j = 0; j < N; j++){
                        fprintf(arquivo, "%d", p[i][j]);
                        if (j < N - 1){
                            fprintf(arquivo, ";");
                        }
                    }
                    if (i < N - 1){
                        fprintf(arquivo, "\n");
                    }
                }
                
                fclose(arquivo);
                printf("** Dados salvos com sucesso **\n");
                system("pause");

                return 1;
            } else {
                printf(" #ERRO: ao abrir o arquivo 'resultados.txt'.\n");
                system("pause");
                return 0;
            }
        } else {
            return 0;
        }
    } while (1);
}

// ===================== floyd.c ====================
static void floydWarshall(matrizAdj *m, int N, double d[][N], int p[][N]) {
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = m->matriz[i][j];

            if (i == j){
                p[i][j] = -1;
            } else if (m->matriz[i][j] < 10000.0){
                p[i][j] = i;
            } else {
                p[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((d[i][k] + d[k][j]) < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

// =================== calcRota.c ===================
static int ReconstruirCaminho(int N, int origem, int destino, const int p[][N], int path_out[]){
    if (origem < 0 || origem >= N || destino < 0 || destino >= N) return -1;

    if (origem == destino) {
        path_out[0] = origem;
        return 1;
    }

    int stack[N];
    int top = 0;

    int atual = destino;
    stack[top++] = destino;

    while (atual != origem) {
        int pred = p[origem][atual];
        
        if (pred < 0){
            return -1; // sem caminho
        }

        atual = pred;

        if (top >= N){
            return -1; // proteção
        }

        stack[top++] = atual;
    }

    int len = 0;
    for (int k = top - 1; k >= 0; k--) {
        path_out[len++] = stack[k];
    }
    return len;
}

static void CalcularRota(const matrizAdj *m, int N, const double d[][N], const int p[][N]){
    system("cls");
    printf("\n =========== CALCULAR-ROTA ===========\n");
    printf(" Escolha pelo numero da cidade:\n\n");

    for (int i = 0; i < N; i++) {
        printf(" %2d) %s\n", i + 1, m->nomes[i]);
    }

    int opOrigem, opDestino;
    printf("\n Origem (1..%d): ", N);
    if (scanf("%d", &opOrigem) != 1){
        puts("Entrada invalida.");
        system("pause");
        return;
    }

    printf(" Destino (1..%d): ", N);
    if (scanf("%d", &opDestino) != 1){
        puts("Entrada invalida.");
        system("pause");
        return;
    }

    if (opOrigem < 1 || opOrigem > N || opDestino < 1 || opDestino > N) {
        puts("\n !! Numero de cidade invalido !!");
        system("pause");
        return;
    }

    int origem  = opOrigem  - 1;
    int destino = opDestino - 1;

    if (origem != destino && p[origem][destino] < 0) {
        printf("\n Nao existe caminho de '%s' para '%s'.\n", m->nomes[origem], m->nomes[destino]);
        system("pause");
        return;
    }

    int path[N];
    int len = ReconstruirCaminho(N, origem, destino, p, path);

    if (len < 0) {
        printf("\n Nao existe caminho de '%s' para '%s'.\n", m->nomes[origem], m->nomes[destino]);
        system("pause");
        return;
    }

    printf("\n Rota: ");
    for (int k = 0; k < len; k++) {
        printf("%s", m->nomes[path[k]]);
        if (k < len - 1){
            printf(" -> ");
        }
    }
    printf("\n Distancia total: %.2f\n", d[origem][destino]);

    system("pause");
}

#endif
