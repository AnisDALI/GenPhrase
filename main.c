#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAILLE_MAX 100000 // Tableau de taille 1000

int main()
{
    FILE* fichier ;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    char type[TAILLE_MAX] = "Nom";
    fichier = fopen("C:\\Users\\User\\CLionProjects\\GenPhrase/dico.txt", "r");
    char d[] = " ";

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {


            if (strstr(chaine,type)!=NULL)

            {
                int bll=0;
                char d[] = " ";

                int i=0;
                char son[TAILLE_MAX];
                char *p = strtok(chaine, d);
                p = strtok(NULL, d);
                while(p != NULL)
                {

                    printf("%s\n", p);
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

                        son[i-1]=p[0];
                    }

                    i=0;

                    p = strtok(NULL, d);
                    p = strtok(NULL, d);
                }

                while(son[i]!="\0")
                {
                    printf("%c",son[i]);
                    i++;
                }


            }


        }

        fclose(fichier);
    }
    else
    {
        printf("erreur?") ;
    }

    return 0;
}