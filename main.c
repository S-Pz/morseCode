#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "morse.h"
#include "menu.h"

void main(){
    
    char Option, *token, *Input, ch, Temp[256];
    char InputString[256], message[256]= "";
    char *msg = malloc(256);
    
    BinaryTree();

    int aux = menu();
    
    switch (aux){
    
        case 1 :

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
            printf("%s", message);

        break;

        case 2:

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
                }
            }
        break;
        
        case 0 :
            printf("Você escolheu a opção SAIR");
        break;
    }
    DeleteNode(Root);
}
