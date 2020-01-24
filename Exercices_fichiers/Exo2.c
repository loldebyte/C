#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
//#include <io.h>
#include <stdbool.h>

void print_tab(char *);
void count_tab(char *);
void create_tab(char *);
void append_tab(char *);
void edit_tab_at_i(char *, int32_t);
void delete_name_at_i(char *, int32_t);
/*
concept : on malloc la taille du fichier - 25 bytes.
on stocke en mémoire le fichier entier jusqu'au ième nom.
on seek 25 bytes en avant
on copie tout le reste du fichier dans la mémoire
on ferme le fichier
on l'ouvre en wt et on écrit le contenu de la mémoire.
*/
void delete_name_at_i(char * path, int32_t i) {
    FILE * file = fopen(path, "rt");
    if (file == NULL) {
        printf("COULD NOT OPEN FILE !\n");
        exit(EXIT_FAILURE);
    }
    int32_t k = 0;
    for (k = 0; k<i-1; i++) {

    }
}

void edit_tab_at_i(char * path, int32_t n) {
    FILE * file = fopen(path, "r+t");   // opening file in read/write textual mode, because we need to edit the file.
    if (file == NULL) {
        printf("COULD NOT OPEN FILE !\n");
        exit(EXIT_FAILURE);
    }
    char student[25];
    printf("Enter the name to use as substitute :\n");
    bzero(student, 25); // nulling the string student to make sure we dont copy random stuff
    fgets(student, 25, stdin); // capturing stdin and stocking it in student
    fseek(file, (n-1)*25, SEEK_SET); // going to the nth cell, at the n-1 position.
    fwrite(student, sizeof(char), 25, file); // writing 25 bytes of data to the file.
    fclose(file);
}

void append_tab(char * path) {
    FILE * file = fopen(path, "at"); // opening file in append textual mode
    if (file == NULL) {
        printf("COULD NOT APPEND TO FILE !\n");
        exit(EXIT_FAILURE);
    }
    char student[25];
    printf("Enter the name to append :\n");
    fgets(student, 25, stdin);
    if (fwrite(student, sizeof(char), 25, file) != 25) { // if we write less than 25 bytes,
        printf("ERROR : COULD NOT WRITE TO FILE !\n");   // then the writing failed and we raise
        fclose(file); // an error
        exit(EXIT_FAILURE);
    }
    else {
        printf("ADDED NAME %s TO FILE \"%s\"\n", student, path);
        fclose(file);
    }
}

void create_tab(char * path) {
    FILE * file = fopen(path, "wt");
    char student[25];
    if (file == NULL) {
        printf("COULD NOT CREATE FILE !\n");
        exit(EXIT_FAILURE);
    }
    printf("ENTER NAMES. ENTER \'0\' TO EXIT\n");
    while (student[0] != '0') {
        bzero(student, 25);
        fgets(student, 25, stdin);
        if (student[0] != '0') {
            printf("WROTE %sto file.\n", student);
            fwrite(student, sizeof(char), 25, file);
        }
    }
    fclose(file);
}

void print_tab(char * path) {
    FILE * file = fopen(path, "rt");
    if (file == NULL) {
        printf("COULD NOT OPEN FILE. DOES %s EXIST IN CURRENT DIRECTORY ?\n", path);
        exit(EXIT_FAILURE);
    }
    char student[25];
    printf("READING NAMES FROM FILE \"%s\" :\n", path);
    while(fread(student, sizeof(char), 25, file) == 25) {
        printf("%s", student);
    }
    if (feof(file)) {
        fclose(file);
        exit(EXIT_SUCCESS);
    }
    else {
        printf("ERROR : could not read file\n");
        fclose(file);
        exit(EXIT_SUCCESS);
    }
}

void count_tab(char * path) {
            FILE * file = fopen(path, "rt");
            if (file == NULL) {
                printf("COULD NOT OPEN FILE. DOES %s EXIST IN CURRENT DIRECTORY ?\n", path);
                exit(EXIT_FAILURE);
            }
            char student[25];
            int32_t count = 0;
            while(fread(student, sizeof(char), 25, file) == 25) {
                count++;
            }
            if (feof(file)) {
                printf("There is %d names in file \"%s\"\n", count, path);
                fclose(file);
                exit(EXIT_SUCCESS);
            }
            else {
                printf("ERROR : could not read file\n");
                fclose(file);
                exit(EXIT_SUCCESS);
            }
}

int32_t main(int32_t argc, char ** argv) {
    if (argc < 3) {
        printf("ERROR : usage ./Exo2 file -flag\n"
        "YOU MUST USE A FLAG :\n"
        "-0 for creation\n"             // done
        "-a to add a name\n"            // done
        "-p to print all names\n"       // done
        "-c to print number of names\n" // done
        "-m i to modify the i-th name\n"// done
        "-i i to delete the i-th name\n"// 
        "-n to delete name n\n");       //
        exit(EXIT_FAILURE);
    }
    if (argv[2][0] != '-') {
        printf("ERROR : flag must be preceded by a single -\n");
        exit(EXIT_FAILURE);
    }
    switch(argv[2][1]) {
        case '0':
            create_tab(argv[1]);
            break;
        
        case 'a':
            append_tab(argv[1]);
            break;
        
        case 'p':
            print_tab(argv[1]);
            break;

        case 'c':
            count_tab(argv[1]);
            break;

        case 'm':
            if (argc < 3) {
                printf("USAGE : %s %s # to modify the #th name !\n", argv[0], argv[1]);
                exit(EXIT_FAILURE);
            }
            int32_t number = (int32_t) strtol(argv[2], NULL, 10);
            if (number < 0) {
                printf("NAMES ARE INDEXED STARTING AT 1, PLEASE ENTER AN INTEGER > 0 !\n");
                exit(EXIT_FAILURE);
            }
            edit_tab_at_i(argv[1], number);
            break;
        
        case 'i':
            printf("NOT YET IMPLEMENTED. SORRY!\n");
            break;

        case 'n':
            printf("NOT YET IMPLEMENTED. SORRY!\n");
            break;

        default:
            printf("ERROR : usage ./Exo2 file -flag\n"
            "YOU MUST USE A FLAG :\n"
            "-0 for creation\n"             // done
            "-a to add a name\n"            // done
            "-p to print all names\n"       // done
            "-c to print number of names\n" // done
            "-m i to modify the i-th name\n"// done
            "-i i to delete the i-th name\n"// 
            "-n to delete name n\n");       //
    }
}