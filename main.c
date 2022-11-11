#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAILLE_MAX 100000 // Tableau de taille 1000

int main()
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    char type[TAILLE_MAX] = "Nom";
    int bll=0;

    int cpt=0;
    int i=0;
    char son[TAILLE_MAX];
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
        printf("%s",son);
        fclose(fichier);
    }

    else
    {
        printf("erreur?") ;
    }

    return 0;
}