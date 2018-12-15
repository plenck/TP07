
#include <SDL/SDL.h>
#include "td7.h"
#include <SDL_draw.h>


//----------------------------------------------------------------------------
//  FONCTION : pgcd
//----------------------------------------------------------------------------
//  DESCRIPTION : calcul le plus grand diviseur commum entre deux double
//----------------------------------------------------------------------------
//  PARAMETERS :
//    int a;
//    int b;
//----------------------------------------------------------------------------
//  RETURN : double pgcd
//----------------------------------------------------------------------------
double pgcd(int a,int b){
  if(b==0) return a;
  else return pgcd(b,a%b);
}

//----------------------------------------------------------------------------
//  FONCTION : sierpinski
//----------------------------------------------------------------------------
//  DESCRIPTION : fonction recursive, elle attribue la position des nouveaux
//                points, si l'ordre n est atteint alors les segments sont
//                chargés dans la SDL. Necessite l'extension SDL_draw
//----------------------------------------------------------------------------
//  PARAMETERS :
//    -int n;  ordre de la fonction à partir du quel on arrete la recursivité
//    -td7_pt p1; contient les coordonées x et y du point p1.x p2.y
//    -td7_pt p2;
//----------------------------------------------------------------------------
//  RETURN : void
//----------------------------------------------------------------------------
void sierpinski(SDL_Surface *f, td7_pt P1, td7_pt P4, int n){
  td7_pt P2,P3;

  if (n==0) {
    Draw_Line(f, P1.x, P1.y, P4.x, P4.y, 0xFFFF);
    return;
  }

  else {
    P2.x = P1.x + (P4.x - P1.x)/4 + 1.75*(P4.y - P1.y)/4;
    P2.y = P1.y + (P4.y - P1.y)/4 - 1.75*(P4.x - P1.x)/4;
    P3.x = P4.x - (P4.x - P1.x)/4 + 1.75*(P4.y - P1.y)/4;
    P3.y = P4.y - (P4.y - P1.y)/4 - 1.75*(P4.x - P1.x)/4;
    sierpinski(P2,P1,n-1,f);
    sierpinski(P2,P3,n-1,f);
    sierpinski(P4,P3,n-1,f);
  }
}
/*
----------------------------------------------------------------------------
FONCTION : tapis
----------------------------------------------------------------------------
DESCRIPTION : construit la fractable "tapis de Sierpinski" à l'aide de

----------------------------------------------------------------------------
PARAMETERS :
  -int largeur;
  -int hauteur;
  -SDL_Surface;
  -unsigned int couleur;
----------------------------------------------------------------------------
RETURN : void
----------------------------------------------------------------------------
*/
void tapis(SDL_Surface screen, int hauteur, int largeur){
  SDL_FillRect(screen,NULL, SDL_MapRGB(32,255,255,255)); // Set background color

}
/*
----------------------------------------------------------------------------
FONCTION : newFenetreGraphique
----------------------------------------------------------------------------
DESCRIPTION : ouvre une fenètre de la dimension voulue, couleur 32 bits,
              chargement dans la mémoire du GPU
----------------------------------------------------------------------------
PARAMETERS :
  -int x ; regle la dimension de l'idex des ordonnées
  -int y ; regle la dimension de l'index des abscices

----------------------------------------------------------------------------
RETURN :  SDL_Surface *screen
----------------------------------------------------------------------------
*/
SDL_Surface *newFenetreGraphique(int x, int y){
  if (SDL_Init(SDL_INIT_VIDEO)==-1){
    fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_Surface *screen = NULL;
  screen = SDL_SetVideoMode(x,y,32,SDL_HWSURFACE | SDL_RESIZABLE);

  if (screen == NULL)
  {
    fprintf(stderr, "Erreur lors du chargement du mode video : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_WM_SetCaption("TD07 QUI MARCHE BIEN, OU PAS.",NULL);
  SDL_Flip();
  return screen;
}

/*
----------------------------------------------------------------------------
FONCTION : pause
----------------------------------------------------------------------------
DESCRIPTION : mets la sdl en attente
----------------------------------------------------------------------------
PARAMETERS : none

----------------------------------------------------------------------------
RETURN :  void
----------------------------------------------------------------------------
*/
void SDL_pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
          continuer = 0;
      }
    }
}
