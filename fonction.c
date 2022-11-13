
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


        fclose(fichier);
        char result= son[rdm];
        return result;

    }

    else {
        printf("erreur?");
        return 0;
    }


}



char* trvDeuxiemeFils(char* type,char* chemin)
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

                            son[cpt]=p[1];
                            cpt++;

                        }





                        bll=0;
                    }
                    p = strtok(NULL, d);
                    p = strtok(NULL, d);


                }





            }


        }

        rdm = rand() % cpt;


        fclose(fichier);

        char result= son[rdm];

        char conca[TAILLE_MAX];
        conca[0]=chemin;
        conca[1]=result;
        printf("%s",conca);





        return conca;

    }

    else {


        printf("erreur?");
        return 0;

    }


}


