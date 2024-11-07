#include<stdio.h>

#define  TAMANHO  100


void ImprimeInvertido(char* string);
void recebeString(char* string);

 
int main()
{
   char strintg[TAMANHO], *result; 
   if ((result = fgets(strintg,TAMANHO,stdin)) != NULL)
      printf("%s\n", result);
    

    return 0;
}

/*void recebeString(char* str){
    int i=0;
    while( fgets){
        i++;
    }
    
}
*/
void ImprimeInvertido(char* str){
    int i=0;
    if(str[i]=='\0')
        printf("%c",str[i]);
    else
        in
}