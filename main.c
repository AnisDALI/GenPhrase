
#include "fonction.c"


int main()
{
    int choix;
    srand( time( NULL ) );
    printf("================| GENERATEUR DE PHRASE |================\n\n");
    printf("Choisissez un modele:\n\n");
    printf("Modele 1 : nom - adjectif - verbe - nom \n");
    printf("Modele 2 : nom - qui - verbe - verbe - nom - adjectif \n");
    printf("Votre choix :");
    scanf("%d",&choix);

    switch (choix) {
        case 1: {

            printf("%s ", afficherType("Nom"));
            printf("%s ",afficherType("Adj"));
            printf("%s ",afficherType("Ver"));
            printf("%s ", afficherType("Nom"));
            break;
        }
        case 2: {
            printf("%s ", afficherType("Nom"));
            printf("qui ");
            printf("%s ",afficherType("Ver"));
            printf("%s ",afficherType("Ver"));
            printf("%s ", afficherType("Nom"));
            printf("%s ",afficherType("Adj"));
            break;
        }
    }







    return 0;
}