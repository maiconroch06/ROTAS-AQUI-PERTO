#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Alunos {
    char nome[255];

    int matricula, idade;
    
    double nota1, nota2;
};

typedef struct Alunos Alunos;


void cadastro(Alunos **aluno, int *i, int *tamanhoAlocado);
void exibirAlunoMatricula(Alunos *aluno, int i);
void exibirTodos(Alunos *aluno, int i);
void editarAluno(Alunos *aluno, int i);
int mediaAluno(Alunos *aluno, int indice);
//int mediaTurma(Alunos *aluno, int i);
int buscarAluno(Alunos *aluno, int i);

int main (void){
    printf("\n\n<=================== I N I C I O ===================>\n\n");
    Alunos *alunos = NULL;
    int i = 0, opcao = 0, tamanhoAlocado = 10;

    alunos = malloc(tamanhoAlocado * sizeof(int));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    do {
        system("cls");
        printf("\n <========== M E N U ==========>\n");
        printf(" [1] < Cadastrar Novo Aluno >\n");
        printf(" [2] < Exibir Informacoes De Um Aluno Especifico >\n");
        printf(" [3] < Exibir Todos Os Alunos >\n");
        printf(" [4] < Alterar Informacoes De Um Aluno >\n");
        printf(" [5] < Exibir Media De Um Aluno >\n");
        printf(" [6] < Exibir Media Da Turma >\n"); //problema
        printf(" [7] < Calcular Media >\n");
        printf(" [0] < Sair >\n");
        printf("\n * Escolha Uma Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastro(&alunos, &i, &tamanhoAlocado);
                break;
            case 2:
                exibirAlunoMatricula(alunos, i);
                break;
            case 3:
                exibirTodos(alunos, i);
                break;
            case 4:
                editarAluno(alunos, i);
                break;
            case 5:
                int aux, repetir, indice;
                do{
                    indice = buscarAluno(alunos, i);
                    if(indice != -1){
                        repetir = 0;
                    } else {
                        do {
                            printf("\n\n <=== OPCOES ===>\n");
                            printf("[0] < Voltar >\n");
                            printf("[1] < Tentar Novamente >\n");
                            printf(" * Escolha Uma Opcao: ");
                            scanf("%d", &repetir);

                            if(repetir == 0) {
                                repetir = 2;
                                break;
                            }
                        } while (repetir != 1);
                    }
                } while(repetir == 1);

                system("cls");

                if(repetir == 2) {
                    opcao = 2;
                    continue;
                }

                double media = mediaAluno(alunos, indice);
                printf(" => Media do aluno(a) '%s' eh: %lf\n\n", alunos[indice].nome, media);

                printf(" [0] < Voltar >\n");
                printf(" * Escolha Uma Opcao: ");
                scanf("%i", &aux);

                break;
            //case 6:
                //mediaTurma(alunos, i);
                //break;
            case 0:
                system("cls");
                printf(" Encerrando O Programa...\n");

                break;
            default:
                system("cls");
                printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                printf(" !! OPCAO INVALIDA !!");
                Sleep(1500);
        }
    } while(opcao != 0);
    

    free(alunos);
    printf("\n\n<==================== F I N A L ====================>\n\n");
    return 0;
}

void cadastro(Alunos **aluno, int *i, int *tamanhoAlocado){
    int indice = 0;
    do {
        system("cls");
        if((i+1) > tamanhoAlocado) {
            *tamanhoAlocado += 10;
            Alunos *temp = realloc(*aluno, (*tamanhoAlocado) * sizeof(Alunos));
            if(temp != NULL) {
                *aluno = temp;

                printf("\n\n <===== C A D A S T R O =====>\n");
                printf(" * Nome: ");
                scanf(" %[^\n]", (*aluno)[*i].nome);

                printf(" * Idade: ");
                scanf("%d", &(*aluno)[*i].idade);

                printf(" * Matricula: ");
                scanf("%d", &(*aluno)[*i].matricula);

                printf(" * Nota 1: ");
                scanf("%lf", &(*aluno)[*i].nota1);

                printf(" * Nota 2: ");
                scanf("%lf", &(*aluno)[*i].nota2);

                (*i)++;

            } else {
                printf("ERRO AO ALOCAR MEMORIA.\n");
            }
        }

        do {
            printf("\n\n <=== OPCOES ===>\n");
            printf("[0] < Voltar >\n");
            printf("[1] < Novo Aluno >\n");
            printf(" * Escolha Uma Opcao: ");
            scanf("%d", &indice);
        } while (indice != 1 && indice != 0);

    } while (indice == 1);
}

