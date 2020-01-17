#include <stdio.h>
// <io.h> gère les fonctions bas niveau de gestions de fichiers ; notamment protocole systèmes et réseaux
// fflush vide le buffer ; écrivant dans le filestream ouvert le contenu du buffer
// fprintf écrit dans le filestream passé en paramètre.     NOTE : fprintf(stdout, x) : est équivalent a printf(x) !
// fichier binaire = données mémoires brutes ; texte = gestion des sauts de ligne (\n & \r) de code 10 et 13 respectivement


int main(void) {
    file = fopen(path, mode); // for mode values cf man fopen ; r (reading) r+ (read & write) w (write & truncate ie stream points to the BEGINNING of the file) w+ (read & write & truncate) a (append, stream positioned at the END of he file) a+ (append & read) b (specify we will be opening a binary file. According to man fopen this is redundant on POSIX systems)
    // the a modes function like adding "fseek(stream, 0, SEEK_END)" just before any write operation
    // what this means is : no matter WHERE you set the stream, a file opened with a mode will ALWAYS write at the end of the field
    fclose(file);
    // NOTE : fgets also works with files, as the f implies. It will continue until a \n is met. Most likely very useful for text files
}
