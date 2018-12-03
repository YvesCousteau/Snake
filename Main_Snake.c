#include <stdlib.h>
#include <stdio.h>

#include "Header.h"
#include "couleur_console.h"
#define couleur_texte(coul) printf("\033[%dm",coul)
#define couleur_fond(coul)	printf("\033[%dm",coul+10)

int main (void)
{
	t_tableau Jeu;
	t_snake Snake;
	t_score* score = NULL;
	
	int choix=0;
	int i = 0;
	int valeur = 0;
	char dl;
	int x=0;
	int j=0;
	
	/*Initialisation de la base du JEU*/
	
	/*Permet un affichage en plein ecran*/
	
	do
	{
		couleur_texte(VERT);
		printf("Nous avons besoin de l'application (xdotool) pour le bon fonctionnement de l'affichage du Jeu, veuillez selectioner Y si vous possédez deja l'application sinon selesctionnez N\n");
		couleur_texte(RESET);
		
		scanf(" %c",&(dl));
		
	}while((dl!='y' && dl!='Y') && (dl!='n' && dl!='N'));
	
	if(dl == 'n' || dl=='N')
	{
		system("sudo apt-get install xdotool");
	}
	system("xdotool key F11");
	
	/*Initialise le premier maillon de la liste chainée*/
	
	score = Ajout__Score_Snake  (score,valeur,x);
	
	Tableau_Jeu_Snake (&Jeu);
	couleur_texte(ROUGE);
	system("clear");
	printf("        .--.           _     _                          _     _                                        \n");
	printf("  _,.-'`_ o `;__,      /    /                           /    /                                         \n");
	printf("   _.-'` '---'  '     /___ /            __    __       /___ /     __    __   )__    __  _/_  _/_    __ \n");
	printf("                     /    /    /   /  /   ) /   )     /    /    /___) /   ) /   ) /   ) /    /    /___)\n");
	printf("                   _/____/____(___(__(___/_(___/_____/____/____(___ _/___/_/_____(___/_(_ __(_ __(___ _\n");
	printf("                                        /                                                              \n");
	printf("                                    (_ /                                                               \n");
	system("sleep 0.5");
	
	system("clear");
	printf("        .--.           _     _                          _     _                                        \n");
	printf("  _,.-'`_ o `;__,      /    /                           /    /                                         \n");
	printf("   _.-'` '---'  '     /___ /            __    __       /___ /     __    __   )__    __  _/_  _/_    __ \n");
	printf("                     /    /    /   /  /   ) /   )     /    /    /___) /   ) /   ) /   ) /    /    /___)\n");
	printf("                   _/____/____(___(__(___/_(___/_____/____/____(___ _/___/_/_____(___/_(_ __(_ __(___ _\n");
	printf("                                        /                                                              \n");
	printf("                                    (_ /                                                               \n");
	system("sleep 0.5");
	
	system("clear");
	printf("                .--.           _     _                          _     _                                        \n");
	printf("             .'`_ o `;__,      /    /                           /    /                                         \n");
	printf("           .'.'` '---'  '     /___ /            __    __       /___ /     __    __   )__    __  _/_  _/_    __ \n");
	printf("   .`-...-'.'                /    /    /   /  /   ) /   )     /    /    /___) /   ) /   ) /   ) /    /    /___)\n");
	printf("     -...-'                _/____/____(___(__(___/_(___/_____/____/____(___ _/___/_/_____(___/_(_ __(_ __(___ _\n");
	printf("                                                /                                                              \n");
	printf("                                            (_ /                                                               \n");
	system("sleep 0.5");
	
	system("clear");
	printf("                     _,.--.           _     _                          _     _                                         \n");
	printf(" --..,_           .'`__ o  `;__,      /    /                           /    /                                          \n");
	printf("    `'.'.       .'.'`  '---'`  '     /___ /            __    __       /___ /     __    __   )__    __  _/_  _/_    __  \n");
	printf("       '.`-...-'.'                  /    /    /   /  /   ) /   )     /    /    /___) /   ) /   ) /   ) /    /    /___) \n");
	printf("         `-...-'                  _/____/____(___(__(___/_(___/_____/____/____(___ _/___/_/_____(___/_(_ __(_ __(___ _ \n");
	printf("                                                       /                                                               \n");
	printf("                                                   (_ /                                                                \n");
	system("sleep 0.5");
	
	system("clear");
	printf("   --..,_                     _,.--.           _     _                          _     _                                        \n");
	printf("      `'.'.                .'`__ o  `;__.      /    /                           /    /                                         \n");
	printf("         '.'.            .'.'`  '---'`  `     /___ /            __    __       /___ /     __    __   )__    __  _/_  _/_    __ \n");
	printf("           '.`'--....--'`.'                  /    /    /   /  /   ) /   )     /    /    /___) /   ) /   ) /   ) /    /    /___)\n");
	printf("             `'--....--'`                  _/____/____(___(__(___/_(___/_____/____/____(___ _/___/_/_____(___/_(_ __(_ __(___ _\n");
	printf("                                                                /                                                              \n");
	printf("                                                            (_ /                                                               \n");
	system("sleep 0.5");
	couleur_texte(RESET);
	
	couleur_texte(VERT);
	printf("  _______                       _                  \n");
	printf(" /       )                     / |                 \n");
	printf("/$$$$$$  | ________    ______ $$ |   __   _______  \n");
	printf("$$ |__$$/ /        )  /      )$$ |  /  | /       ) \n");
	printf("$$      | $$$$$$$  | $$$$$$  |$$ |_/$$/ /$$$$$$  | \n");
	printf(" $$$$$$  |$$ |  $$ | /    $$ |$$   $$<  $$    $$ | \n");
	printf("/  |__$$ |$$ |  $$ |/$$$$$$$ |$$$$$$  | $$$$$$$$/  \n");
	printf("$$    $$/ $$ |  $$ |$$    $$ |$$ | $$  |$$       | \n");
	printf(" $$$$$$/  $$/   $$/  $$$$$$$/ $$/   $$/  $$$$$$$/  \n");
	printf("\nHugo Henrotte CPI2\n");	
	couleur_texte(RESET);
	
	do
	{
		x=1;
		
		couleur_texte(JAUNE);
		printf("\n\nVous voici dans le jeu SNAKE\n\n");
		printf("Vous pouvez choisir entre differents niveaux de difficulté ansi que la possibilité d'arreter de jouer\n\n");
		couleur_texte(RESET);
		couleur_texte(BLEU);
		printf("Menu\n");
		printf("1-Arret\n");
		printf("2-Niveau debutant\n");
		printf("3-Niveau intermediaire\n");
		printf("4-Niveau extreme\n\n");
		couleur_texte(RESET);
		do
		{
			couleur_texte(BLEU);
			printf("Saisir le choix que vous voulez faire :\n");
			scanf(" %d",&choix);
			couleur_texte(RESET);
			
		}while(choix<=0 || choix>=5);
		
		if(choix == 1)
		{
			couleur_texte(VERT);
			printf("\n\nVous avez decidez d'arreter de jouer, au revoir\n");
			couleur_texte(RESET);
			break;
		}
		
		if(choix>=2 && choix<=4)
		{
			/*Ajoute un maillon a la liste*/
			
			score = Ajout__Score_Snake  (score,valeur,x);
			
			/*Le Jeu commence */
			
			valeur = Joueur_Jeu_Snake (&Jeu,&Snake,choix);
			
			(score->storage) = valeur;
			
			j++;
			
		}
		couleur_texte(MAGENTA);
		printf("Voici les scores :\n");
		couleur_texte(RESET);
		
		if(j>=2)
		{
			trie (score);
		}
		
		/*Affiche les 5 meilleur score*/
		
		Affichage_Score_Snake (score);
		
		i++;
		
	}while(choix != 1);
	
	/*Enleve le plein ecran*/
	
	system("xdotool key F11");
	
	/*Affiche les 5 meilleur score*/
	
	Affichage_Score_Snake (score);
	
}


