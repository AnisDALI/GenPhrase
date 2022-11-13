
#include "fonction.c"


int main()
{


    char* test;
    char mot[TAILLE_MAX];
    int hauteur=0;
    test = trvRacine("Nom");

    printf("%c\n", test);
    char* fils;
    fils= trvDeuxiemeFils("Nom",test);
    printf("%s", fils);

    printf("%s", trvFils("Nom","st",2));
    return 0;
}