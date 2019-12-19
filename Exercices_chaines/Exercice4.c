#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define SIZE_OF_STRINGS 50

int sizeOfTableOfString(char ** tableOfStrings, int sizeOfStrings);
int mailIsReferenced(char **, char *);
char * nameOfMailOwner(char **, char **,char *);

int sizeOfTableOfString(char ** tableOfStrings, int sizeOfStrings) {
    return (sizeof(tableOfStrings)/(sizeOfStrings*sizeof(char)));   // taille totale = taille éléments * nb_élements donc nb_éléments = taille totale / taille éléments
}

int mailIsReferenced(char ** tableauDeMails, char * mailAddress) {
    int tableLength = sizeOfTableOfString(tableauDeMails, SIZE_OF_STRINGS);
    for (int i=0; i<tableLength;i++) {
        if (strcmp(tableauDeMails+i*SIZE_OF_STRINGS*sizeof(char), mailAddress) == 0) {
            return i;
        }
    }
    return -1;
}

char * nameOfMailOwner(char ** tableauDeMails, char ** tableauDeNoms, char * mailAddress) {
    int tableIndex = mailIsReferenced(tableauDeMails, mailAddress);
    if (tableIndex == -1)
        return "NOT REFERENCED";
    return (tableauDeNoms+tableIndex*sizeof(char)*SIZE_OF_STRINGS)
}

int main(int argc, char **argv) {

}