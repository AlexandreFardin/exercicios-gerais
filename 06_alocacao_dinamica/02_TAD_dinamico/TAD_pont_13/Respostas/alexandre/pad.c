

#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"
#include "pad.h"


/**
 * @brief Uma estrutura que representa um PAD.
 */
/*typedef struct pad{ 
    int qtdpacientes; 
    tPaciente* listapacientes[100];
} tPad;*/

/**
 * @brief Cria um novo PAD.
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPad contendo o novo PAD criado.
 */
tPad* CriaPad(){
    tPad *p = (tPad *) calloc(1,sizeof(tPad));
    int i;
    for(i=0;i<100;i++){
        p->listapacientes[i] =CriaLesao();
    }

    return p;

}

/**
 * @brief Roda o PAD, permitindo que o usuário adicione pacientes e lesões.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser rodado.
 */
void RodaPad(tPad *p){

}

/**
 * @brief Imprime um relatório com as informações dos pacientes e lesões do PAD.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser impresso.
 */
void ImprimeRelatorioPad(tPad *p);

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPad.
 * 
 * @param p Ponteiro para a estrutura de dados tPad a ser liberada.
 */
void LiberaPad(tPad *p){
    int i;
    for(i=0;i<p->qtdpacientes<100;i++){
        
    }
}
