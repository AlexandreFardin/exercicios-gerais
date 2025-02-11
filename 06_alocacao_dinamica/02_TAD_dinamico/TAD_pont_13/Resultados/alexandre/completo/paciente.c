
#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

/**
 * @brief Retorna o número do cartão SUS do paciente.
 *
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna uma string contendo o número do cartão SUS do paciente.
 */
char *GetCartaoSusPaciente(tPaciente *p)
{
    return p->cartaoSus;
}

/**
 * @brief Retorna a quantidade de lesões do paciente.
 *
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de lesões do paciente.
 */
int GetQtdLesoesPaciente(tPaciente *p)
{
    return p->qtdLesoes;
}

/**
 * @brief Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 *
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 */
int GetQtdCirurgiasPaciente(tPaciente *p)
{
    int i;
    int qtd = 0;
    for (i = 0; i < p->qtdLesoes; i++)
    {
        if (PrecisaCirurgiaLesao(p->listaLesao[i]))
        {
            qtd++;
        }
    }
    return qtd;
}

/**
 * @brief Retorna a data de nascimento do paciente.
 *
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a data de nascimento do paciente.
 */
tData *GetNascimentoPaciente(tPaciente *p)
{
    return p->nascimento;
}

/**
 * @brief Cria uma estrutura do tipo tPaciente
 *
 * @return Retorna um ponteiro para a estrutura de dados tPaciente
 */
tPaciente *CriaPaciente()
{
    /*
    tLesao**  listaLesao;*/
    tPaciente *p = (tPaciente *)calloc(1, sizeof(tPaciente));
    if (p == NULL)
    {
        exit(1);
    }
    p->nome = (char *)calloc(TAM_NOME, sizeof(char));
    if (p->nome == NULL)
    {
        exit(1);
    }
    p->cartaoSus = (char *)calloc(TAM_CSUS, sizeof(char));
    if (p->cartaoSus == NULL)
    {
        exit(1);
    }
    p->listaLesao = (tLesao **)calloc(QTD_LESAO, sizeof(tLesao));
    if (p->listaLesao == NULL)
    {
        exit(1);
    }

    return p;
}

/**
 * @brief Lê informações sobre um paciente do usuário.
 *
 * @return Retorna um ponteiro para a estrutura de dados tPaciente contendo as informações lidas.
 */
void LePaciente(tPaciente *p)
{
    scanf("%[^\n]\n", p->nome);
    p->nascimento = LeData();
    scanf("%[^\n]\n", p->cartaoSus);
    scanf("%c\n", &p->genero);
}

/**
 * @brief Imprime as informações de um paciente na saída padrão.
 *
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 */
void ImprimePaciente(tPaciente *p)
{
    if (p->qtdLesoes != 0)
    {
        printf("- %s ", p->nome);
        int i;
        for (i = 0; i < p->qtdLesoes; i++)
        {
            printf("- %s", GetIdLesao(p->listaLesao[i]));
        }
        printf("\n");
    }
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPaciente.
 *
 * @param p Ponteiro para a estrutura de dados tPaciente a ser liberada.
 */
void LiberaPaciente(tPaciente *p)
{
    if (p->nome != NULL)
    {
        free(p->nome);
    }
    if (p->cartaoSus != NULL)
    {
        free(p->cartaoSus);
    }
    LiberaData(p->nascimento);
    int i;
    for (i = 0; i < QTD_LESAO; i++)
    {
        if (p->listaLesao[i] != NULL)
        {
            LiberaLesao(p->listaLesao[i]);
        }
    }
    if (p->listaLesao != NULL)
    {
        free(p->listaLesao);
    }

    if (p != NULL)
    {
        free(p);
    }
}

/**
 * @brief Adiciona uma lesão à lista de lesões do paciente.
 *
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 */
void AdicionaLesaoPaciente(tPaciente *p, tLesao *l)
{
    p->listaLesao[p->qtdLesoes] = l;
    p->qtdLesoes++;
}
