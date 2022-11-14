
#include "fonction.c"


int main()
{


    char* test;
    char mot[TAILLE_MAX];
    int hauteur=2;
    test = trvRacine("Nom");
    char* Pfils;
    char* fils;

    printf("%c\n", test);

    Pfils= trvDeuxiemeFils("Nom",test);


    fils=trvFils("Nom",Pfils,hauteur);
    hauteur++;



    return 0;
}