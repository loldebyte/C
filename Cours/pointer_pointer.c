#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NB_STRINGS 4
#define STRING_SIZE 10

void inputer(char **, uint8_t, uint8_t);

void inputer(char ** tab_string, uint8_t nbstr, uint8_t sizestr) {
    for (int i=0; i<nbstr; i++) {
        fgets(* (tab_string+i*sizestr*sizeof(char)), sizestr, stdin);
        if(strlen(* (tab_string+i*sizestr*sizeof(char)))<=sizestr) {
            * (tab_string+i*sizestr*sizeof(char)+(strlen(* (tab_string+i*sizestr*sizeof(char)))-1)*sizeof(char)) = '\0';
        }
        fflush(stdin);
    }
}

int main(void) {
    char ** tab_string = malloc(STRING_SIZE * NB_STRINGS * sizeof(char));
    for (int i=0; i<NB_STRINGS; i++) {
        * (tab_string+i*STRING_SIZE*sizeof(char)) = malloc(i*STRING_SIZE*sizeof(char));
    }
    inputer(tab_string, NB_STRINGS, STRING_SIZE);
}