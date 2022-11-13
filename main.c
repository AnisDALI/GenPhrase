
#include "fonction.c"


int main()
{


    char* test;
    char mot[TAILLE_MAX];
    int hauteur=0;
    test = trvRacine("Nom");

    printf("%c\n", test);
    char* fils;
    fils=trvFils("Nom",test);
    printf("%s", fils);
    return 0;
}