#ifndef _MORSE_H
#define _MORSE_H

typedef struct Node NODE;
char *DataTable[26];
NODE *Root, *Current, *Temp, *CreateNode();

/* *
 *
 * */
 
void BinaryTree();
void AddNode(char, char *);
void DeleteNode(NODE *);
char GetChar(char *str);

#endif /* __MORSE_H */