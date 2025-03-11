#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
  //  N = NAVIO, 0 = MAR
    char *tabuleiro[10][10] = {
            {"N", "N", "N", "0", "0", "0", "0", "0", "N", "0"},
            {"0", "0", "0", "0", "0", "0", "0", "N", "0", "0"},
            {"0", "0", "0", "0", "0", "0", "N", "0", "0", "0"},
            {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
            {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
            {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
            {"0", "0", "0", "0", "0", "0", "0", "N", "0", "0"},
            {"0", "0", "N", "0", "0", "0", "0", "N", "0", "0"},
            {"0", "N", "0", "0", "0", "0", "0", "N", "0", "0"},
            {"N", "0", "0", "0", "0", "0", "0", "0", "0", "0"}
    };
    
        // Exibir o tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
             printf("%s ", tabuleiro[i][j]);
        }
        printf("\n");
        }
        
        return 0;
    }    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0