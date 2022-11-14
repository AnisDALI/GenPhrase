
#include "fonction.c"


int main()
{


    char* test;
    int i=0;
    char mot[TAILLE_MAX];
    int hauteur=2;
    test = trvRacine("Nom");
    char* Pfils;
    char* fils;

    printf("%c\n", test);

    Pfils= trvDeuxiemeFils("Nom",test);


    fils=trvFils("Nom",Pfils,hauteur);
    hauteur++;
    while(i<10)
    {
        fils=trvFils("Nom",fils,hauteur);
        hauteur++;
        i++;
    }



    return 0;
}