t_score* Ajout__Score_Snake (t_score* score,int valeur,int x)
{
	t_score* New_Score = NULL;
	int i=0;
	char name[100];

    New_Score = (t_score*) malloc(sizeof(t_score));
	
	if(x==1)
	{
		/*Saisie du Nom*/
		do
		{
			couleur_texte(CYAN);
			printf("Veulliez choisir votre nickname (30 caracteres max):\n");
			scanf(" %s",(name));
			
			do
			{
				New_Score->taille_name = i;
				i++;
				
			}while(name[i]!='\0');
					
			printf("\nNickname User : %s\n",(name));
			couleur_texte(RESET);
			
			for(i=0;i<New_Score->taille_name+1;i++)
			{
				New_Score->name[i] = name[i];
			}
			
		}while(New_Score->taille_name > 31 || New_Score->taille_name < 0); 
	}

    New_Score->storage =valeur;
	
	New_Score->suivant = NULL;
    
    New_Score->suivant=score;
    
    return New_Score;
    
    
}


void Affichage_Score_Snake (t_score* score)
{
	int i = 0;

    while(score->suivant != NULL)
    {
		couleur_texte(MAGENTA);
		printf("Score n°(%d) est celui de (%s) :%d ",i+1, (score->name),(score->storage));
		couleur_texte(RESET);
		
        score = score->suivant;
        
        printf("\n");
        
        i++;
        
        if(i==5)
        {
			break;
		}
    }

}


