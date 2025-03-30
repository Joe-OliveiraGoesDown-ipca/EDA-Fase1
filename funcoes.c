/**
 * @file funcoes.c
 * @author Joe Oliveira
 * @brief Implementação das funções para manipulação de antenas e efeitos nefastos
 * @version 0.1
 * @date 2025-03-21
 * 
 * @copyright Copyright (c) 2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "funcoes.h"
 
 #pragma region criarAntena
 /**
  * @brief Função para criar uma nova antena
  * 
  * @param freq Frequência da antena
  * @param lin Linha da antena
  * @param col Coluna da antena
  * @return Nova antena alocada na memória
  */
 Antena* criarAntena(char freq, int lin, int col) {
     Antena* nova = (Antena*)malloc(sizeof(Antena));
     if (!nova) {
         printf("Erro ao alocar memória para antena.\n");
         exit(1);
     }
     nova->frequencia = freq;
     nova->x = lin;
     nova->y = col;
     nova->prox = NULL;
     return nova;
 }
 #pragma endregion

 #pragma region InserirAntena
 /**
  * @brief Função para inserir uma antena na lista ligada
  * 
  * @param lista Lista de antenas
  * @param freq Frequência da antena
  * @param lin Linha da antena
  * @param col Coluna da antena
  * @return Lista de antenas atualizada com a nova antena
  */
 Antena* inserirAntena(Antena* lista, char freq, int lin, int col)
  {
     Antena* nova = criarAntena(freq, lin, col);
     if (!lista) return nova;
     
     Antena* temp = lista;
     while (temp->prox) {
         temp = temp->prox;
     }
     temp->prox = nova;
     return lista;
 }
 #pragma endregion

 #pragma region ImprimiroAntenas
 /**
  * @brief Função para imprimir a lista de antenas em formato tabular
  * 
  * @param lista Lista de antenas
  */
 void imprimirAntenas(Antena* lista) 
 {
    char matriz[10][10];

    // Preenchendo a matriz com '.'
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 10; j++)
            matriz[i][j] = '.';

    // Adicionando as antenas na matriz
    while (lista) {
        matriz[lista->x][lista->y] = lista->frequencia;
        lista = lista->prox;
    }

    // Imprimindo a matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}
     #pragma endregion
 
 #pragma region imprimirEfeitoNefasto
 /**
  * @brief Função para imprimir as localizações afetadas em formato tabular
  * 
  * @param lista Lista de localizações afetadas
  */
 void imprimirLocalizacoes(Antena* lista, Localizacao* efeitos) 
 {
    char matriz[10][10];

    // Preenchendo a matriz com '.'
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            matriz[i][j] = '.';

    // Adicionando antenas na matriz
    Antena* temp = lista;
    while (temp) {
        matriz[temp->x][temp->y] = temp->frequencia;
        temp = temp->prox;
    }

    // Adicionando locais de efeito nefasto (com '#')
    while (efeitos) {
        if (matriz[efeitos->x][efeitos->y] == '.') { 
            matriz[efeitos->x][efeitos->y] = '#';  // Marca com '#' se não tiver antena no local
        }
        efeitos = efeitos->prox;
    }

    // Imprimindo a matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

 #pragma endregion
 
 #pragma region CalculoEfeitoNefasto
 /**
  * @brief Função para calcular locais com efeito nefasto
  * 
  * @param lista Lista de antenas
  * @return Lista de localizações com efeito nefasto
  */
 Localizacao* calcularEfeitoNefasto(Antena* lista)
  {
    
     Localizacao* efeitoLista = NULL;
     Antena* a1 = lista;
 
     while (a1) {
         Antena* a2 = lista;
         while (a2) {
             if (a1 != a2 && a1->frequencia == a2->frequencia) {
                 int dx = a2->x - a1->x;
                 int dy = a2->y - a1->y;
                 if (dx % 2 == 0 && dy % 2 == 0) {
                     Localizacao* nova = (Localizacao*)malloc(sizeof(Localizacao));
                     if (!nova) {
                         printf("Erro ao alocar memória para local de efeito nefasto.\n");
                         exit(1);
                     }
                     nova->x = a1->x + dx / 2;
                     nova->y = a1->y + dy / 2;
                     nova->prox = efeitoLista;
                     efeitoLista = nova;
                 }
             }
             a2 = a2->prox;
         }
         a1 = a1->prox;
     }
     return efeitoLista;
  }
  #pragma endregion
 
  #pragma region EliminarAntena
 /**
  * @brief Função para eliminar uma antena da lista
  * 
  * @param lista Lista de antenas
  * @param freq Frequência da antena a ser removida
  * @param lin Linha da antena a ser removida
  * @param col Coluna da antena a ser removida
  * @return Lista de antenas atualizada
  */
 Antena* eliminarAntena(Antena* lista, char freq, int lin, int col) 
 {
    
     if (!lista) return NULL;
     
     Antena* temp = lista;
     Antena* prev = NULL;
 
     while (temp) {
         if (temp->frequencia == freq && temp->x == lin && temp->y == col) {
             if (prev) {
                 prev->prox = temp->prox;
             } else {
                 lista = temp->prox;
             }
             free(temp);
             return lista;
         }
         prev = temp;
         temp = temp->prox;
     }
 
     printf("Antena não encontrada.\n");
     return lista;
 }
 #pragma endregion
 
 #pragma region CarregarDeFicheiro
 /**
  * @brief Função para carregar antenas de um ficheiro
  * 
  * @param nomeFicheiro Nome do ficheiro
  * @return Lista de antenas carregadas
  */
 Antena* carregarDeFicheiro(const char* nomeFicheiro)
  {
    
     FILE* file = fopen(nomeFicheiro, "r");
     if (!file) {
         printf("Erro ao abrir o ficheiro %s\n", nomeFicheiro);
         return NULL;
     }
 
     Antena* lista = NULL;
     char linha[100];
     int i = 0;
 
     while (fgets(linha, sizeof(linha), file)) {
         for (int j = 0; linha[j] != '\0'; j++) {
             if (linha[j] != '.' && linha[j] != '0' && linha[j] != '\n') {
                 lista = inserirAntena(lista, linha[j], i, j);
             }
         }
         i++;
     }
 
     fclose(file);
     printf("Antenas carregadas do ficheiro %s com sucesso!\n", nomeFicheiro);
     return lista;
 }
 #pragma endregion
 