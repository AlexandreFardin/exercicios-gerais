#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * Cria um vetor de inteiros de tamanho especificado, alocado dinamicamente.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
int *CriaVetor(int tamanho){
    int *vetor = (int *) calloc (tamanho,sizeof(int));
    if (vetor == NULL) {
        printf("Problema na alocacao!");
        exit;
    }

    return vetor;
}

/**
 * Lê um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(int *vetor, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        scanf("%d ",&vetor[i]);
    }
}

/**
 * Calcula a média dos valores de um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
float CalculaMedia(int *vetor, int tamanho){
    float soma=0;
    int i;
    for(i=0;i<tamanho;i++){
        soma+=vetor[i];
    }

    return soma/tamanho;
}

/**
 * Libera a memória alocada para um vetor de inteiros.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(int *vetor){
    free(vetor);
}

#endif