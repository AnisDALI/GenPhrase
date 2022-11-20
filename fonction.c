
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
    fichier = fopen("../dico.txt", "r");
    char d[] = "    "; //separateur de mot

    if (fichier != NULL) //On verrifie que le fichier n'est pas vide
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) //On lis le fichier ligne par ligne en stockant celle ci dans la variable chaine
        {


            if (strstr(chaine,type)!=NULL)// On prend seulement les ligne avec le type choisi

            {

                char *p = strtok(chaine, d);// On separe les mot de la ligne grace a d= 'espace'
                p = strtok(NULL, d);// On saute le premier mot car on veut la forme de base
                while(p != NULL)
                {
                    i=0;

                    do//Boucle qui permet de verfier si il n'y a pas deux fois un fils identique
                    {
                       if(son[i]==p[0])
                        {

                            bll=1;
                        }

                        i++;

                    }while(son[i]!='\0');

                    if(bll==0)// Si nouvelle lettre
                    {

                        son[cpt]=p[0];
                        cpt++;
                    }
                    p = strtok(NULL, d);// Double saut de mot
                    p = strtok(NULL, d);
                    bll=0;
                }





            }


        }

        rdm = rand() % cpt;// On va prendre un fils au hasard


        fclose(fichier);
        char result= son[rdm];

        return result;

    }

    else {
        printf("erreur?");

    }


}



MOT trvDeuxiemeFils(char* type,char prm)
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int bll=0;

    int rdm;
    int cpt=0;
    int i=0;
    char d[] = "    ";
    char son[TAILLE_MAX]="";
    fichier = fopen("../dico.txt", "r");



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

                    if (p[0]==prm)// On ne prend que les mots qui commence par la racine
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
                            if(p[1]=='\0')// si le mot est deja fini on rendre Z dans les fils possible
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
        if(result=="Z")// Si on tombe sur le fils Z on place la variable "fini" de la structure mot a 1
        {
            mot.fini=1;
            mot.chemin=prm;

            return mot;

        }
        else
        {
            conca[0]=prm;
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
    char chaine[TAILLE_MAX] = "";
    int bll=0;

    int deb=0;
    int rdm;
    int cpt=0;
    int i=0;
    char son[TAILLE_MAX]="";
    fichier = fopen("../dico.txt", "r");
    char d[] = "    ";


    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {


            if (strstr(chaine,type)!=NULL)

            {


                char *p = strtok(chaine, d);
                p = strtok(NULL, d);
                char prm = chemin.chemin;


                while(p != NULL)
                {
                    i=0;
                    while(chemin.chemin[i]!='\0')// On parcour notre chemin lettre par lettre
                    {
                       if(chemin.chemin[i]!=p[i]) // On verifie si le debut du mot correspond a notre chemin
                       {
                           deb=1;

                       }
                       i++;
                    }
                    if (deb==0)// Si le debut correspond
                    {

                        i=0;

                        do
                        {

                            if(son[i]==p[hauteur])//verif doublons
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
    while(fils.fini!=1)// Tant que le mot n'est pas fini on continue a rechercher de nouvelle lettre
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
    printf("Modele 2 : nom - qui - verbe - verbe - nom - adjectif \n");
    printf("Modele 3 : adjectif - nom - verbe - adjectif - nom \n\n");

    do {
        printf("Votre choix :");
        var = scanf("%d", &choix);
        printf("\n");
        int c;
        if (var == 0 || choix < 1 || choix > 3) {
            c_textcolor(RED);
            printf("Veuillez entrer un nombre entre 1 et 3:\n");
            c_textcolor(WHITE);

        }
        while ((c = getchar()) != '\n' && c != EOF);
    } while (var == 0 || choix < 1 || choix > 3);

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
        case 3: {
            printf("%s ", afficherType("Adj"));
            printf("%s ",afficherType("Nom"));
            printf("%s ",afficherType("Ver"));
            printf("%s ",afficherType("Adj"));
            printf("%s\n\n", afficherType("Nom"));
            break;
        }
    }
    menu();
}