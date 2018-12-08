#include <stdlib.h>
#include <stdio.h>

#include "Header.h"	
#include "couleur_console.h"
#define couleur_texte(coul) printf("\033[%dm",coul)
#define couleur_fond(coul)	printf("\033[%dm",coul+10)

void Affichage_Tableau_Snake (t_tableau Jeu,int x)
{
	int i,j;
	
	(Jeu.tab)[0][0]=BORDURE;
	
	printf("\n");
	
	for(i=0;i<(Jeu.taille)+2;i++)
	{
		for(j=0;j<(Jeu.taille)+2;j++)
		{
			if(Jeu.tab[i][j]==SNAKE)
			{
				couleur_texte(JAUNE);
				printf(" %c",(Jeu.tab)[i][j]); 
				couleur_texte(RESET);
			}
			else if(Jeu.tab[i][j]==BORDURE)
			{
				couleur_texte(ROUGE);
				couleur_fond(ROUGE);
				printf(" %c",(Jeu.tab)[i][j]); 
				couleur_texte(RESET);
			}
			else if(Jeu.tab[i][j]==FOND)
			{
				printf(" %c",(Jeu.tab)[i][j]);
			}
			else if(Jeu.tab[i][j]==CORP_SNAKE)
			{
				couleur_texte(VERT);
				printf(" %c",(Jeu.tab)[i][j]); 
				couleur_texte(RESET);
			}
			else if(Jeu.tab[i][j]==OBJECTIF)
			{
				if(x%2==0)
				{
					couleur_texte(BLEU);
					printf(" %c",(Jeu.tab)[i][j]); 
					couleur_texte(RESET);
				}
				if(x%2!=0)
				{
					couleur_texte(ROUGE);
					printf(" %c",(Jeu.tab)[i][j]); 
					couleur_texte(RESET);
				}
			}

		}
		printf("\n");

	}

	printf("\n");
}

