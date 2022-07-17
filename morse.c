#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morse.h"

struct Node{ // Contéudo do nó da árvore
    char DataChar;
    char morseCode[4];
    struct Node *LeftTree, *RightTree;
};

void BinaryTree(){// Cria a árvore em morse

    //Organização por ordem alfabética

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

    //Números de 0 a 9
    DataTable[26] = "-----" ; DataTable[27] = ".---" ;
    DataTable[28] = "..---" ; DataTable[29] = "...--" ;
    DataTable[30] = "....-" ; DataTable[31] = "....." ;
    DataTable[32] = "-...." ; DataTable[33] = "--..." ;
    DataTable[34] = "---.." ; DataTable[35] = "----." ;

    Root = CreateNode(); // Cria a raiz da árvore nula, sem nenhum dado.

    // For para adicionar cada índice da tabela na árvore
    for (int i = 0; i < 26; i++){
        AddNode('A' + i, DataTable[i]);
    }
    for(int j = 26, i = 0 ; i < 10 && j < 36; i++, j++){
        AddNode('0' + i, DataTable[j]);
    }
}
// Converter a letra para o morse correspondente na [árvore de busca, fazend assim com que ele print 
// o código correspondente]

void AddNode(char ch, char str[]){ // Adiciona na árvore
    
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
    strcpy(Current->morseCode, str);

    printf("Arvore a esqueda: %c\n", Current->DataChar);
    printf("Arvore a esqueda: %s\n", Current->morseCode);
}

NODE *CreateNode(){// Cria nó da ávrvore

    NODE *ptr = (NODE *) malloc(sizeof(NODE));
    ptr->DataChar = ' ';

    ptr->LeftTree = ptr->RightTree = NULL;

    return ptr;
}

