#include <stdio.h>

int main() {
    // Letras das colunas (A até J)
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // 1. Criando o tabuleiro (matriz 10x10) e inicializando com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definindo os navios como vetores com valor 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // 3. Coordenadas iniciais dos navios
    int linhaH = 1;    // linha 2
    int colunaH = 2;   // coluna C
    int linhaV = 4;    // linha 5
    int colunaV = 5;   // coluna F

    // 4. Posicionando o navio horizontal (validação de limite)
    if (colunaH + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
        }
    }

    // 5. Posicionando o navio vertical (validação de limite e sobreposição)
    if (linhaV + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            // Só posiciona se não tiver outro navio no local
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
            }
        }
    }

    // 6. Imprimindo o cabeçalho do tabuleiro (letras A–J)
    printf("TABELA BATALHA NAVAL\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
    }
    printf("\n");

    // 7. Imprimindo o conteúdo do tabuleiro com números de linha
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1);  // Exibe número da linha (1 a 10)
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);  // Exibe valor (0 ou 3)
        }
        printf("\n");
    }

    return 0;
}