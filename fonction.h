#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <time.h>

#define TAILLE_MAX 100000 // Tableau de taille 100000

typedef struct
{
    int fini;
    char* chemin;
} MOT;

char trvRacine(char type[TAILLE_MAX]);
MOT trvDeuxiemeFils(char* type,char chemin);
MOT trvFils(char* type,MOT chemin,int hauteur);
void afficherType(char* type);


