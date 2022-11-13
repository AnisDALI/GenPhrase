#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <time.h>

#define TAILLE_MAX 100000 // Tableau de taille 100000

char* trvRacine(char type[TAILLE_MAX]);
char* trvDeuxiemeFils(char* type,char* chemin);
char* trvFils(char* type,char* chemin,int hauteur);
