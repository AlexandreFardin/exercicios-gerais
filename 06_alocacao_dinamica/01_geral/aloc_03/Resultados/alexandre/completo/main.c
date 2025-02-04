#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main(){
    int tam;
    scanf("%d\n",&tam);
    char *vetor = CriaVetor(tam);
    ImprimeString(vetor,tam);
    LeVetor(vetor,tam);
    ImprimeString(vetor,tam);
    LiberaVetor(vetor);




    return 0;
}