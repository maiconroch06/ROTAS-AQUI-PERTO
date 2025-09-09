# ROTAS-AQUI-PERTO

![Linguagem](https://img.shields.io/badge/language-C-blue.svg)
![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)

Este atual repositório visa desenvolver um programa para determinar as rotas mais eficientes para cada par de municípios, com o propósito de minimizar o tempo de viagem. 

## 🎯 Este repositório foi criado com o objetivo de

- Contribuir com meu portifolio;
- Concluir a segunda e última avaliação da disciplina de Programação de Computadores;
- Desenvolver um programa em C de calcular a menor rota entre cidades;
- Separar este repositório do repositório principal "[`IFRN-TADS-Meterial-C`]()". 
- Compartilhar este repositório com colegas da equipe para facilitar no desenvolvimento do codigo.

## 📁 Estrutura do Repositório

  `main.c/`: Arquivo principal.

  `prototipos.h/`: Arquivo onde contém todas as funções, como:
   - Cadastramento manual e carregamento de arquivo `.txt` das cidades;
   - Executar o algoritimo e amazenar os resultados;
   - Exibição de todas as matrizes obtidas no codigo;
   - Calcular menor rota de uma cidade de origem para cidade de destino;
   - Salvar os arquivos iniciais e/ou de resultados em formato `.txt`.

##  Compile e Execute

  - Comando de compilação (WINDOWS):
    `gcc main.c algoritimo\floyd-warshall.c cadastro\cadastro-manual.c cadastro\carregar-cidades.c cadastro\primeiro-acesso.c dados\util.c exibicao\exibir-matrizes.c exibicao\menu-cadastro-cidades.c exibicao\menu-exibir-matrizes.c exibicao\menu-principal.c exibicao\menu-salvar.c menor-caminho\calcular-rota.c menor-caminho\reconstruir-caminho.c salvamento\salvar-dados-iniciais.c salvamento\salvar-resultados.c -o main`

    C:\Users\maicon\Documents\MyProjects\ROTAS-AQUI-PERTO\banco-de-dados\cidades.txt

  - Comando de execução (WINDOWS):
    `.\main`

## 🤝 Contribuição

Contribuições são bem-vindas! Se quiser sugerir melhorias, correções ou adicionar novos conteúdos, sinta-se livre para abrir um Pull Request.

## Pendencias de Melhoria



## 👨‍💻 Autores

Este repositório foi criado por [Lucas Gabriel](https://github.com/Lucasgfln), [Maicon Rocha](https://github.com/maiconroch06) e [Luana Souza](https://github.com/Luana-Souza2) como parte da segunda e ultima avaliação da disciplina de **Programação de Computadores** do curso de **Análise e Desenvolvimento de Sistemas** **(TADS)** no **IFRN - Campus Nova Cruz**.
