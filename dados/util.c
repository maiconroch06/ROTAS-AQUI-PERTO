#include <stdio.h>
#include <stdlib.h>
#include "../prototipos.h"

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
#ifdef _WIN32
    system("pause");
#else
    printf("Pressione ENTER para continuar...");
    getchar();
#endif
}