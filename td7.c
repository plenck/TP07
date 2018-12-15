#include "td7.h"
#include <stdio.h>
#include <SDL/SDL.h>

int main(){

  SDL_Surface* f1=NULL;

  f1 = newFenetreGraphique(1920, 1080);

  int n;
  td7_pt P1,P4;
  P1.x=460;
  P1.y=1020;
  P4.x=1460;
  P4.y=1020;

  printf("entrez l'ordre n de sierpinski\n");
  scanf("%d", &n);

  printf("ordre :  %d\n", n);
  sierpinski(f1,P1,P4,n);

  SDL_Flip(f1);
  printf("sdl actualisée\n");
  SDL_pause();
  SDL_Quit();
  printf("=====SORTIE DU PROGRAMME=====\n\n");
  return EXIT_SUCCESS;
}
