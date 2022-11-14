
#include "fonction.h"

char trvRacine(char type[TAILLE_MAX])
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX

    int bll=0;
    srand( time( NULL ) );
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
        char conca[TAILLE_MAX];
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
            printf("%s\n",conca);
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
        printf("%s\n",son);
        char result= son[rdm];
        if(result=='Z')
        {
            chemin.fini=1;
            printf("fini\n");
            return chemin;
        }

        chemin.chemin[hauteur]=result;

        printf("%s\n",chemin.chemin);





        return chemin;

    }

    else {


        printf("erreur?");


    }


}


void afficherType(char* type)
{
    char test;
    int i=0;
    char mot[TAILLE_MAX];
    int hauteur=2;
    test = trvRacine(type);
    MOT Pfils;
    MOT fils;

    printf("%c\n", test);

    Pfils= trvDeuxiemeFils(type,test);


    fils=trvFils(type,Pfils,hauteur);
    hauteur++;
    while(fils.fini!=1)
    {
        fils=trvFils(type,fils,hauteur);
        hauteur++;


    }
    return;
}


