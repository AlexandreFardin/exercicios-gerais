#include "matrix_utils.h"
#include <stdio.h>

int main(){
    int l,c;
    scanf("%d %d",&l,&c);
    int matrix[l][c];
    matrix_read(l,c,matrix);
    matrix_print(l,c,matrix);

}