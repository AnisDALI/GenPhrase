
#include "fonction.h"

char trvRacine(char type[TAILLE_MAX])
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX

    int bll=0;

    int rdm;
    int cpt=0;
    int i=0;
    char son[TAILLE_MAX]="";
    fichier = fopen("C:\\Users\\anis9\\CLionProjects\\GenPhrase/dico.txt", "r");
    char d[] = " ";

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {


            if (strstr(chaine,type)!=NULL)

            {

                char *p = strtok(chaine, d);
                p = strtok(NULL, d);
                while(p != NULL)
                {
                    i=0;

                    do
                    {
                       if(son[i]==p[0])
                        {

                            bll=1;
                        }

                        i++;

                    }while(son[i]!='\0');

                    if(bll==0)
                    {

                        son[cpt]=p[0];
                        cpt++;
                    }
                    p = strtok(NULL, d);
                    p = strtok(NULL, d);
                    bll=0;
                }





            }


        }

        rdm = rand() % cpt;


        fclose(fichier);
        char result= son[rdm];
        MOT mot;
        mot.chemin=result;
        return result;

    }

    else {
        printf("erreur?");

    }


}



MOT trvDeuxiemeFils(char* type,char chemin)
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int bll=0;

    int rdm;
    int cpt=0;
    int i=0;
    char d[] = " ";
    char son[TAILLE_MAX]="";
    fichier = fopen("C:\\Users\\anis9\\CLionProjects\\GenPhrase/dico.txt", "r");



    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {


            if (strstr(chaine,type)!=NULL)

            {


                char *p = strtok(chaine, d);
                p = strtok(NULL, d);
                char prm = chemin;


                while(p != NULL)
                {

                    if (p[0]==prm)
                    {

                        i=0;

                        do
                        {

                            if(son[i]==p[1])
                            {

                                bll=1;
                            }

                            i++;

                        }while(son[i]!='\0');


                        if(bll==0)
                        {
                            if(p[1]=='\0')
                            {
                                son[cpt]="Z";
                                cpt++;
                            }
                            else
                            {
                                son[cpt]=p[1];
                                cpt++;

                            }


                        }





                        bll=0;
                    }
                    p = strtok(NULL, d);
                    p = strtok(NULL, d);


                }





            }


        }

        rdm = rand() % cpt;
        MOT mot;


        fclose(fichier);
        char conca[TAILLE_MAX]="";
        char result= son[rdm];
        if(result=="Z")
        {
            mot.fini=1;
            mot.chemin=chemin;

            return mot;

        }
        else
        {
            conca[0]=chemin;
            conca[1]=result;


            mot.chemin=conca;

            return mot;
        }







    }

    else {


        printf("erreur?");


    }


}



MOT trvFils(char* type,MOT chemin,int hauteur)
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int bll=0;

    int deb=0;
    int rdm;
    int cpt=0;
    int i=0;
    char son[TAILLE_MAX]="";
    fichier = fopen("C:\\Users\\anis9\\CLionProjects\\GenPhrase/dico.txt", "r");
    char d[] = " ";


    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {


            if (strstr(chaine,type)!=NULL)

            {


                char *p = strtok(chaine, d); //corriger
                p = strtok(NULL, d);
                char prm = chemin.chemin;


                while(p != NULL)
                {
                    i=0;
                    while(chemin.chemin[i]!='\0')
                    {
                       if(chemin.chemin[i]!=p[i])
                       {
                           deb=1;

                       }
                       i++;
                    }
                    if (deb==0)
                    {

                        i=0;

                        do
                        {

                            if(son[i]==p[hauteur])
                            {

                                bll=1;
                            }
                            if(p[hauteur]=='\0'&& son[i]=='Z')
                            {
                                bll=1;

                            }
                            i++;

                        }while(son[i]!='\0');

                        if(p[hauteur]=='\0')
                        {

                            son[cpt]='Z';
                            cpt++;
                        }
                        if(bll==0)
                        {

                            son[cpt]=p[hauteur];
                            cpt++;

                        }





                        bll=0;
                    }
                    deb=0;
                    p = strtok(NULL, d);
                    p = strtok(NULL, d);


                }





            }


        }

        rdm = rand() % cpt;


        fclose(fichier);

        char result= son[rdm];
        if(result=='Z')
        {
            chemin.fini=1;

            return chemin;
        }

        chemin.chemin[hauteur]=result;







        return chemin;

    }

    else {


        printf("erreur?");


    }


}


char* afficherType(char* type)
{
    char test;
    int i=0;

    int hauteur=2;
    test = trvRacine(type);

    MOT Pfils;

    MOT fils;


    test = trvRacine(type);

    Pfils= trvDeuxiemeFils(type,test);
    if(Pfils.fini==1)
    {
        return Pfils.chemin;
    }


    fils=trvFils(type,Pfils,hauteur);

    hauteur++;
    while(fils.fini!=1)
    {
        fils=trvFils(type,fils,hauteur);
        hauteur++;


    }

    return fils.chemin;
}


void menu()
{

    int var;
    int choix;
    srand( time( NULL ) );
    c_textcolor(LIGHTBLUE);
    printf("================| GENERATEUR DE PHRASE |================\n\n");
    c_textcolor(WHITE);
    printf("Choisissez un modele:\n\n");
    printf("Modele 1 : nom - adjectif - verbe - nom \n");
    printf("Modele 2 : nom - qui - verbe - verbe - nom - adjectif \n\n");

    do {
        printf("Votre choix :");
        var = scanf("%d", &choix);
        printf("\n");
        int c;
        if (var == 0 || choix < 1 || choix > 2) {
            c_textcolor(RED);
            printf("Veuillez entrer 1 ou 2:\n");
            c_textcolor(WHITE);

        }
        while ((c = getchar()) != '\n' && c != EOF);
    } while (var == 0 || choix < 1 || choix > 2);

    c_textcolor(YELLOW);
    switch (choix) {
        case 1: {

            printf("%s ", afficherType("Nom"));
            printf("%s ",afficherType("Adj"));
            printf("%s ",afficherType("Ver"));
            printf("%s\n\n", afficherType("Nom"));
            break;
        }
        case 2: {
            printf("%s ", afficherType("Nom"));
            printf("qui ");
            printf("%s ",afficherType("Ver"));
            printf("%s ",afficherType("Ver"));
            printf("%s ", afficherType("Nom"));
            printf("%s\n\n",afficherType("Adj"));
            break;
        }
    }
    menu();
}