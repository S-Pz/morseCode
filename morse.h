#ifndef _MORSE_H
#define _MORSE_H

typedef struct Node NODE;

char *DataTable[36];
NODE *Root, *Current, *Temp;

/* *
 *
 * */
NODE *CreateNode();
void BinaryTree();
void AddNode(char, char *);
void DeleteNode(NODE *);
char GetChar(char *str);
void preOrdem(NODE *);
void emOrdem(NODE *);
void decodifica();
void codifica(char );

#endif /* __MORSE_H */