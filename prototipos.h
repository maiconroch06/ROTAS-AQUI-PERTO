#ifndef _PROTOTIPOS_H
#define _PROTOTIPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITO 1000.0

// ===================== Tipos =====================
/**
 * @struct DadosCidades
 * @brief Estrutura para armazenar os dados das cidades e as matrizes de distância.
 * @var DadosCidades::num_cidades O número de cidades.
 * @var DadosCidades::nomes_cidades Os nomes das cidades.
 * @var DadosCidades::matriz_adjacentes A matriz de adjacências.
 * @var DadosCidades::matriz_distancias A matriz de distâncias.
 * @var DadosCidades::matriz_predecessores A matriz de predecessores.
 */
typedef struct {
    int num_cidades;
    char **nomes_cidades;
    double **matriz_adjacentes;
    double **matriz_distancias;
    int **matriz_predecessores;
} DadosCidades;

// ============== Assinaturas =============

// ============== memoria.c =============
/**
 * @brief Aloca memória para as matrizes e nomes de cidades.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void alocar_memoria(DadosCidades *cidades);

/**
 * @brief Libera a memória alocada para as matrizes e nomes de cidades.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void liberar_memoria(DadosCidades *cidades);


// ============== util.c =============
/**
 * @brief Limpa o console.
 */
void limparTela();

/**
 * @brief Pausa a execução do programa.
 */
void pausar();

/**
 * @brief Limpa o buffer de entrada.
 */
void limparBuffer();


// ============== menu.c =============
/**
 * @brief Exibe o menu principal e retorna a opção escolhida pelo usuário.
 * @return A opção do menu escolhida.
 */
int MenuPrincipal();

/**
 * @brief Realiza o primeiro acesso ao sistema, cadastrando as cidades.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void PrimeiroAcesso(DadosCidades *cidades);

/**
 * @brief Gerencia o cadastro de cidades, permitindo escolher entre manual e arquivo.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 * @return 1 se o cadastro foi bem-sucedido, 0 caso contrário.
 */
int  CadastroCidades(DadosCidades *cidades);

/**
 * @brief Realiza o cadastro manual das cidades e distâncias.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 * @return 1 se o cadastro foi bem-sucedido, 0 caso contrário.
 */
int  CadastroManual(DadosCidades *cidades);

/**
 * @brief Carrega os dados das cidades de um arquivo de texto.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 * @return 1 se o carregamento foi bem-sucedido, 0 caso contrário.
 */
int  CarregarArquivo(DadosCidades *cidades);


// ============== exibicao.c =============
/**
 * @brief Exibe as matrizes de adjacência, distâncias ou predecessores.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void ExibirMatrizes(DadosCidades *cidades);

/**
 * @brief Exibe a matriz de adjacências.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void ExibirMatrizA(DadosCidades *cidades);

/**
 * @brief Exibe a matriz de distâncias.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void ExibirMatrizD(DadosCidades *cidades);

/**
 * @brief Exibe a matriz de predecessores.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void ExibirMatrizP(DadosCidades *cidades);


// ============== salvamento.c =============
/**
 * @brief Salva os dados em arquivos de texto.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void Salvar(DadosCidades *cidades);

/**
 * @brief Salva os dados iniciais (cidades e matriz de adjacências) em um arquivo.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void SalvarDadosIniciais(DadosCidades *cidades);

/**
 * @brief Salva os resultados (matrizes de distâncias e predecessores) em um arquivo.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void SalvarResultados(DadosCidades *cidades);


// ============== algoritimo.c =============
/**
 * @brief Executa o algoritmo de Floyd-Warshall para encontrar os menores caminhos.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void floydWarshall(DadosCidades *cidades);


// ============== menor-caminho.c =============
/**
 * @brief Calcula e exibe a menor rota entre duas cidades.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 */
void CalcularRota( DadosCidades *cidades);

/**
 * @brief Reconstrói o caminho mais curto entre duas cidades.
 * @param cidades Ponteiro para a estrutura de dados das cidades.
 * @param indice_origem Índice da cidade de origem.
 * @param indice_destino Índice da cidade de destino.
 * @param caminho_saida Array para armazenar o caminho reconstruído.
 * @return O número de cidades no caminho.
 */
int  ReconstruirCaminho( DadosCidades *cidades, int indice_origem, int indice_destino, int caminho_saida[]);

// ============== teste_util.c =============
void print_matrix_d(DadosCidades *cidades);
void print_matrix_p(DadosCidades *cidades);

#endif
