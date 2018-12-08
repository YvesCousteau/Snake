#include <stdlib.h>
#include <stdio.h>
#include "gestion_clavier.h"
#include "Header.h"	
#include <time.h>
#include "couleur_console.h"
#define couleur_texte(coul) printf("\033[%dm",coul)
#define couleur_fond(coul)	printf("\033[%dm",coul+10)

int Joueur_Jeu_Snake (t_tableau* Jeu,t_snake* Snake,int choix,t_score* score)
{
	t_point tmp[30] ;
	t_point objo;
	
	int i=0;
	int win=0;
	int j = 0;
	char key_touche;
	char temp;
	int lvl = 0;
	int x = 0;
	
	
	(Snake->taille_snake)=0;
	
	(Snake->corp_snake) = (t_point*)malloc(((((Snake->taille_snake)+1)*(Snake->taille_snake)+1))*sizeof(t_point));
	
	/*Initialisation*/
	
	system("clear");
	couleur_texte(BLEU);
	printf("Que le jeu commence !!!\n\n");
	printf("Vous devez manger les (@) pour grandir et remplir l'ecran au maximum !\n\n");
	printf("Vous echouerez si vous touchez votre corps ou alors les extremitées de la zone avec votre tete\n\n");
	couleur_texte(RESET);
	
	/*Choisir la position de depart de la tete du Snake*/
	
	Tete_Snake (Jeu,Snake);	
	
	/*Definition du premiere objectif*/
		
	Objectif_Snake (Jeu,Snake);
	
	objo = Jeu->tirage;
	
	(Jeu->tab)[(Jeu->tirage.x)][(Jeu->tirage.y)]=OBJECTIF;
	
	Remplissage_Jeu_Snake (Jeu,Snake,lvl);
	
	
	do /*Boucle tant que il y a pas un choc entre le ver ou les barrois*/
	{		
		/*Affichage sur le terminal debut*/
		
		system("clear");
		
		/*Fin de partie si les regles ne sont pas respecté*/
		
		
		/*Fin de partie si il percute les barrois*/
		printf("\n\n\n");
		couleur_texte(VERT);
		printf("  _______                       _                  \n");
		printf(" /       )                     / |                 \n");
		printf("/$$$$$$  | ________    ______ $$ |   __   _______  \n");
		printf("$$ |__$$/ /        )  /      )$$ |  /  | /       ) \n");
		printf("$$      | $$$$$$$  | $$$$$$  |$$ |_/$$/ /$$$$$$  | \n");
		printf(" $$$$$$  |$$ |  $$ | /    $$ |$$   $$<  $$    $$ | \n");
		printf("/  |__$$ |$$ |  $$ |/$$$$$$$ |$$$$$$  | $$$$$$$$/  \n");
		printf("$$    $$/ $$ |  $$ |$$    $$ |$$ | $$ | $$       | \n");
		printf(" $$$$$$/  $$/   $$/  $$$$$$$/ $$/   $$/  $$$$$$$/  \n");
		printf("\nHugo Henrotte CPI2\n");	
		couleur_texte(RESET);
		Affichage_Tableau_Snake (*Jeu,x);
		
		/*Saisie d'un caractere --> Mouvement de la tete*/
		
		couleur_texte(JAUNE);
		printf("Taille=%d\n",(Snake->taille_snake));
		printf("Avancer : Z\n");
		printf("Reculer : S\n");
		printf("Gauche : Q\n");
		printf("Droite : D\n");
		printf("Tete : %c\n",(Jeu->tab)[(Snake->tete_snake.x)][(Snake->tete_snake.y)]);
		printf("Saisir la direction:\n");
		couleur_texte(RESET);
		
		for(i=0;i<(Snake->taille_snake)+1;i++)
		{
			tmp[i] = (Snake->corp_snake)[i];
		}
		
		key_touche= pressing_key(choix);
		
		/*Affichage sur le terminal Fin*/
		
		if(key_touche == NO_KEY)
		{
			key_touche = temp;
		}
		
		if(key_touche != NO_KEY)
		{
			
			Key_Snake (Snake,&key_touche);
			temp = key_touche;
		}
		
		/*Remplissage suivant le niveaux*/
		
		Remplissage_Jeu_Snake (Jeu,Snake,lvl);
		
		/*Objectif atteind*/
		
		if (((Snake->tete_snake.x) == (Jeu->tirage.x)) && ((Snake->tete_snake.y) == (Jeu->tirage.y)))
		{
			(Snake->taille_snake)++;

			(Snake->corp_snake) = (t_point*)malloc(((Snake->taille_snake)+2)*sizeof(t_point));
			
			objo = (Jeu->tirage);
			
			/*Nouvel objectif*/
			
			do
			{
				Objectif_Snake (Jeu,Snake);
				
			}while((Jeu->tab)[(Jeu->tirage.x)][(Jeu->tirage.y)]==(CORP_SNAKE));
			
			(Jeu->tab)[(Jeu->tirage.x)][(Jeu->tirage.y)]=OBJECTIF;
			
			if(Snake->taille_snake % 2 == 0)
			{
				lvl ++;
			}
			
			j=0;
		}
		
		/*Verification que le Snake ne fait pas d'erreur*/
		
		if((Jeu->tab)[(Snake->tete_snake.x)][(Snake->tete_snake.y)] == BORDURE)
		{
			win = 1;
		}
		
		(Jeu->tab)[(Jeu->tirage.x)][(Jeu->tirage.y)]=OBJECTIF;
		
		/*Definition du corp avec son developpement*/
		
		for(i=1;i<(Snake->taille_snake)+1;i++)
		{	
			
			(Snake->corp_snake)[i] = tmp [i-1];
			
			(Jeu->tab)[(Snake->corp_snake)[i].x][(Snake->corp_snake)[i].y]=CORP_SNAKE;
		}
		
		/*Verification que le Snake ne fait pas d'erreur*/
		
		if((Jeu->tab)[(Snake->tete_snake.x)][(Snake->tete_snake.y)] == CORP_SNAKE)
		{
			win = 1;
		}
		
		/*couleur clignitante*/
		
		if(j%2==0)
		{
			x++;
		}
		
		/*probleme avec un troue dans le snake du coup permet de le fixer*/
		
		if(j<=Snake->taille_snake)
		{
			(Jeu->tab)[objo.x][objo.y] = CORP_SNAKE;
		}
		
		(Jeu->tab)[(Snake->tete_snake.x)][(Snake->tete_snake.y)]=SNAKE;
		
		j++;
		
	}while(win!=1);
	
	
	system("clear");
	
	couleur_texte(VERT);
	printf("       ---_ ......._-_--.     \n");
	printf("      (/| /      / /| /  |    \n");
	printf("      /  /     .'  -=-'   `.  \n");
	printf("     /  /    .'             ) \n");
	printf("   _/  /   .'        _.)   /  \n");
	printf("  / o   o        _.-' /  .'   \n");
	printf("  |          _.-'    / .'*|   \n");
	printf("   |______.-'//    .'.' |*|   \n");
	printf("    |/  | / //   .'.' _ |*|   \n");
	printf("    '   |/ //  .'.'_ _ _|*|   \n");
	printf("      .' .// .'.' |  _ _|*|   \n");
	printf("      `- /_-'''   | _ _ |*|   \n");
	printf("       `/'        | _ _ |*|   \n");
	printf("      /^|          | _ _ |*   \n");
	printf("     '  `           | _ _ |   \n");
	printf("                     |_       \n");
	printf("Hugo Henrotte CPI2\n");	
	couleur_texte(RESET);;
	couleur_texte(ROUGE);
	printf("   /$$$$$$   /$$$$$$  /$$$$$$/$$$$   /$$$$$$         /$$$$$$  /$$    /$$ /$$$$$$   /$$$$$$   \n");
	printf("  /$$__  $$ |____  $$| $$_  $$_  $$ /$$__  $$       /$$__  $$|  $$  /$$//$$__  $$ /$$__  $$  \n");
	printf(" | $$  | $$  /$$$$$$$| $$ | $$ | $$| $$$$$$$$      | $$  | $$ |  $$/$$/| $$$$$$$$| $$  |__/  \n");
	printf(" | $$  | $$ /$$__  $$| $$ | $$ | $$| $$_____/      | $$  | $$  |  $$$/ | $$_____/| $$        \n");
	printf(" |  $$$$$$$|  $$$$$$$| $$ | $$ | $$|  $$$$$$$      |  $$$$$$/   |  $/  |  $$$$$$$| $$        \n");
	printf(" |_____  $$|_______/|__/ |__/ |__/ |_______/       |______/      |_/    |_______/|__/        \n");
	printf("   /$$ | $$                                                                                  \n");
	printf("  | $$$$$$/                                                                                  \n");
	printf("  |______/                                                                                   \n");
	printf("Joueur :%s\n",score->name);
	couleur_texte(RESET);
	
	/*libere le tableau du copr de snake*/
	
	free(Snake->corp_snake);
	
	return Snake->taille_snake;
}

