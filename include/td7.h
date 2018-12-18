
#ifndef _FCT_H
#define _FCT_H

#include <SDL/SDL.h>

struct point{
  int x;
  int y;
};

typedef struct point td7_pt;

double pgcd(int a, int b);
void sierpinski(SDL_Surface *f, td7_pt P1, td7_pt P4, int n);
SDL_Surface *newFenetreGraphique(int x, int y, const char* title);
void SDL_pause();
void tapis(SDL_Surface *screen, int cote, int ordre);
void genTapis(SDL_Surface *screen, int cote, int ordre,td7_pt origin, Uint32 color);
#endif
