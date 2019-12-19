#include <stdio.h>
#include <string.h>
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>

int unsigner(int);
char * substring(char *, int32_t, int32_t);
int index_of_first_occurence(char *, char *);

int unsigner(int value) {
    return value >= 0 ? value : 0;
}
char * substring(char * string, int32_t start, int32_t size) {
    char tmp[size];
    return (strncpy(tmp, string+start, size));
}

 int main (int argc, char **argv) {
    if (argc < 4) {
        printf("ERREUR : MANQUE D'ARGUMENTS\n   ");
        return(-1);
    }
    char * newString = malloc (sizeof(char) * strlen(argv[1]) + unsigner(sizeof(char) * (strlen(argv[2]) - strlen(argv[3]))) +1);
    char * tmp = malloc (sizeof(char) * strlen(argv[1]) +1);
    char * tmp2 = malloc (sizeof(char) * strlen(argv[1]) +1);
    uint pointerOnLastCell = strstr(argv[1], argv[2]) - argv[1]; // index of first occurence aka last unmodifie cell
    strcpy(tmp, argv[1]);   // tmp <- argv[1]
    strncpy(newString, argv[1], pointerOnLastCell); // newString <- unmodified chars
    printf("tmp precopie :%s\n", tmp);

    strcpy(tmp2, tmp+pointerOnLastCell+strlen(argv[2]));
    strcpy(tmp, tmp2);
    printf("tmp postcopie :%s\n", tmp);
    printf("tmp2 :%s\n", tmp);

    tmp[strlen(tmp)] = '\0';    // 
    printf("tmp : %s\n", tmp);

    while (pointerOnLastCell<(strlen(argv[1]) + unsigner(strlen(argv[2]) - strlen(argv[3])))) {
        newString[pointerOnLastCell] = '\0';
        strcat(newString,argv[3]);
        pointerOnLastCell += strlen(argv[3]);
        strcat(newString, tmp);
        pointerOnLastCell += strlen(tmp);
        
    }

    printf("\n\nTMP : %s\n\n", tmp);
    printf("CHAINE TRAITEE : %s\n", newString);
    free(tmp);
    free (newString);
 }