void trie (t_score* score)
{
	t_score* courant = NULL;
	t_score tab[100];
	int i=0;
	int j=0;
	t_score tmp;
	
	if(score == NULL)
	{
		return;
	}
	
	courant = score;
	
	//on sait que courant est != NULL
	
	while ( courant->suivant != NULL )
	{
		tab[i].storage = courant->storage;
		
		tab[i+1].storage =courant->suivant->storage ;
		
		
		tab[i].taille_name = courant->taille_name;
		
		for(j=0;j<(tab[i].taille_name)+1;j++)
		{
			 tab[i].name[j] = courant-> name[j];
		}
		
		tab[i+1].taille_name = courant->suivant->taille_name;
		
		for(j=0;j<(tab[i+1].taille_name)+1;j++)
		{
			tab[i+1].name[j] = courant-> suivant-> name[j];
		}
		
		i++;
		courant = courant->suivant ;
	}	

	for(j=0;j<i && j<7;j++)
	{
		
		if(tab[j].storage <= tab[j+1].storage)
		{
			tmp.storage = tab[j+1].storage;
			
			tab[j+1].storage = tab[j].storage;
				
			tab[j].storage = tmp.storage;
			
			
			tmp.taille_name = tab[j+1].taille_name;
			
			for(i=0;i<(tab[j+1].taille_name)+1;i++)
			{
				
				tmp.name[i] = tab[j+1].name[i];
				
			}
			
			tab[j+1].taille_name = tab[j].taille_name;
			
			for(i=0;i<(tab[j+1].taille_name)+1;i++)
			{
				tab[j+1].name[i] = tab[j].name[i];
			}
						
			tab[j].taille_name = tmp.taille_name;
			
			for(i=0;i<(tab[j].taille_name)+1;i++)
			{
				
				tab[j].name[i] = tmp.name[i];
			}
		}
		else
		{
			
		}
	}
	
	courant = score;
	i=0;
	while ( courant->suivant != NULL )
	{
		courant->storage = tab [i].storage;
		
		courant->suivant->storage = tab[i+1].storage;

		courant->taille_name = tab[i].taille_name;
		
		
		for(j=0;j<courant->suivant->taille_name+1;j++)
		{
			 courant-> name[j] = tab[i].name[j];
		}
		
		courant->suivant->taille_name = tab[i+1].taille_name;
		
		for(j=0;j<courant->taille_name+1;j++)
		{
			 courant->suivant ->name[j] = tab[i+1].name[j];
		}
		
		i++;
		courant = courant->suivant ;
	}	
	
	
	return;
	
}

void liberation (t_tableau* Jeu,t_snake* Snake)
{
	
	
}



