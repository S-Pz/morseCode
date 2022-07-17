#include <stdio.h>

int main(){
    char DataTable[10];
    char a = 'A';
    char b = '.'; 
    char c = '.';
    char d = '.';

    printf("%d\n",a);

    for(int j = 0, i = 0 ; i < 10 && j < 10; i++, j++){
        AddNode('0' + i, DataTable[j]);
    }

    for(int k = 0; k < 10; k++){

        printf("%s",DataTable[k]);
    }
    return 0;
}