
#include "fonction.h"

char* trvRacine(char type[TAILLE_MAX])
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX

    int bll=0;
    srand( time( NULL ) );
    int rdm;
    int cpt=0;
    int i=0;
    char son[TAILLE_MAX]="";
    fichier = fopen("C:\\Users\\User\\CLionProjects\\GenPhrase/dico.txt", "r");
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
        printf("%d",rdm);

        fclose(fichier);
        char result= son[rdm];
        return result;

    }

    else {
        printf("erreur?");
        return 0;
    }


}



char* trvFils(char* type,char* chemin)
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int bll=0;

    int rdm;
    int cpt=0;
    int i=0;
    char son[TAILLE_MAX]="";
    fichier = fopen("C:\\Users\\User\\CLionProjects\\GenPhrase/dico.txt", "r");
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
        printf("%d",rdm);

        fclose(fichier);

        char result= son[rdm];

        printf("%c",result);
        for(i=0;chemin[i]!="\0";i++)
        {

        }
        chemin[i-1]=result;

        printf("sqdfqsdf");

        return chemin;

    }

    else {
        printf("erreur?");
        return 0;
    }


}


