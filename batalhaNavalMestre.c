#include <stdio.h>
#include <stdlib.h>  

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

#define TAM_HAB 5  // tamanho das matrizes de habilidade

// ==========================
// FUNÇÃO: Cria matriz Cone
// ==========================
void criarCone(int m[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // centro do cone é a coluna do meio
            int meio = TAM_HAB / 2;

            // Forma de cone: quanto mais para baixo, mais largo
            if (j >= meio - i && j <= meio + i) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

// ==========================
// FUNÇÃO: Cria matriz Cruz
// ==========================
void criarCruz(int m[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == meio || j == meio) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

// ==============================
// FUNÇÃO: Cria matriz Octaedro
// ==============================
void criarOctaedro(int m[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // distância de Manhattan ≤ raio
            if (abs(i - meio) + abs(j - meio) <= meio) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

// ==================================================
// FUNÇÃO: Sobrepõe matriz de habilidade no tabuleiro
// ==================================================
void aplicarHabilidade(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int hab[TAM_HAB][TAM_HAB],
                       int origemLinha,
                       int origemColuna) 
{
    int inicio = TAM_HAB / 2;  // deslocamento da matriz

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (hab[i][j] == 1) {  // só marca onde há efeito

                int linhaTab = origemLinha + (i - inicio);
                int colTab   = origemColuna + (j - inicio);

                // valida limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colTab >= 0 && colTab < TAMANHO_TABULEIRO) 
                {
                    // Não altera navios, apenas água
                    if (tab[linhaTab][colTab] == 0)
                        tab[linhaTab][colTab] = VALOR_HABILIDADE;
                }
            }
        }
    }
}

int main() {
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // ================================
    // 1. Inicializa tabuleiro com água
    // ================================
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==========================
    // 2. Posiciona navios (igual ao código fornecido)
    // ==========================

    int linhaH = 1, colunaH = 2;
    int linhaV = 5, colunaV = 4;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 2, colunaD2 = 7;

    // navio horizontal
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linhaH][colunaH + i] != 0) pode = 0;

        if (pode)
            for (int i = 0; i < TAMANHO_NAVIO; i++)
                tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
    }

    // navio vertical
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linhaV + i][colunaV] != 0) pode = 0;

        if (pode)
            for (int i = 0; i < TAMANHO_NAVIO; i++)
                tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
    }

    // diagonal principal
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)
    {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) pode = 0;

        if (pode)
            for (int i = 0; i < TAMANHO_NAVIO; i++)
                tabuleiro[linhaD1 + i][colunaD1 + i] = VALOR_NAVIO;
    }

    // diagonal secundária
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaD2 - TAMANHO_NAVIO + 1 >= 0)
    {
        int pode = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) pode = 0;

        if (pode)
            for (int i = 0; i < TAMANHO_NAVIO; i++)
                tabuleiro[linhaD2 + i][colunaD2 - i] = VALOR_NAVIO;
    }

    // ============================================
    // 3. Criação das matrizes de habilidades
    // ============================================

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int oct[TAM_HAB][TAM_HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    // ============================================
    // 4. Posições das habilidades no tabuleiro
    // ============================================

    int origemConeLinha = 4, origemConeCol = 4;
    int origemCruzLinha = 7, origemCruzCol = 2;
    int origemOctLinha  = 5, origemOctCol = 8;

    // ============================================
    // 5. Aplica habilidades ao tabuleiro
    // ============================================
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeCol);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzCol);
    aplicarHabilidade(tabuleiro, oct, origemOctLinha, origemOctCol);

    // ============================================
    // 6. Impressão do tabuleiro final
    // ============================================
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %c", colunas[i]);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
