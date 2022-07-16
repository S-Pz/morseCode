#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morse.h"

struct Node{
    char DataChar;
    struct Node *LeftTree, * RightTree;
};


void BinaryTree(){// Função para criar a árvore

    //Organização dos morse via ordem alfabética

    DataTable[0] = ".-" ; DataTable[1] = "-...";
    DataTable[2] = "-.-." ; DataTable[3] = "-..";
    DataTable[4] = "." ; DataTable[5] = "..-.";
    DataTable[6] = "--." ; DataTable[7] = "...."; 
    DataTable[8] = ".." ; DataTable[9] = ".---";
    DataTable[10] = "-.-" ; DataTable[11] = ".-.."; 
    DataTable[12] = "--" ; DataTable[13] = "-.";
    DataTable[14] = "---" ; DataTable[15] = ".--.";
    DataTable[16] = "--.-" ; DataTable[17] = ".-."; 
    DataTable[18] = "..." ; DataTable[19] = "-";
    DataTable[20] = "..-" ; DataTable[21] = "...-" ;
    DataTable[22] = ".--" ; DataTable[23] = "-..-" ;
    DataTable[24] = "-.--" ; DataTable[25] = "--.." ;


    Root = CreateNode(); // Cria a raiz da árvore nula, sem nenhum dado

    // For para adicionar cada índice da tabela na árvore
    for (int i = 0; i<26; i++){
        AddNode('A' + i, DataTable[i]);
    }
}

// Função sem retorno para adicionar um nó na árvore
void AddNode(char ch, char *str){
    
    Current = Root;
    char *ptr = str;
    
    while (*ptr){

        if(*ptr == '.'){
            if(Current-> LeftTree == NULL){
                Current-> LeftTree = CreateNode();
            }
            Current = Current-> LeftTree;
        }
        if(*ptr == '-'){
            if(Current-> RightTree == NULL){
                Current-> RightTree = CreateNode();
            }
            Current = Current-> RightTree;
        }
        ptr ++;
    }
    Current->DataChar = ch;
}

//Função para criar  a raiz da árvore e retorna a raiza da árvore
NODE *CreateNode(){

    NODE *ptr = (NODE *) malloc(sizeof(NODE));
    ptr-> DataChar = ' ';

    ptr->LeftTree = ptr->RightTree = NULL;

    return ptr;
}
// Dar uma olhada nessa função, para saber está sendo utilzada corretamente
char GetChar(char *str){

    Current = Root;
    if(strlen(str) == 0){
        return ' ';
    }
    char *ptr = str;

    while(*ptr){

        if(*ptr == '.'){
            Current = Current-> LeftTree;
        }
        if(*ptr == '-'){
            Current = Current->RightTree;
        }
        ptr ++;
    }
    return Current->DataChar;
}
// Função para deleter um no da árvore, recebe como parâmetro o nó da árvore
void DeleteNode(NODE *ptr){
    
    if(ptr != NULL){
        if(ptr->LeftTree != NULL){
            DeleteNode(ptr->LeftTree);
            ptr->LeftTree = NULL;
        }
        if(ptr->RightTree != NULL){
            DeleteNode(ptr->RightTree);
            ptr->RightTree = NULL;
        }
        free(ptr);
        ptr = NULL;
    }
}

int ReadString(char *p){
    
    printf("dentro do Read \n");

    int i = 0 , len = 0;

    do {
        p[i] = getchar();
        len ++;
        i++;

    }while(p[i-1] != '\n');

    p[i-1] = '\0';

    return --len;
}