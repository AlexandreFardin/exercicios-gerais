#include "matrix_utils.h"
#include <stdio.h>
#include <stdlib.h>

void telaEntrada(){
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

/**
 * @brief Lê os valores da matriz especificada a partir da entrada padrão.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser preenchida.
 */
void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
        j=0;
    }
}

/**
 * @brief Imprime a matriz especificada na saída padrão.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser impressa.
 */
void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int i,j;
    for(i=0;i<rows;i++){
        printf("|");
        for(j=0;j<cols;j++){
            printf("%d",matrix[i][j]);
            if(j!=cols-1){
                printf(" ");
            }
        }
        j=0;
        printf("|\n");
    }
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if(rows1 + rows2 >=1 && cols1 + cols2 >=1){
        return 1;
    }else
        return 0;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2 && cols1 == cols2 ){
        return 1;
    }else
        return 0;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int possible_matrix_multiply(int cols1, int rows2){
    if(cols1 == rows2){
        return 1;
    }
    return 0;
}

/**
 * @brief Soma duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da soma.
 */
void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    if(!possible_matrix_sum){
        printf("n soma");
        exit(0);
    }
    int i,j;
    for(i=0;i<rows1;i++){
        for(j=0;j<cols1;j++){
            result[i][j]=matrix1[i][j]+matrix2[i][j];
        }
        j=0;
    }
    transpose_matrix(rows1,cols1,result,matrix1);
}

/**
 * @brief Subtrai duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da subtração.
 */
void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    if(!possible_matrix_sub){
        printf("n sub");
        exit(0);
    }
    int i,j;
    for(i=0;i<rows1;i++){
        for(j=0;j<cols1;j++){
            result[i][j]=matrix1[i][j]-matrix2[i][j];
        }
        j=0;
    }
    transpose_matrix(rows1,cols1,result,matrix1);
}

/**
 * @brief Multiplica duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da multiplicação.
 */
void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
    int i,j;
    int k,l1,m1,l2,m2,num=0;
    for(i=0;i<rows1;i++){
        for(j=0;j<cols2;j++){
            l1=i;
            m1=j;
            l2=i;
            m2=j;
            for(k=0;k<cols1;k++){
                num+=matrix1[l1][m1]*matrix2[l2][m2];
                l2++;
                m1++;
            }
        
        }
        result[i][j]=num;
        j=0;
    }
    matrix_print(rows1,cols2,result);
}

/**
 * @brief Transpõe a matriz especificada.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser transposta.
 * @param result Matriz que armazenará o resultado da transposição.
 */
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            result[i][j]=matrix[i][j];
        }
    }
}

/**
 * @brief Multiplica a matriz especificada por um escalar.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser multiplicada.
 * @param scalar Escalar a ser multiplicado.
 */
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar);