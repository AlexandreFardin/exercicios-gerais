#include <stdio.h>

int recebeValor();
void imprime(int numero);
void fazTriangulo(int valor);

int main()
{
    int valor;
    valor = recebeValor();
    fazTriangulo(valor);

    return 0;
}

void fazTriangulo(int valor){
    int limiteAtual=1,numeroImprimir=1;
    int i,j
    for(i=1;i<=valor;i++){
        for(int j=0;j<limiteAtual;j++){
            imprime(numeroImprimir);
            numeroImprimir++;
        }
        limiteAtual++;
        printf("\n");
    }

}

int recebeValor(){
    int valor;
    scanf("%d",&valor);
    return valor;

}

void imprime(int numero){
    printf("%d ",numero);
}