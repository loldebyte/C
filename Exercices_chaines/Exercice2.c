#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define MAX_STR 200

char * substring(char *, int32_t, int32_t);

char * substring(char * string, int32_t start, int32_t size) {
    char tmp[size];
    return (strncpy(tmp, string+start, size));
}

int main(void) {
    char input[200];
    fgets(input, 200, stdin);
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    int32_t swap;
    swap = (strlen(input)/2);
    char swapped_string[200];
    strcpy(swapped_string, substring(input, swap, (strlen(input)-swap)));
    strncat(swapped_string, input, swap);
    printf("%s\n", swapped_string);
    printf("taille input : %lu\ntaille post swap : %lu\n", strlen(input), strlen(swapped_string));
}