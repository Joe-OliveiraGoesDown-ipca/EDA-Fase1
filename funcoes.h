/**
 * @file funcoes.h
 * @author Joe Oliveira
 * @brief 
 * @version 0.1
 * @date 2025-03-24
 * 
 * @copyright Copyright (c) 2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "dados.h"
 
/**
 * @brief Função para criar uma nova antena.
 * 
 * @param freq Frequência da antena
 * @param lin Linha da antena
 * @param col Coluna da antena
 * @return Nova antena criada
 */
Antena* criarAntena(char freq, int lin, int col);

/**
 * @brief Função para inserir uma antena na lista de antenas.
 * 
 * @param lista Lista de antenas
 * @param freq Frequência da antena
 * @param lin Linha da antena
 * @param col Coluna da antena
 * @return Lista de antenas atualizada
 */
Antena* inserirAntena(Antena* lista, char freq, int lin, int col);

/**
 * @brief Função para imprimir a lista de antenas.
 * 
 * @param lista Lista de antenas
 */
void imprimirAntenas(Antena* lista);

/**
 * @brief Função para calcular locais com efeito nefasto.
 * 
 * @param lista Lista de antenas
 * @return Lista de localizações com efeito nefasto
 */
Localizacao* calcularEfeitoNefasto(Antena* lista);

/**
 * @brief Função para imprimir as localizações afetadas por efeito nefasto.
 * 
 * @param lista Lista de localizações afetadas
 */
void imprimirLocalizacoes(Antena* lista, Localizacao* efeitos);

/**
 * @brief Função para carregar antenas de um ficheiro.
 * 
 * @param nomeFicheiro Nome do ficheiro (matrix.txt, na main.c)
 * @return Lista de antenas carregadas
 */
Antena* carregarDeFicheiro(const char* nomeFicheiro);

/**
 * @brief Função para eliminar uma antena da lista.
 * 
 * @param lista Lista de antenas
 * @param freq Frequência da antena a ser removida
 * @param lin Linha da antena a ser removida
 * @param col Coluna da antena a ser removida
 * @return Lista de antenas atualizada
 */
Antena* eliminarAntena(Antena* lista, char freq, int lin, int col);

 