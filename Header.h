#include <stdio.h>
#ifndef Header
#define  Header
#define FOND ' '
#define SNAKE '@'
#define CORP_SNAKE '+'
#define OBJECTIF '#'
#define BORDURE 'X'

typedef struct point
{
	int x;
	int y;
   
}t_point;


typedef struct
{
	char **tab;
	int taille;
	t_point tirage;
	
}t_tableau;

typedef struct
{
	t_point *corp_snake;
	int taille_snake;
    t_point tete_snake;
    
}t_snake;

typedef struct t_score
{
	char name[31];
	int taille_name;
	int storage;
    struct t_score *suivant;
    
}t_score;

void Affichage_Score_Snake ( t_score * score);

t_score* Ajout__Score_Snake ( t_score * score,int valeur,int x);

void trie (t_score* score);



void Tableau_Jeu_Snake (t_tableau* Jeu);

void Taille_Tableau_Snake (t_tableau* Jeu); 

void Allocation_Tableau_Jeu_Snake (t_tableau* Jeu);

void Remplissage_Tableau_Snake (t_tableau* Jeu);

void Affichage_Tableau_Snake (t_tableau Jeu);




int Joueur_Jeu_Snake (t_tableau* Jeu,t_snake* Snake,int choix);

void Tete_Snake (t_tableau* Jeu,t_snake* Snake);

void Remplissage_Jeu_Snake (t_tableau* Jeu,t_snake* Snake,int lvl);

int Security_Snake (t_snake* Snake,t_tableau* Jeu,int lvl);

void Key_Snake (t_snake* Snake,char*touche);

void Objectif_Snake (t_tableau* Jeu,t_snake* Snake);

void liberation (t_tableau* Jeu,t_snake* Snake);

#endif

