#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char * strcatv2 (char *, char *);

char * strcatv2 (char * str1, char * str2) {
    char * result = malloc((strlen(str1)+strlen(str2)+2)*sizeof(char));
    strcat(strcat(strcpy(result, str1), " "), str2);
    return result;
}

int main(void) {
    char chaine1[50] ="stuff";
    char * chaine2 = "someotherstuff";
    puts(strcatv2(chaine1, chaine2));
}