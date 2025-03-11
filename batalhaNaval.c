#include <stdio.h>

// definição de constantes 
#define TAMANHO 10  
#define NAVIO 3      
#define AGUA 0
#define HABILIDADE 1

// Inicia o tabuleiro com água 
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona navios no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + i] = NAVIO; // Posiciona na horizontal
        } else if (orientacao == 1) {
            tabuleiro[linha + i][coluna] = NAVIO; // Posiciona na vertical
        } else if (orientacao == 2) {
            tabuleiro[linha + i][coluna + i] = NAVIO; // Posiciona na diagonal
        }
    }
}

// habilidade de cruz
void Cruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        if (linha + i >= 0 && linha + i < TAMANHO) {
            tabuleiro[linha + i][coluna] = HABILIDADE;
        }
        if (coluna + i >= 0 && coluna + i < TAMANHO) {
            tabuleiro[linha][coluna + i] = HABILIDADE;
        }
    }
}

// habilidade de cone
void Cone(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + 2 < TAMANHO) {
        tabuleiro[linha + 2][coluna] = HABILIDADE;
    }
    if (linha + 1 < TAMANHO) {
        if (coluna - 1 >= 0) tabuleiro[linha + 1][coluna - 1] = HABILIDADE;
        tabuleiro[linha + 1][coluna] = HABILIDADE;
        if (coluna + 1 < TAMANHO) tabuleiro[linha + 1][coluna + 1] = HABILIDADE;
    }
    tabuleiro[linha][coluna] = HABILIDADE;
}

// habilidade de octaedro
void Octaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = HABILIDADE;
    if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = HABILIDADE;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = HABILIDADE;
    if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = HABILIDADE;
    tabuleiro[linha][coluna] = HABILIDADE;
}


// exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; 
    inicializarTabuleiro(tabuleiro); 
    
    // coordenadas navios
    int linha1 = 2, coluna1 = 2; 
    int linha2 = 5, coluna2 = 7; 
    int linha3 = 0, coluna3 = 6; 
    int linha4 = 7, coluna4 = 1; 

    // Habilidades
    Cruz(tabuleiro, 5, 8);
    Cone(tabuleiro, 6, 2);
    Octaedro(tabuleiro, 9, 6);

    // Verificação de limites e posicionamento dos navios
    if (coluna1 + NAVIO <= TAMANHO) {
        posicionarNavio(tabuleiro, linha1, coluna1, 0); // navio horizontal
    }
    
    if (linha2 + NAVIO <= TAMANHO) {
        posicionarNavio(tabuleiro, linha2, coluna2, 1); //vertical
    }
    
    if (linha3 + NAVIO <= TAMANHO && coluna3 + NAVIO <= TAMANHO) { //diagonal
        posicionarNavio(tabuleiro, linha3, coluna3, 2); 
    }

    if (linha4 + NAVIO <= TAMANHO && coluna4 + NAVIO <= TAMANHO) {
        posicionarNavio(tabuleiro, linha4, coluna4, 2); 
    }

    // Exibe o tabuleiro atualizado no console
    exibirTabuleiro(tabuleiro);
    
return 0;
}


    