int buscarAluno(Alunos *aluno, int i) {
    system("cls");
    int matricula;
    printf(" * Informe A Matricula Do Aluno: ");
    scanf("%d", &matricula);
    for(int j = 0; j < i; j++) {
        if(matricula == aluno[j].matricula) {
            return j;
        }
    }
    system("cls");

    printf("\n\n<=================== E R R O ! ! ===================>\n\n");
    printf(" !! Matricula nao encontrada !!\n !! Por Favor Verique se a matricula '%i' esta correta !!\n", matricula);
    Sleep(1000);

    return -1;
    }

void exibirAluno (Alunos *aluno, int i) {
    printf("\n <======== ALUNO: '%s' ========>\n", aluno[i].nome);
    printf("\n => Nome: %s\n", aluno[i].nome);
    printf(" => Idade: %i\n", aluno[i].idade);
    printf(" => Matricula: %i\n", aluno[i].matricula);
    printf(" => 1a Nota: %.1lf\n", aluno[i].nota1);
    printf(" => 2a Nota: %.1lf\n", aluno[i].nota2);
}

void exibirAlunoMatricula(Alunos *aluno, int i){
    system("cls");
    printf("\n\n <======= I N F O R M A C O E S =======>\n");
    int repetir = 1;

    while(repetir) {
        int indice = buscarAluno(aluno, i);

        if(indice != -1){
            exibirAluno(aluno, indice);
        }

        do {
            printf("\n\n <=== OPCOES ===>\n");
            printf("[0] < Voltar >\n");
            printf("[1] < Outro Aluno >\n");
            printf(" * Escolha Uma Opcao: ");
            scanf("%d", &repetir);
        } while (repetir != 1 && repetir != 0);
        
    }
}

void exibirTodos(Alunos *aluno, int i) {
    system("cls");
    int aux;

    printf("\n\n <========== TODOS OS ALUNOS ==========>");
    for(int j = 0; j < i; j++) {
        exibirAluno(aluno, j);
    }
    printf("\n <=====================================>\n");

    printf(" [0] < Voltar >\n");
    printf(" * Escolha Uma Opcao: ");
    scanf("%i", &aux);
}

void editarNome(char *nome){
    int opcao;
    
    printf("\n <========== EDITAR NOME ==========>\n");
    do{
        system("cls");
        char aux[255];
        printf(" * Nome Antigo: %s\n", nome);
        printf(" * Nome Novo: ");
        scanf(" %[^\n]", aux);

        do{
            system("cls");

            printf("\n <========= Confirmacao =========>\n\n");
            printf(" => Voce realmente deseja modificar '%s' para '%s'\n", nome, aux);
            printf(" [1] < Confirmar >\n");
            printf(" [2] < Alterar >\n");
            printf(" [0] < Cancelar >\n");
            printf("\n * Escolha Uma Opcao: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao) {
            case 1:
                strcpy(nome, aux);
                printf(" <=== NOME ALTERADO COM SUCESSO ===>");
                opcao = 0;
                break;
        
            case 2:
                break;

            case 0:
                printf(" <==== NOME NAO ALTERADO ====>");
                break; 

            default:
                printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                printf(" !! OPCAO INVALIDA !!");
                break;
            }

            Sleep(2000);

        } while (opcao != 0 && opcao != 1 && opcao != 2);

        system("cls");
    } while(opcao != 0);

}

