#include <stdio.h>
#include <string.h>

// Função que lê uma matriz
void ler_matrix(int matrix[4][4])
{
    for (int linha = 0; linha < 4; linha++)
    {
        for (int coluna = 0; coluna < 4; coluna++)
        {
            scanf("%d", &matrix[linha][coluna]); // Lê os elemento da matriz
        }
    }
}

// Função que imprimi uma matriz
void imprimir_matrix(int matrix[4][4])
{
    for (int linha = 0; linha < 4; linha++)
    {
        for (int coluna = 0; coluna < 4; coluna++)
        {
            printf("%4d", matrix[linha][coluna]); // Imprime os elementos da matriz
        }
        printf("\n");
    }
}

// Função que soma duas matrizes
void soma(int A[4][4], int B[4][4], int R[4][4])
{
    for (int linha = 0; linha < 4; linha++)
    {
        for (int coluna = 0; coluna < 4; coluna++)
        {
            R[linha][coluna] = A[linha][coluna] + B[linha][coluna]; // formula para somar duas matrizes
        }
    }
}

// Função que subtrai duas matrizes
void sub(int A[4][4], int B[4][4], int R[4][4])
{
    for (int linha = 0; linha < 4; linha++)
    {
        for (int coluna = 0; coluna < 4; coluna++)
        {
            R[linha][coluna] = A[linha][coluna] - B[linha][coluna]; // formula para subtrair duas matrizes
        }
    }
}

// Função que multiplica duas matrizes 4x4
void mult(int A[4][4], int B[4][4], int R[4][4])
{
    for (int linha = 0; linha < 4; linha++)
    {
        for (int coluna = 0; coluna < 4; coluna++)
        {
            R[linha][coluna] = 0;
            for (int i = 0; i < 4; i++)
            {
                R[linha][coluna] += A[linha][i] * B[i][coluna]; // formula para multiplicar duas matrizes
            }
        }
    }
}

int main()
{
    // A matriz R representa o resultado das operações das matrizes

    int A[4][4], B[4][4], R[4][4]; // Declarando as matrizes
    char operacao[5]; // Declara uma string para as 3 operações

    ler_matrix(A);
    ler_matrix(B);

    scanf("%s", operacao);

    // Imprimindo o resultado das operações
    if (strcmp(operacao, "soma") == 0)
    {
        soma(A, B, R);
        imprimir_matrix(R);
    }
    else if (strcmp(operacao, "sub") == 0)
    {
        sub(A, B, R);
        imprimir_matrix(R);
    }
    else
    {
        mult(A, B, R);
        imprimir_matrix(R);
    }

    return 0;
}