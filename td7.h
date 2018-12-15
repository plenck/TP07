
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
SDL_Surface *newFenetreGraphique(int x, int y);
void SDL_pause();
#endif
