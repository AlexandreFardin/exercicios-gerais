#include "esfera_utils.h"
#include <stdio.h>

int main(){
    float r;
    scanf("%f",&r);
    printf("Area: %.2f\n",calcula_area(r));
    printf("Volume: %.2f\n",calcula_volume(r));

}