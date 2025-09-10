#include <stdio.h>
#include <stdlib.h>
#include "../prototipos.h"

/**
 * @brief Limpa o console.
 *
 * Limpa o console, funcionando tanto em sistemas Windows quanto em sistemas baseados em Unix.
 */
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * @brief Pausa a execução do programa até que o usuário pressione Enter.
 *
 * Pausa a execução, funcionando tanto em sistemas Windows quanto em sistemas baseados em Unix.
 */
void pausar() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer();
    getchar();
}

/**
 * @brief Limpa o buffer de entrada.
 *
 * Limpa o buffer de entrada para evitar problemas com leituras de caracteres.
 */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}