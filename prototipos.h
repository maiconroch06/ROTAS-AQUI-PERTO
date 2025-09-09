#ifndef _PROTOTIPOS_H
#define _PROTOTIPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===================== Tipos =====================
typedef struct {
    int num_cidades;
    char nomes_cidades[100][255];
    double matriz_adjacentes[100][100];
    double matriz_distancias[100][100];
    int matriz_predecessores[100][100];
} DadosCidades;

// ============== Assinaturas =============
void limparTela();
void pausar();

int MenuPrincipal();
void PrimeiroAcesso(DadosCidades *cidades);

int  CadastroCidades(DadosCidades *cidades);
int  CadastroManual(DadosCidades *cidades);
int  CarregarArquivo(DadosCidades *cidades);

void ExibirMatrizes(DadosCidades *cidades);
void ExibirMatrizA(DadosCidades *cidades); 
void ExibirMatrizD(DadosCidades *cidades); 
void ExibirMatrizP(DadosCidades *cidades); 

void Salvar(DadosCidades *cidades);
void SalvarDadosIniciais(DadosCidades *cidades);
void SalvarResultados(DadosCidades *cidades); 

void floydWarshall(DadosCidades *cidades);

void CalcularRota( DadosCidades *cidades);
int  ReconstruirCaminho( DadosCidades *cidades, int indice_origem, int indice_destino, int caminho_saida[]);

#endif
