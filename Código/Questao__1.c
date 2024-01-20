#include <stdio.h>

// Função que imprimi os valores e espaços
void imprimir_valores(int *V, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", V[i]); // imprimir valores
        if (i < n - 1)
        {
            printf(" "); // imprimir espaços
        }
    }
    printf("\n");
}

// função que soma os valores
void Soma(int *V, int n)
{
    imprimir_valores(V, n);

    while (n > 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            V[i] += V[i + 1]; // formula que soma os valores
        }
        n--;

        imprimir_valores(V, n);
    }
}

int main()
{
    int valores[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &valores[i]); // lendo os valores
    }

    Soma(valores, 10);

    return 0;
}