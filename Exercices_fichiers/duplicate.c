#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_nuller(char *);
int fpeek(FILE *);

void str_nuller(char * string) {
    for(int i=0; i < (int) strlen(string); i++) {
        string[i] = '\0';
    }
}

int main(int argc, char ** argv) {
    char line[1000] = "";
    int n_line = 0, stop_while = 1;
    FILE * file, * dup;
    if (argc != 2) {
        printf("USAGE : ./dupicata file_to_duplicate\n");
        exit(1);
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("FILE DOES NOT EXIST.\n");
        fclose(file);
        exit(1);
    }
    char new_file[100];
    strncpy(new_file, argv[1], strlen(argv[1])-2);  // on enlève le .c de l'argument
    new_file[strlen(argv[1])-1] = '\0';             // on ajoute \0 à la fin de la chaine
    strcat(new_file, "_dup.c");                     // on suffixe l'argument par _dup.c
    dup = fopen(new_file, "w");
    strcpy(line, fgets(line, 512, file));
    while(stop_while)
    {
        char new_line[10000] = "";
        sprintf(new_line, "/* %d", n_line);
        strcat(new_line, " */");
        strcat(new_line, line);
        fputs(new_line, dup);
        char c = fgetc(file);
        if (c < 0)
        {
            stop_while = 0;
        }
        else {
            ungetc(c, file);
            strcpy(line, fgets(line, 512, file));
        }
        n_line++;
    }
    fclose(file);
    fclose(dup);
}