void Tete_Snake (t_tableau* Jeu,t_snake* Snake)
{	
	do
	{
		couleur_texte(JAUNE);
		printf("Saisir les coordonnées x et y :\n");
		couleur_texte(RESET);
		
		scanf(" %d",&(Snake->tete_snake.x));
		
		
		scanf(" %d",&(Snake->tete_snake.y));
		
		couleur_texte(JAUNE);
		printf("Les coordonnées sont (%d/%d)\n",(Snake->tete_snake.x),(Snake->tete_snake.y));
		couleur_texte(RESET);
		
	}while(((Snake->tete_snake.x)<0 || (Snake->tete_snake.x)>(Jeu->taille)) || ((Snake->tete_snake.y)<0 || (Snake->tete_snake.y)>(Jeu->taille)));
	
}

void Objectif_Snake (t_tableau* Jeu,t_snake* Snake)
{	
	int x = 0;
	int y = 0;
	do
	{
		srand(time(NULL));
		
		(Jeu->tirage.x) = rand()%((Jeu->taille)-1)+1;
		(Jeu->tirage.y) = rand()%((Jeu->taille)-1)+1;
		
		x = (Jeu->tirage.x);
		y = (Jeu->tirage.y);
		
	}while((Jeu->tab)[x][y]==BORDURE);
}

