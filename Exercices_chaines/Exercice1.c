#include <stdio.h>
#include <string.h>
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>

int main (void) {
    char pw[] = "mdp";
    printf("Veuillez entrer un mot de passe : \n");
    char input[5];
    fgets(input, 5, stdin);
    if (input[3] == '\n') {
        input[3] = '\0';
    }
    if (!strcmp(input,pw) && (strlen(input) == 3)) {
        printf("Bienvenue\n");
    }
    else {
        printf("Erreur\n");
        printf("chaine entrée : %s\n", input);
    }
}