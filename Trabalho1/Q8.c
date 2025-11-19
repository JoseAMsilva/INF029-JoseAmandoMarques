#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 3
#define COLUNAS 3
#define true 1
#define false 0

char tabuleiro[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void separarJogada(char jogada[], int *linha, int *coluna)
{
    if (strlen(jogada) != 2)
    {
        *linha = -1;
        *coluna = -1;
        return;
    }

    if (jogada[0] >= 'a' && jogada[0] <= 'c')
    {
        jogada[0] = jogada[0] - 'a' + 'A';
    }

    if ((jogada[0] >= 'A' && jogada[0] <= 'C') && (jogada[1] >= '1' && jogada[1] <= '3'))
    {   
        *linha = jogada[0] - 'A';
        *coluna = jogada[1] - '1';
    }else
    {
        *linha = -1;
        *coluna = -1;
        return;
    }
}
int ganhou(char jogador)
{
    for (int i = 0; i < LINHAS; i++)
    {
        if (tabuleiro[i][0] == jogador  && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
        {
            return true;
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
        {
            return true;
        }
        if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        {
            return true;
        }
        if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        {
            return true;
        }
    }
    return false;
}
int jogadaValida(int linha, int coluna)
{
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS)
    {
        return false;
    }
    if (tabuleiro[linha][coluna] != ' ')
    {
        return false;
    }
    return true;
}

void visualizar()
{
    printf("  1   2   3\n");
    printf("A %c | %c | %c \n",tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf(" ___|___|___\n");
    printf("B %c | %c | %c \n",tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf(" ___|___|___\n");
    printf("C %c | %c | %c \n",tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf(" ___|___|___\n");
    printf("    |   |");
    printf("\n");
}

int main()
{
    int fim = false;
    int jogadaAtual;
    int linha, coluna;
    char ordem [9] = {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'};
    char jogada[3];
    char jogador;

    while (!fim)
    {
        for (jogadaAtual = 0; jogadaAtual < 9; jogadaAtual++)
        {
            jogador = ordem[jogadaAtual];
            visualizar();
            printf("jogador '%c' Digite a posicao da jogada\n", jogador);
            fgets(jogada, 3, stdin);
            fflush(stdin);
            jogada[strlen(jogada)] = '\0';
            separarJogada(jogada, &linha, &coluna);

            if (jogadaValida(linha, coluna))
            {
                tabuleiro[linha][coluna] = jogador;
            }
            else
            {
                printf("Jogada invalida jogue novamente!\n");
                jogadaAtual--;
            }
            if (ganhou(jogador))
            {
                printf("\n");
                printf("JOGADOR %c GANHOU!\n", jogador);
                visualizar();
                fim = true;
                break;
            }
        }
        if (!fim)
        {
            printf("\n");
            printf("EMPATE!\n");
            visualizar();
            fim = true;
        }
    }
    return 0;
}