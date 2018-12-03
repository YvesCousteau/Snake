#include <stdlib.h>
#include <stdio.h>

#include "Header.h"	

#include "couleur_console.h"
#define couleur_texte(coul) printf("\033[%dm",coul)
#define couleur_fond(coul)	printf("\033[%dm",coul+10)

void Tableau_Jeu_Snake (t_tableau* Jeu)
{
	/*Choisir la taille de la zone de Jeu*/
	
	(Jeu->taille)=24;
	
	/*Allocation de la zone de Jeu*/
	
	Allocation_Tableau_Jeu_Snake (Jeu);
	
}

void Allocation_Tableau_Jeu_Snake (t_tableau* Jeu)
{
	int i=0;
	
	(Jeu->tab)=(char**)malloc(((Jeu->taille)+2)*sizeof(char*));
	
	for(i=0;i<(Jeu->taille)+2;i++)
	{
		(Jeu->tab)[i]=(char*)malloc(((Jeu->taille)+2)*sizeof(char));
	}
}
