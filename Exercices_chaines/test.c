#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

int main(int argc, char ** argv) {
    if (argc <2) {
        printf("Not enough args");
        return -1;
    }
    char * tmp = malloc(sizeof(char) * strlen(argv[1]));
    strcpy(tmp, argv[1]);
    printf("%s\n", tmp);
    free(tmp);
}
