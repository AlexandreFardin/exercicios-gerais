#include "matrix_utils.h"
#include <stdio.h>

int main(){
    int l1,c1;
    scanf("%d %d",&l1,&c1);
    int matrix1[l1][c1];
    matrix_read(l1,c1,matrix1);
    matrix_print(l1,c1,matrix1);
    int l2,c2;
    scanf("%d %d",&l2,&c2);
    int matrix2[l2][c2];
    matrix_read(l2,c2,matrix2);
    matrix_print(l2,c2,matrix2);
    int escolha=0;
    while(escolha!=6){
        telaEntrada();
        scanf("%d",&escolha);

        if(escolha == 1){
            int result[l1][c1];
            matrix_add(l1,c1,matrix1,l2,c2,matrix2,result);
        }else if(escolha == 2){
            int result[l1][c1];
            matrix_sub(l1,c1,matrix1,l2,c2,matrix2,result);
        }else if(escolha == 2){
            int result[l1][c2];
            matrix_multiply(l1,c1,matrix1,l2,c2,matrix2,result);
        }
        matrix_print(l1,c1,matrix1);
    }

}