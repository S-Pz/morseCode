#include<stdio.h>
#include<stdlib.h>

#include "menu.h"

int menu(){

    int aux;

    do{ 

        printf("###########################################\n");
        printf("Escolha uma das opcoes:\n");
        printf("Digite 1 para DECODIFICAR uma mensagem em morse \n");
        printf("Digite 2 para CODIFICAR uma mensagem em morse \n");
        printf("Digite 0 para SAIR \n");
        printf("###########################################\n");
        scanf("%d", &aux);
        fflush(stdin);

        return aux;

    }while(aux != 0);
}