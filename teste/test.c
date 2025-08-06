#include <stdio.h>
#include <string.h>
//#include <windows.h>

#define MAX_MSGS 100
#define TAM_MSG 100

struct Rotas {
    char mensagens[MAX_MSGS][TAM_MSG];
    int total;
};

void gravarotas(Rotas );
void exibirotas(int *total, char mensagens[][TAM_MSG]);
void carregarotas(int *total, char mensagens[][TAM_MSG]);

typedef struct Rotas rotas;

int main(void) {
    char op;

    do {
        printf("\n ======== MENSAGEM ========");
        printf("\n > [1] Gravar mensagem");
        printf("\n > [2] Ver mensagens");
        printf("\n > [3] Carregar mensagens");
        printf("\n > [0] Sair");
        printf("\n ==========================\n");
        printf(" Opcao: ");
        scanf(" %i", &op);
        getchar(); // limpa o '\n'

        system("cls");

        switch (op) {
            case 1:
                gravarotas(&rotas, &total);
                break;

            case 2:
                exibirotas(&total, &rotas);
                break;
            
            case 3:
                carregarotas(&total, &rota);
                break;

            case 0:
                printf("\n\n   Saindo....\n");
                Sleep(1000);
                return 0;

            default:
                printf("\n\n Opcao invalida...\n");
                Sleep(2000);
                break;
        }

        system("cls");
    } while (op != '0');

    return 0;
}

/*
void gravarotas(char mensagens[][TAM_MSG], int *total) {
    int continuar;

    do {
        if (*total >= MAX_MSGS) {
            printf("Limite de mensagens atingido.\n");
            break;
        }

        printf(" -> Insira a sua mensagem: ");
        fgets(mensagens[*total], TAM_MSG, stdin);
        mensagens[*total][strcspn(mensagens[*total], "\n")] = '\0'; // remove '\n'
        (*total)++;

        system("cls");

        printf("\n ====== NOVA MENSAGEM? ======");
        printf("\n > [1] Sim");
        printf("\n > [2] Nao");
        printf("\n ============================\n");
        printf(" Opcao: ");
        scanf("%d", &continuar);
        getchar(); // limpa o '\n'

        system("cls");

    } while (continuar == 1);
}
void exibirotas(int *total, char mensagens[][TAM_MSG]) {
    if (*total == 0) {
        printf("\n Nenhuma mensagem gravada ainda.\n");
    } else {
        printf("\n ======== MENSAGENS GRAVADAS ========\n");
        for (int i = 0; i < *total; i++) {
            printf(" > [%d] %s\n", i + 1, mensagens[i]);
        }
        printf(" ====================================\n");
    }
    system("pause");
}

void carregarotas(int *total, char mensagens[][TAM_MSG]){

    return 0;
}
*/