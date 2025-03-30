/**
 * @file dados.h
 * @author Joe Oliveira
 * @brief Estruturas de dados para as antenas e localizações afetadas.
 * @version 0.1
 * @date 2025-03-24
 * 
 * @copyright Copyright (c) 2025
 */

/**
 * @brief Estrutura das antenas (Lista Ligada)
 * 
 * @n x = linhas; y = colunas
 */
typedef struct Antena 
{
    char frequencia;
    int x, y;
    struct Antena* prox;
} Antena;

/**
 * @brief Estrutura para efeito nefasto
 * 
 */
typedef struct Localizacao 
{
    int x, y;
    struct Localizacao* prox;
} Localizacao;
