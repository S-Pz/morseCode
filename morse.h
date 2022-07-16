#ifndef _ARVORE_H
#define _ARVORE_H

typedef struct Node NODE;
NODE *Root, *Current, *Temp, *CreateNode();

/* *
 *
 * */
 
void BinaryTree(), AddNode(char, char *);
void DeleteNode(NODE *);
char GetChar(char *str);
char *DataTable[26];
int ReadString(char *);

#endif /* __ARVORE_H */