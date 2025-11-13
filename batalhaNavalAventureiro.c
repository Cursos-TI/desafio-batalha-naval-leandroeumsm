#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3

int main() {
    // Letras das colunas para impressão
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // 1. Inicializa o tabuleiro 10x10 com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Coordenadas iniciais dos navios (linha, coluna)
    int linhaH = 1, colunaH = 2; // navio horizontal ↔
    int linhaV = 5, colunaV = 4; // navio vertical ↓
    int linhaD1 = 0, colunaD1 = 0; // navio diagonal principal ↘
    int linhaD2 = 2, colunaD2 = 7; // navio diagonal secundária ↙

    // 3. Posiciona navio horizontal
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                pode = 0;
                break;
            }
        }
        if (pode) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
            }
        }
    }

    // 4. Posiciona navio vertical
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                pode = 0;
                break;
            }
        }
        if (pode) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
            }
        }
    }

    // 5. Posiciona navio diagonal principal (↘)
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                pode = 0;
                break;
            }
        }
        if (pode) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = VALOR_NAVIO;
            }
        }
    }

    // 6. Posiciona navio diagonal secundária (↙)
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - TAMANHO_NAVIO + 1 >= 0) {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                pode = 0;
                break;
            }
        }
        if (pode) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = VALOR_NAVIO;
            }
        }
    }

    // 7. Imprime cabeçalho das colunas
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %c", colunas[i]);
    }
    printf("\n");

    // 8. Imprime o tabuleiro com números de linha
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // numeração de 1 a 10
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}