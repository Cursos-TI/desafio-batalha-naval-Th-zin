#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho das matrizes de habilidade
#define TAMANHO_HABILIDADE 5

// Função para exibir o tabuleiro (agora retorna int)
int exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval com Habilidades:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe o valor da posição (0, 3 ou 5)
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
    return 0; // Retorno simbólico
}

// Função para criar a matriz de habilidade Cone (agora retorna int)
int criarCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= i && j < TAMANHO_HABILIDADE - i) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
    return 0; // Retorno simbólico
}

// Função para criar a matriz de habilidade Cruz (agora retorna int)
int criarCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
    return 0; // Retorno simbólico
}

// Função para criar a matriz de habilidade Octaedro (agora retorna int)
int criarOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
    return 0; // Retorno simbólico
}

// Função para aplicar a habilidade ao tabuleiro (agora retorna int)
int aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz de habilidade
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = linhaOrigem - centro + i;
            int colunaTabuleiro = colunaOrigem - centro + j;
            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca a área afetada
                }
            }
        }
    }
    return 0; // Retorno simbólico
}

int main() {
    // Inicializa o tabuleiro com 0s (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona os navios
    tabuleiro[2][3] = 3; // Navio 1
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    tabuleiro[5][7] = 3; // Navio 2
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    tabuleiro[1][1] = 3; // Navio 3
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;

    tabuleiro[3][8] = 3; // Navio 4
    tabuleiro[4][7] = 3;
    tabuleiro[5][6] = 3;

    // Cria as matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);    // Cone com origem em (4, 4)
    aplicarHabilidade(tabuleiro, cruz, 7, 2);    // Cruz com origem em (7, 2)
    aplicarHabilidade(tabuleiro, octaedro, 1, 8); // Octaedro com origem em (1, 8)

    // Exibe o tabuleiro com os navios e as áreas de efeito das habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