void editarIdade(int *idade){
    int opcao;
    
    printf("\n <========== EDITAR IDADE ==========>\n");
    do{
        system("cls");
        int aux;
        printf(" * Idade Antiga: %i\n", *idade);
        printf(" * Idade Nova: ");
        scanf(" %d", &aux);

        do{
            system("cls");

            printf("\n <========= Confirmacao =========>\n\n");
            printf(" => Voce realmente deseja modificar '%i' para '%i'\n", *idade, aux);
            printf(" [1] < Confirmar >\n");
            printf(" [2] < Alterar >\n");
            printf(" [0] < Cancelar >\n");
            printf("\n * Escolha Uma Opcao: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao) {
            case 1:
                *idade = aux;
                printf(" <=== IDADE ALTERADA COM SUCESSO ===>");
                opcao = 0;
                break;
        
            case 2:
                break;

            case 0:
                printf(" <==== IDADE NAO ALTERADA ====>");
                break; 

            default:
                printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                printf(" !! OPCAO INVALIDA !!");
                break;
            }

            Sleep(2000);

        } while (opcao != 0 && opcao != 1 && opcao != 2);

        system("cls");
    } while(opcao != 0);

}

void editarMatricula(int *matricula){
    int opcao;
    
    printf("\n <========== EDITAR MATRICULA ==========>\n");
    do{
        system("cls");
        int aux;
        printf(" * Matricula Antiga: %i\n", *matricula);
        printf(" * Matricula Nova: ");
        scanf(" %d", &aux);

        do{
            system("cls");

            printf("\n <========= Confirmacao =========>\n\n");
            printf(" => Voce realmente deseja modificar '%i' para '%i'\n", *matricula, aux);
            printf(" [1] < Confirmar >\n");
            printf(" [2] < Alterar >\n");
            printf(" [0] < Cancelar >\n");
            printf("\n * Escolha Uma Opcao: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao) {
            case 1:
                *matricula = aux;
                printf(" <=== MATRICULA ALTERADA COM SUCESSO ===>");
                opcao = 0;
                break;
        
            case 2:
                break;

            case 0:
                printf(" <==== MATRICULA NAO ALTERADA ====>");
                break; 

            default:
                printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                printf(" !! OPCAO INVALIDA !!");
                break;
            }

            Sleep(2000);

        } while (opcao != 0 && opcao != 1 && opcao != 2);

        system("cls");
    } while(opcao != 0);

}

void editarNota1(double *nota1){
    int opcao;
    
    printf("\n <========== EDITAR NOTA 1 ==========>\n");
    do{
        system("cls");
        double aux;
        printf(" * Nota Antiga: %.2lf\n", *nota1);
        printf(" * Nota Nova: ");
        scanf(" %lf", &aux);

        do{
            system("cls");

            printf("\n <========= Confirmacao =========>\n\n");
            printf(" => Voce realmente deseja modificar '%.2lf' para '%.2lf'\n", *nota1, aux);
            printf(" [1] < Confirmar >\n");
            printf(" [2] < Alterar >\n");
            printf(" [0] < Cancelar >\n");
            printf("\n * Escolha Uma Opcao: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao) {
            case 1:
                *nota1 = aux;
                printf(" <=== NOTA ALTERADA COM SUCESSO ===>");
                opcao = 0;
                break;
        
            case 2:
                break;

            case 0:
                printf(" <==== NOTA NAO ALTERADA ====>");
                break; 

            default:
                printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                printf(" !! OPCAO INVALIDA !!");
                break;
            }

            Sleep(2000);

        } while (opcao != 0 && opcao != 1 && opcao != 2);

        system("cls");
    } while(opcao != 0);

}