char GetChar(char *str){// Procura o elemento desejado na árvore

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
/*char procuraLetra(char *str){// Procura o elemento desejado na árvore

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
}*/

void DeleteNode(NODE *ptr){ // Deleta um nó da árvore
    
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

void preOrdem(NODE *ptr){
    if(ptr == NULL){
        return;
    }

    printf("%s %c\n",ptr->morseCode, ptr->DataChar);
    preOrdem(ptr->LeftTree);
    preOrdem(ptr->RightTree);
    
}

/*void emOrdem(NODE *ptr){
    if(ptr == NULL){
        return;
    }
    emOrdem(ptr->LeftTree);
    printf("%s %c\n",ptr->morseCode, ptr->DataChar);
    emOrdem(ptr->RightTree);
}*/
void decodifica(){

    char *token, *Input, ch, Temp[256];
    char InputString[256], message[256]= "";

    printf("Digite em código morse a menssagem: \n");

    setbuf(stdin,NULL);
    fgets(InputString, 256, stdin);

    strcpy(Input, InputString);         
    token = strtok(InputString, " /");              

    while(token != NULL){

        ch = GetChar(token);
        
        sprintf(Temp, "%c", ch);
        strcat(message, Temp);

        Input = Input + strlen(token);
                
        if(*Input != '/'){
            Input ++;
        }
        if(*Input == '/'){
            strcat(message, " ");
            Input ++;  
        }
        token = strtok(NULL, " /");
    }
    
    printf("A mensagem decodificada eh: ");
    printf("%s\n", message);
}

void codifica(char aux){
    char *msg = malloc(256);

    printf("Escreva a mensagem que sera Codificada: \n");
    setbuf(stdin,NULL);
    fgets(msg, 256, stdin);
        
    aux = strlen(msg);
       
    for(int i = 0; i < aux; i++){
        switch (msg[i]){
              
            case ' ':
                printf ("/");
            break;             
            case 'A':
                printf (" %s", DataTable[0]);
            break;
            case 'a':
                printf (" %s", DataTable[0]);
            break;                
            case 'B':
                printf (" %s", DataTable[1]);
            break;
            case 'b':
                printf (" %s", DataTable[1]);
            break;                
            case 'C':
                printf (" %s", DataTable[2]);
            break;
            case 'c':
                printf (" %s", DataTable[2]);
            break;               
            case 'D':
                printf (" %s", DataTable[3]);
            break;
            case 'd':
                printf (" %s", DataTable[3]);
            break;               
            case 'E':
                printf (" %s", DataTable[4]);
            break;
            case 'e':
                printf (" %s", DataTable[4]);
            break;               
            case 'F':
                printf (" %s", DataTable[5]);
            break;
            case 'f':
                printf (" %s", DataTable[5]);
            break;               
            case 'G':
                printf (" %s", DataTable[6]);
            break;
            case 'g':
                printf (" %s", DataTable[6]);
            break;               
            case 'H':
                printf (" %s", DataTable[7]);
            break;
            case 'h':
                printf (" %s", DataTable[7]);
            break;             
            case 'I':
                printf (" %s", DataTable[8]);
            break;
            case 'i':
                printf (" %s", DataTable[8]);
            break;                
            case 'J':
                printf (" %s", DataTable[9]);
            break;
            case 'j':
                printf (" %s", DataTable[9]);
            break;               
            case 'K':
                printf (" %s", DataTable[10]);
            break;
            case 'k':
                printf (" %s", DataTable[10]);
            break;              
            case 'L':
                printf (" %s", DataTable[11]);
            break;
            case 'l':
                printf (" %s", DataTable[11]);
            break;                
            case 'M':
                printf (" %s", DataTable[12]);
            break;
            case 'm':
                printf (" %s", DataTable[12]);
            break;               
            case 'N':
                printf (" %s", DataTable[13]);
            break;
            case 'n':
                printf (" %s", DataTable[13]);
            break;               
            case 'O':
                printf (" %s", DataTable[14]);
            break;
            case 'o':
                printf (" %s", DataTable[14]);
            break;                
            case 'P':
                printf (" %s", DataTable[15]);
            break;
            case 'p':
                printf (" %s", DataTable[15]);
            break;                
            case 'Q':
                printf (" %s", DataTable[16]);
            break;
            case 'q':
                printf (" %s", DataTable[16]);
            break;                
            case 'R':
                printf (" %s", DataTable[17]);
            break;
            case 'r':
                printf (" %s", DataTable[17]);
            break;              
            case 'S':
                printf (" %s", DataTable[18]);
            break;
            case 's':
                printf (" %s", DataTable[18]);
            break;              
            case 'T':
                printf (" %s", DataTable[19]);
            break;
            case 't':
                printf (" %s", DataTable[19]);
            break;                
            case 'U':
                printf (" %s", DataTable[20]);
            break;
            case 'u':
                printf (" %s", DataTable[20]);
            break;               
            case 'V':
                printf (" %s", DataTable[21]);
            break;
            case 'v':
                printf (" %s", DataTable[21]);
            break;                
            case 'W':
                printf (" %s", DataTable[22]);
            break;
            case 'w':
                printf (" %s", DataTable[22]);
            break;              
            case 'X':
                printf (" %s", DataTable[23]);
            break;
            case 'x':
                printf (" %s", DataTable[23]);
            break;                
            case 'Y':
                printf (" %s", DataTable[24]);
            break;
            case 'y':
                printf (" %s", DataTable[24]);
            break;
            case 'Z':
                printf (" %s", DataTable[25]);
            break;
            case 'z':
                printf (" %s", DataTable[25]);
            break;
            case '0':
                printf (" %s", DataTable[26]);
            break;
            case '1':
                printf (" %s", DataTable[27]);
            break;
            case '2':
                printf (" %s", DataTable[28]);
            break;
            case '3':
                printf (" %s", DataTable[29]);
            break;
            case '4':
                printf (" %s", DataTable[30]);
            break;
            case '5':
                printf (" %s", DataTable[31]);
            break;
            case '6':
                printf (" %s", DataTable[32]);
            break;
            case '7':
                printf (" %s", DataTable[33]);
            break;
            case '8':
                printf (" %s", DataTable[34]);
            break;
            case '9':
                printf (" %s", DataTable[35]);
            break;
        }
    }
    printf("\n");
}