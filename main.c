/**
 * @file main.c
 * @author Joe Oliveira
 * @brief Implementação do menu principal para manipulação de antenas
 * @version 0.1
 * @date 2025-03-24
 * 
 * @copyright Copyright (c) 2025
 */

 #include <stdio.h>   
 #include <stdlib.h>  // Para NULL e malloc
 #include "funcoes.h" 
 
 /**
  * @brief Função main com um menu 
  * O menu permite inserir antenas, listar antenas, calcular efeitos nefastos,
  * listar localizações afetadas , carregar antenas de um ficheiro e apagar antena.
  * 
  * @return int Retorna 0 para sair do programa.
  */
 int main() {
     Antena* lista = NULL;
     Localizacao* efeitos = NULL;
     int op, x, y;
     char freq;
               
 
     do {
         #pragma region Menu
         printf("\n======= MENU PRINCIPAL =======\n");
         printf("1 - Inserir Antena\n");
         printf("2 - Listar Antenas\n");
         printf("3 - Calcular Efeito Nefasto\n");
         printf("4 - Listar Localizações com Efeito Nefasto\n");
         printf("5 - Carregar Antenas de um Ficheiro\n");
         printf("6 - Eliminar Antena\n");
         printf("0 - Sair\n");
         printf("Escolha uma opção: ");
        
         scanf("%d", &op);

         #pragma endregion

         switch (op) 
         {

             #pragma region Inserir Antena
             case 1: 
                 printf("Digite a frequência (A, O, etc.): ");
                 scanf(" %c", &freq);
                 printf("Digite a linha e a coluna: ");
                 scanf("%d %d", &x, &y);
                 lista = inserirAntena(lista, freq, x, y);
                 break;
             
             #pragma endregion
 
             #pragma region Listar Antenas
             case 2:
             imprimirAntenas(lista);
                 break;
             #pragma endregion
 
             #pragma region Calcular Efeito Nefasto
             case 3:
                 efeitos = calcularEfeitoNefasto(lista);
                 break;
             #pragma endregion
 
             #pragma region Imprimir Localizações com Efeito Nefasto
             case 4:
             imprimirLocalizacoes(lista,efeitos);  
             break;
             #pragma endregion
 
             #pragma region Carregar Antenas de um Ficheiro
             case 5:
                 lista = carregarDeFicheiro("matriz.txt");
                 break;
             #pragma endregion

             #pragma region EliminarAntena
             case 6: 
               
                printf("Digite a frequência da antena a ser removida: ");
                scanf(" %c", &freq);
                printf("Digite a linha e a coluna da antena a ser removida: ");
                scanf("%d %d", &x, &y);
                lista = eliminarAntena(lista, freq, x, y);  // Função para eliminar antena
                break;
            #pragma endregion

             default:
                 printf("Opção inválida! Tente novamente.\n");
        
         }
     } while (op != 0);
 
     return 0;
 }
 