void Key_Snake (t_snake* Snake,char*touche)
{
	t_point tampon ;
	char key;
	
	key = *touche;
	
	if(key=='z' || key=='Z' )
	{
		tampon=(Snake->tete_snake);
		(Snake->tete_snake.x)=(Snake->tete_snake.x)-1;
		(Snake->corp_snake)[0]=(Snake->tete_snake);
		(Snake->corp_snake)[1]=tampon;
	}
	else if(key=='s' || key=='S' )
	{
		tampon=(Snake->tete_snake);
		(Snake->tete_snake.x)=(Snake->tete_snake.x)+1;
		(Snake->corp_snake)[0]=(Snake->tete_snake);
		(Snake->corp_snake)[1]=tampon;
	}
	else if(key=='d' || key=='D' )
	{
		tampon=(Snake->tete_snake);
		(Snake->tete_snake.y)=(Snake->tete_snake.y)+1;
		(Snake->corp_snake)[0]=(Snake->tete_snake);
		(Snake->corp_snake)[1]=tampon;
	}
	else if(key=='q' || key=='Q' )
	{
		tampon=(Snake->tete_snake);
		(Snake->tete_snake.y)=(Snake->tete_snake.y)-1;
		(Snake->corp_snake)[0]=(Snake->tete_snake);
		(Snake->corp_snake)[1]=tampon;
	}
			
}

void Remplissage_Jeu_Snake (t_tableau* Jeu,t_snake* Snake,int lvl)
{
	int i,j;
	
	for(i=0;i<((Jeu->taille)+2);i++)
	{
		for(j=0;j<((Jeu->taille)+2);j++)
		{
			(Jeu->tab)[0][0]=BORDURE;
			if(j==0 && i!=0)
			{
				(Jeu->tab)[i][j]=BORDURE;
			}
			else if(i==0 && j!=0)
			{
				(Jeu->tab)[i][j]=BORDURE;
			}
			else if(i==((Jeu->taille)+1) && j!=((Jeu->taille)+1))
			{
				(Jeu->tab)[i][j]=BORDURE;
			}
			else if(i!=((Jeu->taille)+1) && j==((Jeu->taille)+1))
			{
				(Jeu->tab)[i][j]=BORDURE;
			}
			else
			{
				(Jeu->tab)[i][j]=FOND;
			}		
			
			(Jeu->tab)[(Jeu->taille)+1][(Jeu->taille)+1]=BORDURE;
			
		}
	}
	if(lvl>=1)
	{
		(Jeu->tab)[15][3]=BORDURE;
		(Jeu->tab)[5][3]=BORDURE;
		(Jeu->tab)[14][17]=BORDURE;
	}
	if(lvl>=2)
	{	
		for(i=6;i<10;i++)
		{
			(Jeu->tab)[i][21]=BORDURE;
		}
	}
	if(lvl>=3)
	{	
		for(i=11;i<13;i++)
		{
			(Jeu->tab)[13][i]=BORDURE;
		}
	}
	if(lvl>=4)
	{		
		for(i=19;i<25;i++)
		{
			(Jeu->tab)[18][i]=BORDURE;
		}
	}
	if(lvl>=5)
	{		
		for(i=13;i<19;i++)
		{
			(Jeu->tab)[11][i]=BORDURE;
		}
	}
	if(lvl>=6)
	{		
		for(i=1;i<8;i++)
		{
			(Jeu->tab)[10][i]=BORDURE;
		}
	}
	if(lvl>=7)
	{		
		for(i=1;i<8;i++)
		{
			(Jeu->tab)[i][6]=BORDURE;
		}
	}
	if(lvl>=8)
	{		
		for(i=1;i<8;i++)
		{
			(Jeu->tab)[i][18]=BORDURE;
		}
	}
	if(lvl>=9)
	{		
		for(i=18;i<25;i++)
		{
			(Jeu->tab)[i][12]=BORDURE;
		}
	}
	if(lvl>=10)
	{		
		for(i=13;i<20;i++)
		{
			(Jeu->tab)[i][6]=BORDURE;
		}
	}
	
}
