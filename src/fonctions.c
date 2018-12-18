
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
    sierpinski(f,P2,P1,n-1);
    sierpinski(f,P2,P3,n-1);
    sierpinski(f,P4,P3,n-1);
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
void tapis(SDL_Surface *screen, int cote, int ordre){
  SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,255,255,255)); // Set background color to white
  td7_pt origin;
  origin.x=0;
  origin.y=0;
  genTapis(screen,cote,ordre,origin,SDL_MapRGB(screen->format,0,0,0));
}
/*
----------------------------------------------------------------------------
FONCTION : genTapis
----------------------------------------------------------------------------
DESCRIPTION : genération des carrés par appel récurssif
----------------------------------------------------------------------------
PARAMETERS :
  -SDL_Surface screen
  -int ordre
  -Uint32 color
  -int cote
----------------------------------------------------------------------------
RETURN :void
----------------------------------------------------------------------------
*/
void genTapis(SDL_Surface *screen, int cote, int n,td7_pt origin, Uint32 color){
  if(n==0){
    //do nothing
    return;
  }
  else{
    int a = cote/3;

    Draw_FillRect(screen,origin.x+a,origin.y+a,a,a,color);
    td7_pt offset;
    offset = origin;

    genTapis(screen,a,n-1, origin, color);
    offset.x = origin.x + 1*a;
    offset.y = origin.y + 0*a;
    genTapis(screen,a,n-1, offset, color);
    offset.x = origin.x + 2*a;
    offset.y = origin.y + 0*a;
    genTapis(screen,a,n-1, offset, color);
    offset.x = origin.x + 0*a;
    offset.y = origin.y + 1*a;
    genTapis(screen,a,n-1, offset, color);
    offset.x = origin.x + 2*a;
    offset.y = origin.y + 1*a;
    genTapis(screen,a,n-1, offset, color);
    offset.x = origin.x + 0*a;
    offset.y = origin.y + 2*a;
    genTapis(screen,a,n-1, offset, color);
    offset.x = origin.x + 1*a;
    offset.y = origin.y + 2*a;
    genTapis(screen,a,n-1, offset, color);
    offset.x = origin.x + 2*a;
    offset.y = origin.y + 2*a;
    genTapis(screen,a,n-1, offset, color);
  }
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
SDL_Surface *newFenetreGraphique(int x, int y, const char *title){
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
  SDL_WM_SetCaption(title,NULL);
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
