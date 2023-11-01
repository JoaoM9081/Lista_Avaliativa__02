#include <stdio.h>
#include <string.h>

// Definindo as variaveis de jogadores
typedef struct J
{
    char nome_jogador[30];
    char posicao;
    double forca_jogador;

} JOGADORES;

// Definindo as variaveis de time
typedef struct T
{
    char nome_time[30];
    JOGADORES elenco[11];

} TIME;

// Função que calcula a força dos jogadores
double forca_elenco(JOGADORES jogador)
{
    switch (jogador.posicao)
    {
    case 'G':
        return 8 * jogador.forca_jogador;
    case 'L':
        return 10 * jogador.forca_jogador;
    case 'Z':
        return 5 * jogador.forca_jogador;
    case 'V':
        return 8 * jogador.forca_jogador;
    case 'M':
        return 11 * jogador.forca_jogador;
    case 'A':
        return 12 * jogador.forca_jogador;
    default:
        return 0;
    }
}

// Função que calcula a força total dos times
double forca_total(TIME time)
{
    double Ftotal = 0;

    for (int i = 0; i < 11; i++)
    {
        Ftotal += forca_elenco(time.elenco[i]);
    }

    return Ftotal / 100;
}

// Função que lê os dados dos jogadores
void ler_jogadores(TIME *time)
{
    for (int j = 0; j < 11; j++)
    {
        char linha[70];
        fgets(linha, 70, stdin);

        sscanf(linha, "%[^;];%c;%lf", time->elenco[j].nome_jogador, &time->elenco[j].posicao, &time->elenco[j].forca_jogador);
    }
}

int main()
{
    TIME times[2]; // vetor que define os 2 times

    for (int t = 0; t < 2; t++)
    {
        // Usando fgets para poder armazenar espaços
        fgets(times[t].nome_time, 30, stdin);

        // tirando a nova linha
        times[t].nome_time[strcspn(times[t].nome_time, "\n")] = 0;

        ler_jogadores(&times[t]);
    }

    double forca_times[2]; // vetor que define a força de cada time

    for (int ft = 0; ft < 2; ft++)
    {
        forca_times[ft] = forca_total(times[ft]);
        printf("%s: %.2f de forca\n", times[ft].nome_time, forca_times[ft]); // Imprimindo a força de cada time
    }

    // Definindo qual time é o mais forte
    if (forca_times[0] > forca_times[1])
    {
        printf("%s eh mais forte\n", times[0].nome_time);
    }
    else
    {
        printf("%s eh mais forte\n", times[1].nome_time);
    }

    return 0;
}