void editarNota2(double *nota2){
    int opcao;
    
    printf("\n <========== EDITAR NOTA 2 ==========>\n");
    do{
        system("cls");
        double aux;
        printf(" * Nota Antiga: %.2lf\n", *nota2);
        printf(" * Nota Nova: ");
        scanf(" %lf", &aux);

        do{
            system("cls");

            printf("\n <========= Confirmacao =========>\n\n");
            printf(" => Voce realmente deseja modificar '%.2f' para '%.2f'\n", *nota2, aux);
            printf(" [1] < Confirmar >\n");
            printf(" [2] < Alterar >\n");
            printf(" [0] < Cancelar >\n");
            printf("\n * Escolha Uma Opcao: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao) {
            case 1:
                *nota2 = aux;
                printf(" <=== NOTA ALTERADA COM SUCESSO ===>");
                opcao = 0;
                break;
        
            case 2:
                break;

            case 0:
                printf(" <==== NOTA NAO ALTERADA ====>");
                break; 

            default:
                printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                printf(" !! OPCAO INVALIDA !!");
                break;
            }

            Sleep(2000);

        } while (opcao != 0 && opcao != 1 && opcao != 2);

        system("cls");
    } while(opcao != 0);

}

void editarAluno(Alunos *aluno, int i){
    int opcao = 9, indice;
    do{
        system("cls");

        int repetir = 1;
        do{
            indice = buscarAluno(aluno, i);
            if(indice != -1){
                repetir = 0;
            } else {
                do {
                    printf("\n\n <=== OPCOES ===>\n");
                    printf("[0] < Voltar >\n");
                    printf("[1] < Outro Aluno >\n");
                    printf(" * Escolha Uma Opcao: ");
                    scanf("%d", &repetir);

                    if(repetir == 0) {
                        repetir = 2;
                        break;
                    }
                } while (repetir != 1);
            }
        } while(repetir == 1);

        system("cls");

        if(repetir == 2) {
            opcao = 0;
            continue;
        }

        do {
            system("cls");

            printf(" => Aluno '%s' Escolhido Com Sucesso!!", aluno[indice].nome);
            printf("\n <========== O QUE DESEJA ALTERAR? ==========>\n");
            printf(" [1] < NOME >\n");
            printf(" [2] < IDADE >\n");
            printf(" [3] < MATRICULA >\n");
            printf(" [4] < NOTA 1 >\n");
            printf(" [5] < NOTA 2 >\n");
            printf(" [0] < Sair >\n");
            printf(" [8] < Exibir Informacoes Desse Aluno >\n");
            printf(" [9] < Editar Outro Aluno >\n");
            printf("\n * Escolha Uma Opcao: ");
            scanf("%d", &opcao);

            if(opcao != 0) {
                switch(opcao) {
                case 1:
                    editarNome(aluno[indice].nome);                    
                    break;
                
                case 2:
                    editarIdade(&aluno[indice].idade);
                    break;

                case 3:
                    editarMatricula(&aluno[indice].matricula);
                    break;
                    
                case 4: 
                    editarNota1(&aluno[indice].nota1);                    
                    break;

                case 5: 
                    editarNota2(&aluno[indice].nota2);                    
                    break;

                case 8: 
                    exibirAluno(aluno,indice);  
                    int aux;
                    printf(" [0] < Voltar >\n");
                    printf(" * Escolha Uma Opcao: ");
                    scanf("%i", &aux);                
                    break;

                case 0:
                    break;

                default:
                    printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                    printf(" !! OPCAO INVALIDA !! :->");
                    Sleep(2000);
                    break;
                }
            } else {
                printf("\n\n<=================== E R R O ! ! ===================>\n\n");
                printf(" !! OPCAO INVALIDA :-<!!");
                Sleep(2000);
            }
        } while (opcao != 0 && opcao != 9);
    } while(opcao != 0);
}

int  mediaAluno(Alunos *aluno, int indice){
    int media = (aluno[indice].nota1 + aluno[indice].nota2) / 2;

    return media;
}

//Até agora tudo certo, Continue as funções e ajeite a repetição quando erra a matricula lá no editar aluno;