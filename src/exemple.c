#include <SDL/SDL.h>
#include <SDL_draw.h>
#include "td7.h"

int main () {
  unsigned int couleur ;
         /* Variable permettant de manipuler une fenetre */
  SDL_Surface* f1=NULL;

	/* Initialisation de la bibliotheque video
       Creation d'une fenetre de dimension 300x200,
       Couleurs sur 32 bits, Fond de couleur blanche
       CRTL-C possible pour tuer le programme */
  f1=newFenetreGraphique(300, 100,"EXEMPLE") ;

         /* On verifie que la fenetre est ouverte ;
         sinon, arret du programme */
  if ( f1== NULL) { printf("Erreur SDL\n"); exit(EXIT_FAILURE);  }

     /* Affichage : dessiner des objets sur la fenetre f1
	Ligne noire entre les points x=10,y=0) et (x=300,y=50)
	Attention, la ligne n'est pas encore visible a l'ecran */
  couleur=0 ;
  Draw_Line(f1,10,0,300,50,couleur);

	/* Met a jour l'ecran : la ligne apparait */
  SDL_Flip(f1) ;

	/* un getchar pour attendre, sinon le programme se termine
     		et la fenetre disparait */
  puts("Taper une touche pour continuer") ; getchar() ;
  SDL_Quit();
  return EXIT_SUCCESS;
}
