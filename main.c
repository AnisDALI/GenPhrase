
#include "fonction.c"


int main()
{
    char tabl[TAILLE_MAX];


    char* test;
    test = trvRacine("Nom");
    printf("%c\n", test);

    char* fils=trvFils("Nom",test);
    printf("%s", fils);
    return 0;
}