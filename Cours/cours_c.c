// fonction qui calcule l'inverse de n'importe quelle fonction :

double agnostic_inverse( double (*f)(double), double x, int8_t * err) {
	if(!f(x)) {
		* err = -1;
		return -1;
	}
	* err = 1;
	return (x/f(x));
}

// exemple d'appel :
int32_t x;
int8_t error;
agnostic_inverse(pow, x, error);
// pointeur de fonction : type_retour (*pf)(types_reçus, en_param, etc)

// chaine suivante est CONSTANTE, IMPOSSIBLE A MODIFIER !! :
char * chaine = "ceci est une chaine constante!";

// note : "abc" est équivalent a : {'a', 'b', 'c', '\0'}

// puts(a) <=> printf("%s\n", a)
// saisie de chaine : fgets(chaine, nb, stdin) stocke nb-1 octets(char) dans chaine
// , et stocke \0 dans le dernier octet 
// flush stdin après un fgets
// /!\ : EFFACER LES \n DES INPUTS OBTENUS VIA FGETS via :
// if ...	
chaine[(strlen(chaine)-1)] = '\0'

// FONCTIONS SUR LES STRINGS :
// strcmp OU strncmp ET/OU stricmp OU strnicmp = comparaison
// strcat OU strncat = concaténation
// strchr OU strstr OU strpbrk = recherche
// strcpy OU strncpy = strcpy(dest, src) /!\ strcpy includes the \0 but strncpy does NOT !
// /!\ ALL n VERSION LIMIT THE NUMBER OF CHARACTERS THE FUNCTION APPLIES TO

// fputs & fgets : lis/écrit une ligne (jusqu'à \n). fgetc lis un octet
// fprintf ne peut écrire que du texte, éventuellement via variable
// Il en découle que fscanf ne peut lire QUE du texte !
// fputs écrit du texte sans variable
// fwrite renvoie le nb d'éléments écrits, a comparer avec l'arguments nmemb pour s'assurer que l'exécution s'est bien passée !
// NOTE : cf fwrite.c qui contient le man fwrite.
// NOTE : supposons qu'on fwrite un tableau de 1000 double dans fichier. On a donc :
fwrite(tableau, sizeof(talbeau[0]), 1000, fichier);
// supposons maintenant que l'on aie :
fwrite(tableau, sizeof(talbeau[0]), 1001, fichier);
// L'instruction ci dessus ne plantera que rarement : on ne modifie pas l'addresse derrière, on se contente de l'écrire ailleurs
// autrement dit, elle va écrire n'importe quoi dans le fichier, à la 1001ème case.
// fread fonctionne de manière très similaire à fwrite : copié deouis le man fread :
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
/* The  function  fread() reads nmemb items of data, each size bytes long,
    from the stream pointed to by stream,  storing  them  at  the  location
    given by ptr.
*/
