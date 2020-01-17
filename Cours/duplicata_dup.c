/* 0 */#include <stdio.h>
/* 1 */#include <stdlib.h>
/* 2 */#include <string.h>
/* 3 */
/* 4 */void str_nuller(char *);
/* 5 */int fpeek(FILE *);
/* 6 */
/* 7 */void str_nuller(char * string) {
/* 8 */    for(int i=0; i < (int) strlen(string); i++) {
/* 9 */        string[i] = '\0';
/* 10 */    }
/* 11 */}
/* 12 */
/* 13 */int fpeek(FILE *stream)
/* 14 */{
/* 15 */    int c;
/* 16 */
/* 17 */    c = fgetc(stream);
/* 18 */    ungetc(c, stream);
/* 19 */
/* 20 */    return c;
/* 21 */}
/* 22 */
/* 23 */int main(int argc, char ** argv) {
/* 24 */    char line[1000] = "";
/* 25 */    int n_line = 0, stop_while = 1;
/* 26 */    FILE * file, * dup;
/* 27 */    if (argc != 2) {
/* 28 */        printf("USAGE : ./dupicata file_to_duplicate\n");
/* 29 */        exit(1);
/* 30 */    }
/* 31 */    file = fopen(argv[1], "r");
/* 32 */    if (file == NULL) {
/* 33 */        printf("FILE DOES NOT EXIST.\n");
/* 34 */        fclose(file);
/* 35 */        exit(1);
/* 36 */    }
/* 37 */    char new_file[100];
/* 38 */    strncpy(new_file, argv[1], strlen(argv[1])-2);
/* 39 */    new_file[strlen(argv[1])-1] = '\0';
/* 40 */    strcat(new_file, "_dup.c");
/* 41 */    dup = fopen(new_file, "w");
/* 42 */    strcpy(line, fgets(line, 512, file));
/* 43 */    while(stop_while)
/* 44 */    {
/* 45 */        char new_line[10000] = "";
/* 46 */        sprintf(new_line, "/* %d", n_line);
/* 47 */        strcat(new_line, " */");
/* 48 */        strcat(new_line, line);
/* 49 */        fputs(new_line, dup);
/* 50 */        char c = fgetc(file);
/* 51 */        if (c < 0)
/* 52 */        {
/* 53 */            stop_while = 0;
/* 54 */        }
/* 55 */        else {
/* 56 */            ungetc(c, file);
/* 57 */            strcpy(line, fgets(line, 512, file));
/* 58 */        }
/* 59 */        n_line++;
/* 60 */    }
/* 61 */    fclose(file);
/* 62 */    fclose(dup);
/* 63 */}